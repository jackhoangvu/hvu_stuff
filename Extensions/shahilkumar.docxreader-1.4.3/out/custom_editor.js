"use strict";
var __createBinding = (this && this.__createBinding) || (Object.create ? (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    var desc = Object.getOwnPropertyDescriptor(m, k);
    if (!desc || ("get" in desc ? !m.__esModule : desc.writable || desc.configurable)) {
      desc = { enumerable: true, get: function() { return m[k]; } };
    }
    Object.defineProperty(o, k2, desc);
}) : (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    o[k2] = m[k];
}));
var __setModuleDefault = (this && this.__setModuleDefault) || (Object.create ? (function(o, v) {
    Object.defineProperty(o, "default", { enumerable: true, value: v });
}) : function(o, v) {
    o["default"] = v;
});
var __importStar = (this && this.__importStar) || (function () {
    var ownKeys = function(o) {
        ownKeys = Object.getOwnPropertyNames || function (o) {
            var ar = [];
            for (var k in o) if (Object.prototype.hasOwnProperty.call(o, k)) ar[ar.length] = k;
            return ar;
        };
        return ownKeys(o);
    };
    return function (mod) {
        if (mod && mod.__esModule) return mod;
        var result = {};
        if (mod != null) for (var k = ownKeys(mod), i = 0; i < k.length; i++) if (k[i] !== "default") __createBinding(result, mod, k[i]);
        __setModuleDefault(result, mod);
        return result;
    };
})();
Object.defineProperty(exports, "__esModule", { value: true });
exports.DocxEditorProvider = void 0;
const vscode = __importStar(require("vscode"));
const render_1 = require("./render");
const docx_handler_1 = require("./docx_handler");
class DocxEditorProvider {
    _onDidChangeCustomDocument = new vscode.EventEmitter();
    onDidChangeCustomDocument = this._onDidChangeCustomDocument.event;
    activeWebviewPanels = new Map();
    panelsByPath = new Map();
    panelToUri = new Map(); // reverse lookup
    // Per-document state — keyed by URI string so each file has independent zoom/outline/toolbar
    documentStates = new Map();
    getOrCreateState(uriString) {
        if (!this.documentStates.has(uriString)) {
            const config = vscode.workspace.getConfiguration('docxreader');
            this.documentStates.set(uriString, {
                zoom: config.get('zoomLevel', 1.0),
                outlineVisible: config.get('showOutline', true),
                currentTheme: config.get('theme', 'auto'),
                toolbarVisible: false
            });
        }
        return this.documentStates.get(uriString);
    }
    getStateForPanel(panel) {
        const uri = this.panelToUri.get(panel);
        return uri ? this.documentStates.get(uri) : undefined;
    }
    getActiveState() {
        const panel = this.getActiveWebviewPanel();
        return panel ? this.getStateForPanel(panel) : undefined;
    }
    async resolveCustomEditor(document, webviewPanel, _token) {
        // Store the webview panel reference
        const uriString = document.uri.toString();
        this.activeWebviewPanels.set(uriString, webviewPanel);
        this.panelToUri.set(webviewPanel, uriString);
        // Initialize fresh per-document state for this URI
        this.getOrCreateState(uriString);
        // Track panels by filesystem path to detect diff views
        const fsPath = document.uri.fsPath;
        let panels = this.panelsByPath.get(fsPath) || [];
        panels.push(webviewPanel);
        this.panelsByPath.set(fsPath, panels);
        // Configure webview options
        webviewPanel.webview.options = {
            enableScripts: true,
            localResourceRoots: [vscode.Uri.file(require('path').dirname(__dirname))]
        };
        // Set up message handling
        webviewPanel.webview.onDidReceiveMessage(message => this.handleWebviewMessage(message, webviewPanel), undefined, []);
        // Clean up on dispose
        webviewPanel.onDidDispose(() => {
            this.activeWebviewPanels.delete(uriString);
            this.panelToUri.delete(webviewPanel);
            this.documentStates.delete(uriString);
            const panels = this.panelsByPath.get(fsPath) || [];
            const idx = panels.indexOf(webviewPanel);
            if (idx !== -1) {
                panels.splice(idx, 1);
                if (panels.length === 0) {
                    this.panelsByPath.delete(fsPath);
                }
                else {
                    this.panelsByPath.set(fsPath, panels);
                }
            }
        });
        // Render the initial content — pass per-document state so the renderer
        // uses the correct state for this specific file
        const state = this.getOrCreateState(uriString);
        await render_1.DocumentRenderer.renderDocument(document.uri, webviewPanel, {
            zoom: state.zoom,
            outlineVisible: state.outlineVisible,
            toolbarVisible: state.toolbarVisible
        });
        // Check if we need to show diffs (more than 1 panel for same file)
        if (panels.length >= 2) {
            this.triggerDiffUpdate(fsPath);
        }
    }
    async handleWebviewMessage(message, webviewPanel) {
        const uri = this.panelToUri.get(webviewPanel);
        const state = uri ? this.documentStates.get(uri) : undefined;
        switch (message.command) {
            case 'scroll':
                this.syncScroll(webviewPanel, message.scrollPercent);
                break;
            case 'zoomChanged':
                if (state) {
                    state.zoom = message.zoom;
                }
                render_1.DocumentRenderer.updateZoom(message.zoom);
                // Notify extension about zoom change for status bar update
                vscode.commands.executeCommand('docxreader.updateStatusBar');
                break;
            case 'outlineToggled':
                if (state) {
                    state.outlineVisible = message.visible;
                }
                render_1.DocumentRenderer.toggleOutline();
                break;
            case 'themeChanged':
                if (state) {
                    state.currentTheme = message.theme;
                }
                render_1.DocumentRenderer.updateTheme(message.theme);
                break;
            case 'toolbarToggled':
                if (state) {
                    state.toolbarVisible = message.visible;
                }
                render_1.DocumentRenderer.toggleToolbar();
                break;
            case 'error':
                vscode.window.showErrorMessage(`Document Viewer Error: ${message.message}`);
                break;
            case 'info':
                vscode.window.showInformationMessage(message.message);
                break;
        }
    }
    syncScroll(sourcePanel, scrollPercent) {
        let targetPath;
        for (const [path, panels] of this.panelsByPath) {
            if (panels.includes(sourcePanel)) {
                targetPath = path;
                break;
            }
        }
        if (targetPath) {
            const panels = this.panelsByPath.get(targetPath);
            if (panels) {
                panels.forEach(p => {
                    if (p !== sourcePanel) {
                        p.webview.postMessage({ command: 'syncScroll', scrollPercent });
                    }
                });
            }
        }
    }
    async triggerDiffUpdate(fsPath) {
        const panels = this.panelsByPath.get(fsPath);
        if (!panels || panels.length < 2)
            return;
        const panelUris = [];
        const orderedPanels = [];
        for (const p of panels) {
            for (const [uriStr, activeP] of this.activeWebviewPanels) {
                if (activeP === p) {
                    panelUris.push(vscode.Uri.parse(uriStr));
                    orderedPanels.push(p);
                    break;
                }
            }
        }
        if (panelUris.length < 2)
            return;
        try {
            const html1 = await docx_handler_1.DocxHandler.renderDocx(panelUris[0]);
            const html2 = await docx_handler_1.DocxHandler.renderDocx(panelUris[1]);
            const paras1 = this.extractParagraphText(html1);
            const paras2 = this.extractParagraphText(html2);
            const diff = this.diffArrays(paras1, paras2);
            const p1Removals = [];
            const p2Additions = [];
            let idx1 = 0;
            let idx2 = 0;
            diff.forEach(part => {
                if (part.added) {
                    for (let i = 0; i < part.count; i++)
                        p2Additions.push(idx2 + i);
                    idx2 += part.count;
                }
                else if (part.removed) {
                    for (let i = 0; i < part.count; i++)
                        p1Removals.push(idx1 + i);
                    idx1 += part.count;
                }
                else {
                    idx1 += part.count;
                    idx2 += part.count;
                }
            });
            orderedPanels[0].webview.postMessage({ command: 'highlight', diffs: { removed: p1Removals, added: [] } });
            orderedPanels[1].webview.postMessage({ command: 'highlight', diffs: { removed: [], added: p2Additions } });
        }
        catch (error) {
            console.error('Error computing diff:', error);
        }
    }
    extractParagraphText(html) {
        const matches = html.matchAll(/<(p|h[1-6]|li|div|blockquote)[^>]*>([\s\S]*?)<\/\1>/gi);
        const results = [];
        for (const match of matches) {
            results.push(match[2].replace(/<[^>]+>/g, '').trim());
        }
        return results;
    }
    diffArrays(arr1, arr2) {
        const n = arr1.length;
        const m = arr2.length;
        const matrix = Array(n + 1).fill(0).map(() => Array(m + 1).fill(0));
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < m; j++) {
                if (arr1[i] === arr2[j]) {
                    matrix[i + 1][j + 1] = matrix[i][j] + 1;
                }
                else {
                    matrix[i + 1][j + 1] = Math.max(matrix[i + 1][j], matrix[i][j + 1]);
                }
            }
        }
        const parts = [];
        let i = n;
        let j = m;
        const stack = [];
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && arr1[i - 1] === arr2[j - 1]) {
                stack.push({ count: 1 });
                i--;
                j--;
            }
            else if (j > 0 && (i === 0 || matrix[i][j - 1] >= matrix[i - 1][j])) {
                stack.push({ count: 1, added: true });
                j--;
            }
            else {
                stack.push({ count: 1, removed: true });
                i--;
            }
        }
        stack.reverse();
        if (stack.length > 0) {
            let current = stack[0];
            for (let k = 1; k < stack.length; k++) {
                const next = stack[k];
                if ((current.added === next.added) && (current.removed === next.removed)) {
                    current.count += next.count;
                }
                else {
                    parts.push(current);
                    current = next;
                }
            }
            parts.push(current);
        }
        return parts;
    }
    async handleZoomIn(webviewPanel) {
        const panel = webviewPanel || this.getActiveWebviewPanel();
        const state = panel ? this.getStateForPanel(panel) : undefined;
        if (state && state.zoom < 3.0) {
            state.zoom = Math.min(3.0, parseFloat((state.zoom + 0.1).toFixed(1)));
            await this.sendZoomUpdate(panel, state.zoom);
            vscode.commands.executeCommand('docxreader.updateStatusBar');
        }
    }
    async handleZoomOut(webviewPanel) {
        const panel = webviewPanel || this.getActiveWebviewPanel();
        const state = panel ? this.getStateForPanel(panel) : undefined;
        if (state && state.zoom > 0.5) {
            state.zoom = Math.max(0.5, parseFloat((state.zoom - 0.1).toFixed(1)));
            await this.sendZoomUpdate(panel, state.zoom);
            vscode.commands.executeCommand('docxreader.updateStatusBar');
        }
    }
    async handleResetZoom(webviewPanel) {
        const panel = webviewPanel || this.getActiveWebviewPanel();
        const state = panel ? this.getStateForPanel(panel) : undefined;
        if (state) {
            state.zoom = 1.0;
            await this.sendZoomUpdate(panel, state.zoom);
            vscode.commands.executeCommand('docxreader.updateStatusBar');
        }
    }
    async handleToggleOutline(webviewPanel) {
        const panel = webviewPanel || this.getActiveWebviewPanel();
        const state = panel ? this.getStateForPanel(panel) : undefined;
        if (state) {
            state.outlineVisible = !state.outlineVisible;
            await this.sendOutlineUpdate(panel, state.outlineVisible);
        }
    }
    async handleToggleTheme(webviewPanel) {
        const panel = webviewPanel || this.getActiveWebviewPanel();
        const state = panel ? this.getStateForPanel(panel) : undefined;
        if (state) {
            // Cycle through themes: auto -> light -> dark -> auto
            if (state.currentTheme === 'auto') {
                state.currentTheme = 'light';
            }
            else if (state.currentTheme === 'light') {
                state.currentTheme = 'dark';
            }
            else {
                state.currentTheme = 'auto';
            }
            await this.sendThemeUpdate(panel, state.currentTheme);
        }
    }
    async handleToggleToolbar(webviewPanel) {
        const panel = webviewPanel || this.getActiveWebviewPanel();
        const state = panel ? this.getStateForPanel(panel) : undefined;
        if (state) {
            state.toolbarVisible = !state.toolbarVisible;
            await this.sendToolbarUpdate(panel, state.toolbarVisible);
        }
    }
    async sendZoomUpdate(panel, zoom) {
        if (panel) {
            await panel.webview.postMessage({ command: 'updateZoom', zoom });
            render_1.DocumentRenderer.updateZoom(zoom);
        }
    }
    async sendOutlineUpdate(panel, visible) {
        if (panel) {
            await panel.webview.postMessage({ command: 'toggleOutline', visible });
            render_1.DocumentRenderer.toggleOutline();
        }
    }
    async sendThemeUpdate(panel, theme) {
        if (panel) {
            await panel.webview.postMessage({ command: 'updateTheme', theme });
            render_1.DocumentRenderer.updateTheme(theme);
        }
    }
    async sendToolbarUpdate(panel, visible) {
        if (panel) {
            await panel.webview.postMessage({ command: 'toggleToolbar', visible });
            render_1.DocumentRenderer.toggleToolbar();
        }
    }
    getActiveWebviewPanel() {
        // Return the first active panel (in a real scenario, you might want to track the focused one)
        const panels = Array.from(this.activeWebviewPanels.values());
        return panels.length > 0 ? panels[0] : undefined;
    }
    getCurrentZoom() {
        return this.getActiveState()?.zoom ?? 1.0;
    }
    isOutlineVisible() {
        return this.getActiveState()?.outlineVisible ?? true;
    }
    isToolbarVisible() {
        return this.getActiveState()?.toolbarVisible ?? false;
    }
    hasActiveWebviewPanels() {
        return this.activeWebviewPanels.size > 0;
    }
    saveCustomDocument(document, cancellation) {
        // Document viewing is read-only, no save needed
        return Promise.resolve();
    }
    saveCustomDocumentAs(document, destination, cancellation) {
        // Could implement export functionality here in the future
        throw new Error('Save As not supported for document viewing');
    }
    revertCustomDocument(document, cancellation) {
        // No changes to revert for read-only viewer
        return Promise.resolve();
    }
    backupCustomDocument(document, context, cancellation) {
        // No backup needed for read-only viewer
        return Promise.resolve({
            id: context.destination.toString(),
            delete: async () => { }
        });
    }
    openCustomDocument(uri, openContext, token) {
        return {
            uri,
            dispose() { }
        };
    }
}
exports.DocxEditorProvider = DocxEditorProvider;
//# sourceMappingURL=custom_editor.js.map