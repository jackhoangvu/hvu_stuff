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
exports.activate = activate;
exports.deactivate = deactivate;
const vscode = __importStar(require("vscode"));
const custom_editor_1 = require("./custom_editor");
function activate(context) {
    // Create the custom editor provider instance
    const editorProvider = new custom_editor_1.DocxEditorProvider();
    // Register the custom editor provider
    context.subscriptions.push(vscode.window.registerCustomEditorProvider('docxreader.docxEditor', editorProvider, {
        webviewOptions: {
            retainContextWhenHidden: true
        },
        supportsMultipleEditorsPerDocument: false
    }));
    // Register configuration command
    context.subscriptions.push(vscode.commands.registerCommand('docxreader.openConfig', () => {
        vscode.commands.executeCommand('workbench.action.openSettings', '@ext:shahilkumar.docxreader');
    }));
    // Register zoom commands
    context.subscriptions.push(vscode.commands.registerCommand('docxreader.zoomIn', () => {
        editorProvider.handleZoomIn();
    }));
    context.subscriptions.push(vscode.commands.registerCommand('docxreader.zoomOut', () => {
        editorProvider.handleZoomOut();
    }));
    context.subscriptions.push(vscode.commands.registerCommand('docxreader.resetZoom', () => {
        editorProvider.handleResetZoom();
    }));
    context.subscriptions.push(vscode.commands.registerCommand('docxreader.toggleOutline', () => {
        editorProvider.handleToggleOutline();
    }));
    context.subscriptions.push(vscode.commands.registerCommand('docxreader.toggleTheme', () => {
        editorProvider.handleToggleTheme();
    }));
    context.subscriptions.push(vscode.commands.registerCommand('docxreader.toggleToolbar', () => {
        editorProvider.handleToggleToolbar();
    }));
    // Register status bar update command
    context.subscriptions.push(vscode.commands.registerCommand('docxreader.updateStatusBar', () => {
        updateStatusBar();
    }));
    // Register status bar item to show current zoom level
    const statusBarItem = vscode.window.createStatusBarItem(vscode.StatusBarAlignment.Right, 100);
    statusBarItem.command = 'docxreader.resetZoom';
    statusBarItem.tooltip = 'Click to reset zoom';
    // Function to update status bar
    function updateStatusBar() {
        const activeEditor = vscode.window.activeTextEditor;
        const isDocxEditor = activeEditor &&
            (activeEditor.document.uri.scheme === 'vscode-webview' ||
                activeEditor.document.fileName.endsWith('.docx') ||
                activeEditor.document.fileName.endsWith('.odt'));
        if (isDocxEditor || editorProvider.hasActiveWebviewPanels()) {
            const zoom = Math.round(editorProvider.getCurrentZoom() * 100);
            statusBarItem.text = `$(zoom-in) ${zoom}%`;
            statusBarItem.show();
        }
        else {
            statusBarItem.hide();
        }
    }
    // Update status bar when active editor changes
    context.subscriptions.push(vscode.window.onDidChangeActiveTextEditor(() => {
        updateStatusBar();
    }));
    // Update status bar when webview panel becomes active
    context.subscriptions.push(vscode.window.onDidChangeActiveColorTheme(() => {
        updateStatusBar();
    }));
    context.subscriptions.push(statusBarItem);
    // Show welcome message for first-time users
    const hasShownWelcome = context.globalState.get('hasShownWelcome', false);
    if (!hasShownWelcome) {
        vscode.window.showInformationMessage('Welcome to Enhanced Docx Viewer! 🎉 Use Ctrl+Plus/Minus to zoom, Ctrl+F to search, and click the outline button to navigate.', 'Learn More', 'Don\'t Show Again').then(selection => {
            if (selection === 'Learn More') {
                vscode.commands.executeCommand('docxreader.openConfig');
            }
            else if (selection === 'Don\'t Show Again') {
                context.globalState.update('hasShownWelcome', true);
            }
        });
    }
    console.log('Enhanced Docx Viewer activated successfully!');
}
function deactivate() {
    console.log('Enhanced Docx Viewer deactivated');
}
//# sourceMappingURL=extension.js.map