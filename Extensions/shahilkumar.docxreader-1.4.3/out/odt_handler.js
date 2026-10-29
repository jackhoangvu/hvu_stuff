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
exports.OdtHandler = void 0;
const vscode = __importStar(require("vscode"));
const os = __importStar(require("os"));
const path = __importStar(require("path"));
const fs = __importStar(require("fs/promises"));
const odt2html = require('odt2html');
class OdtHandler {
    static async renderOdt(uri) {
        try {
            // odt2html requires a file path, so we might need to write to temp if it's not a file scheme
            let filePath = uri.fsPath;
            let tempFile;
            if (uri.scheme !== 'file') {
                const fileData = await vscode.workspace.fs.readFile(uri);
                if (fileData.byteLength === 0)
                    return '';
                const tempDir = os.tmpdir();
                tempFile = path.join(tempDir, `temp_${Date.now()}.odt`);
                await fs.writeFile(tempFile, Buffer.from(fileData));
                filePath = tempFile;
            }
            else {
                const stat = await fs.stat(filePath);
                if (stat.size === 0)
                    return '';
            }
            // The odt2html returns promise
            const html = await odt2html.toHTML({
                path: filePath
            });
            if (tempFile) {
                try {
                    await fs.unlink(tempFile);
                }
                catch { }
            }
            return html;
        }
        catch (error) {
            console.error('Error converting ODT:', error);
            throw new Error(`Failed to convert ODT file: ${error}`);
        }
    }
}
exports.OdtHandler = OdtHandler;
//# sourceMappingURL=odt_handler.js.map