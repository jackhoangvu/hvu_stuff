"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.activate = activate;
exports.deactivate = deactivate;
const vscode = require("vscode");
const formatter_1 = require("./formatter");
function activate(context) {
    const disposable = vscode.commands.registerCommand('noBlankFormat.format', async () => {
        const editor = vscode.window.activeTextEditor;
        if (!editor) {
            vscode.window.showWarningMessage('No Blank Format: no active editor.');
            return;
        }
        const selection = editor.selection;
        if (selection.isEmpty) {
            vscode.window.showWarningMessage('No Blank Format: select some code first.');
            return;
        }
        const config = vscode.workspace.getConfiguration('noBlankFormat');
        const indentSize = config.get('indentSize', 2);
        const originalText = editor.document.getText(selection);
        let formatted;
        try {
            formatted = (0, formatter_1.formatCompact)(originalText, indentSize);
        }
        catch (err) {
            const message = err instanceof Error ? err.message : String(err);
            vscode.window.showErrorMessage(`No Blank Format: failed to format selection — ${message}`);
            return;
        }
        await editor.edit((editBuilder) => {
            editBuilder.replace(selection, formatted);
        });
    });
    context.subscriptions.push(disposable);
}
function deactivate() {
    // No cleanup needed: the command registration is disposed via
    // context.subscriptions automatically on extension deactivation.
}
//# sourceMappingURL=extension.js.map