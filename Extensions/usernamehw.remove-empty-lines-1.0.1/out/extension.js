"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.deactivate = exports.activate = void 0;
const vscode_1 = require("vscode");
let documentSaveDisposable;
const onSaveReasonDefaults = {
    manual: true,
    afterDelay: false,
    focusOut: false,
};
/**
 * Get extension configuration (depending on scope (active editor document language)).
 */
function getExtensionConfig(document) {
    let allowedNumberOfEmptyLines = 0;
    const runOnSave = false;
    const config = vscode_1.workspace.getConfiguration(undefined, document).get("remove-empty-lines" /* Constants.ExtensionConfigPrefix */);
    if (!config) {
        return {
            runOnSave,
            allowedNumberOfEmptyLines,
            onSaveReason: onSaveReasonDefaults,
        };
    }
    if (config.allowedNumberOfEmptyLines >= 0 && config.allowedNumberOfEmptyLines <= 500) {
        allowedNumberOfEmptyLines = config.allowedNumberOfEmptyLines;
    }
    return {
        allowedNumberOfEmptyLines,
        runOnSave: config.runOnSave,
        onSaveReason: config.onSaveReason,
    };
}
function configWasUpdated() {
    updateRunOnSaveListener();
}
function removeEmptyLines(editor, inSelection, keybindingsPassedAllowedNumberOfEmptyLines) {
    const $config = getExtensionConfig(editor.document);
    if (typeof keybindingsPassedAllowedNumberOfEmptyLines === 'number') {
        $config.allowedNumberOfEmptyLines = keybindingsPassedAllowedNumberOfEmptyLines;
    }
    const { document } = editor;
    if (inSelection) {
        const { selections } = editor;
        if (selections.length === 1 && selections[0].isEmpty) {
            // remove all adjacent empty lines up & down of the cursor
            const activeLine = document.lineAt(selections[0].start.line);
            if (!activeLine.isEmptyOrWhitespace) {
                return;
            }
            else {
                const closestUp = findUpClosestNonEmptyLine(selections[0].start.line, document);
                const closestDown = findDownClosestNonEmptyLine(selections[0].start.line, document);
                removeEmptyLinesInRange(editor, document, [[closestUp, closestDown]], $config.allowedNumberOfEmptyLines);
            }
        }
        else {
            const ranges = [];
            for (const selection of selections) {
                ranges.push([selection.start.line, selection.end.line]);
            }
            removeEmptyLinesInRange(editor, document, ranges, $config.allowedNumberOfEmptyLines);
        }
    }
    else {
        removeEmptyLinesInRange(editor, document, [[0, document.lineCount - 1]], $config.allowedNumberOfEmptyLines);
    }
}
function removeEmptyLinesInRange(editorOrUri, document, ranges, allowedNumberOfEmptyLines) {
    const rangesToDelete = [];
    for (const range of ranges) {
        let numberOfConsequtiveEmptyLines = 0;
        for (let i = range[0]; i <= range[1]; i++) {
            const line = document.lineAt(i);
            if (line.isEmptyOrWhitespace) {
                numberOfConsequtiveEmptyLines++;
                if (numberOfConsequtiveEmptyLines > allowedNumberOfEmptyLines) {
                    rangesToDelete.push(line.rangeIncludingLineBreak);
                }
            }
            else {
                numberOfConsequtiveEmptyLines = 0;
            }
        }
    }
    if (isEditor(editorOrUri)) {
        editorOrUri.edit(edit => {
            for (const range of rangesToDelete) {
                edit.delete(range);
            }
        });
    }
    else {
        // When editor is not visible - it seems not possible to find it. But uri can be used with WorkspaceEdit.
        const workspaceEdit = new vscode_1.WorkspaceEdit();
        for (const range of rangesToDelete) {
            workspaceEdit.delete(document.uri, range);
        }
        vscode_1.workspace.applyEdit(workspaceEdit);
    }
}
/**
 * Assume argument is of TextEditor type if it has the `document` property.
 */
function isEditor(arg) {
    return Boolean(arg.document);
}
function findUpClosestNonEmptyLine(ln, document) {
    for (let i = ln; i > 0; i--) {
        const lineAt = document.lineAt(i);
        if (lineAt.isEmptyOrWhitespace) {
            continue;
        }
        return i;
    }
    return 0;
}
function findDownClosestNonEmptyLine(ln, document) {
    for (let i = ln; i < document.lineCount; i++) {
        const lineAt = document.lineAt(i);
        if (lineAt.isEmptyOrWhitespace) {
            continue;
        }
        return i;
    }
    return document.lineCount - 1;
}
function updateRunOnSaveListener() {
    documentSaveDisposable?.dispose();
    documentSaveDisposable = vscode_1.workspace.onWillSaveTextDocument(saveEvent => {
        const config = getExtensionConfig(saveEvent.document);
        if (!config.runOnSave) {
            return;
        }
        if (!isOnSaveReasonEnabled(saveEvent.reason, getExtensionConfig().onSaveReason)) {
            return;
        }
        if (config.onSaveReason.focusOut && saveEvent.reason === vscode_1.TextDocumentSaveReason.FocusOut ||
            config.onSaveReason.afterDelay && saveEvent.reason === vscode_1.TextDocumentSaveReason.AfterDelay) {
            removeEmptyLinesInRange(saveEvent.document.uri, saveEvent.document, [[0, saveEvent.document.lineCount - 1]], config.allowedNumberOfEmptyLines);
            return;
        }
        const editor = findEditorByDocument(saveEvent.document);
        if (!editor) {
            return;
        }
        removeEmptyLines(editor, false);
    });
}
function isOnSaveReasonEnabled(reason, configReason) {
    if (reason === vscode_1.TextDocumentSaveReason.Manual && configReason.manual ||
        reason === vscode_1.TextDocumentSaveReason.AfterDelay && configReason.afterDelay ||
        reason === vscode_1.TextDocumentSaveReason.FocusOut && configReason.focusOut) {
        return true;
    }
    return false;
}
function findEditorByDocument(document) {
    for (const editor of vscode_1.window.visibleTextEditors) {
        if (editor.document === document) {
            return editor;
        }
    }
    return undefined;
}
function activate(context) {
    configWasUpdated();
    context.subscriptions.push(vscode_1.commands.registerTextEditorCommand("remove-empty-lines.inDocument" /* CommandId.inDocument */, (editor, edit, keybinding) => {
        removeEmptyLines(editor, false, keybinding);
    }));
    context.subscriptions.push(vscode_1.commands.registerTextEditorCommand("remove-empty-lines.inSelection" /* CommandId.inSelection */, (editor, edit, keybinding) => {
        removeEmptyLines(editor, true, keybinding);
    }));
    context.subscriptions.push(vscode_1.workspace.onDidChangeConfiguration(e => {
        if (!e.affectsConfiguration("remove-empty-lines" /* Constants.ExtensionConfigPrefix */)) {
            return;
        }
        configWasUpdated();
    }));
}
exports.activate = activate;
function deactivate() { }
exports.deactivate = deactivate;
//# sourceMappingURL=extension.js.map