"use strict";
/**
 * Formats C++-style code into a maximally compact style, following an
 * inclusion-exclusion approach:
 *
 *   1. Tokenize the code (respecting string/char literals and comments).
 *   2. By default, NO space is placed between any two adjacent tokens.
 *   3. A space is added back only at specific, enumerated exceptions:
 *
 *      (a) between two tokens that would otherwise merge into a different
 *          token if written adjacently (e.g. `long` `long` -> "longlong"
 *          would read as one identifier; keywords/identifiers/numbers
 *          separated only by whitespace in the source keep exactly one
 *          space between them).
 *      (b) after the `;` that separates the three clauses of a C-style
 *          `for (...)` header — e.g. `for(int i=0; i<n; i++)`.
 *      (c) after the closing `)` of a braceless `if(...)`, `for(...)`,
 *          `while(...)` header, before its single-statement body — e.g.
 *          `if(e&1) ans=ans*b%m;`.
 *
 * Blank lines are removed, a lone `{` line is joined onto the previous
 * line, and every line is re-indented to `depth * indentSize` spaces
 * based on running brace depth (with braceless single-statement bodies
 * indented one extra level, matching the previous formatter's behavior).
 *
 * String/char literal contents and `//` line-comment text are emitted
 * verbatim and are never touched by the spacing rules above.
 */
Object.defineProperty(exports, "__esModule", { value: true });
exports.formatCompact = formatCompact;
const DEFAULT_INDENT_SIZE = 2;
const WORD_START = /[A-Za-z_]/;
const WORD_CONT = /[A-Za-z0-9_]/;
const DIGIT = /[0-9]/;
/**
 * Tokenizes a single line of C++-like source. Multi-line constructs
 * (block comments, raw strings) are intentionally unsupported, matching
 * the scope of the CP-style single-statement-per-line code this tool
 * targets.
 */
function tokenizeLine(line) {
    const tokens = [];
    let i = 0;
    let sawSpaceBeforeNext = false;
    while (i < line.length) {
        const ch = line[i];
        if (ch === ' ' || ch === '\t') {
            sawSpaceBeforeNext = true;
            i++;
            continue;
        }
        if (ch === '/' && line[i + 1] === '/') {
            tokens.push({ kind: 'comment', text: line.slice(i), precededByOriginalSpace: sawSpaceBeforeNext });
            sawSpaceBeforeNext = false;
            i = line.length;
            continue;
        }
        if (ch === '"') {
            let j = i + 1;
            while (j < line.length && line[j] !== '"') {
                if (line[j] === '\\')
                    j++;
                j++;
            }
            j = Math.min(j + 1, line.length);
            tokens.push({ kind: 'string', text: line.slice(i, j), precededByOriginalSpace: sawSpaceBeforeNext });
            sawSpaceBeforeNext = false;
            i = j;
            continue;
        }
        if (ch === "'") {
            let j = i + 1;
            while (j < line.length && line[j] !== "'") {
                if (line[j] === '\\')
                    j++;
                j++;
            }
            j = Math.min(j + 1, line.length);
            tokens.push({ kind: 'char', text: line.slice(i, j), precededByOriginalSpace: sawSpaceBeforeNext });
            sawSpaceBeforeNext = false;
            i = j;
            continue;
        }
        if (WORD_START.test(ch)) {
            let j = i + 1;
            while (j < line.length && WORD_CONT.test(line[j]))
                j++;
            tokens.push({ kind: 'word', text: line.slice(i, j), precededByOriginalSpace: sawSpaceBeforeNext });
            sawSpaceBeforeNext = false;
            i = j;
            continue;
        }
        if (DIGIT.test(ch) || (ch === '.' && DIGIT.test(line[i + 1] ?? ''))) {
            // Covers ints, floats, exponents (1e9), and hex (0x...).
            let j = i + 1;
            while (j < line.length && /[0-9a-fA-FxX.]/.test(line[j])) {
                // Allow a sign immediately after an exponent marker, e.g. 1e-7.
                if ((line[j] === '+' || line[j] === '-') && /[eE]/.test(line[j - 1])) {
                    j++;
                    continue;
                }
                j++;
            }
            tokens.push({ kind: 'number', text: line.slice(i, j), precededByOriginalSpace: sawSpaceBeforeNext });
            sawSpaceBeforeNext = false;
            i = j;
            continue;
        }
        // Any other single character: treat as its own punctuation token.
        // Multi-character operators (==, <=, &&, ->, <<, etc.) don't need
        // special-casing here since we never insert a space *inside* a
        // run of adjacent punctuation characters — they stay glued together
        // exactly as tokenized, character by character.
        tokens.push({ kind: 'punct', text: ch, precededByOriginalSpace: sawSpaceBeforeNext });
        sawSpaceBeforeNext = false;
        i++;
    }
    return tokens;
}
/**
 * Finds the index (into `tokens`) of the closing `)` that ends a
 * leading `if(...)`/`for(...)`/`while(...)`/`else if(...)` header, if
 * the line starts with one — used to detect exception (c): the header
 * and a single-statement body written on the same source line, e.g.
 * `if(e&1) ans=ans*b%m;`. Returns -1 if the line does not start with
 * such a header, or if the header's `)` is the last code token (i.e.
 * no inline body follows, which is handled by the cross-line
 * braceless-body indent logic instead).
 */
function findInlineBracelessHeaderCloseIndex(tokens) {
    if (tokens.length === 0)
        return -1;
    let start = 0;
    const first = tokens[0];
    if (first.kind === 'word' && first.text === 'else') {
        if (tokens[1]?.kind === 'word' && tokens[1].text === 'if') {
            start = 2;
        }
        else {
            return -1; // bare `else`, handled elsewhere
        }
    }
    else if (first.kind === 'word' && (first.text === 'if' || first.text === 'for' || first.text === 'while')) {
        start = 1;
    }
    else {
        return -1;
    }
    if (!(tokens[start]?.kind === 'punct' && tokens[start].text === '('))
        return -1;
    let depth = 0;
    for (let i = start; i < tokens.length; i++) {
        const tok = tokens[i];
        if (tok.kind === 'punct' && tok.text === '(')
            depth++;
        if (tok.kind === 'punct' && tok.text === ')') {
            depth--;
            if (depth === 0) {
                // Only exception (c) if a real single-statement body follows —
                // i.e. the next non-comment token exists and is not `{`. A `{`
                // right after the header's `)` is a normal braced block, which
                // is always glued directly (handled by the `{`-gluing rule in
                // `shouldInsertSpace`), not an inline single-statement body.
                const next = tokens.slice(i + 1).find((t) => t.kind !== 'comment');
                const hasInlineBody = next !== undefined && !(next.kind === 'punct' && next.text === '{');
                return hasInlineBody ? i : -1;
            }
        }
    }
    return -1;
}
/**
 * Joins tokens for a single line back into a string, inserting a
 * single space only where one of the enumerated exceptions applies.
 */
function joinTokens(tokens) {
    let out = '';
    const inlineHeaderCloseIdx = findInlineBracelessHeaderCloseIndex(tokens);
    for (let idx = 0; idx < tokens.length; idx++) {
        const tok = tokens[idx];
        const prevTok = idx > 0 ? tokens[idx - 1] : null;
        if (idx === 0) {
            out += tok.text;
            continue;
        }
        const isExceptionC = idx === inlineHeaderCloseIdx + 1;
        const needsSpace = isExceptionC || shouldInsertSpace(prevTok, tok);
        out += (needsSpace ? ' ' : '') + tok.text;
    }
    return out;
}
/**
 * Exception (a): two "word-like" tokens (word/number) that were
 * separated by whitespace in the original source must stay separated,
 * since gluing them would change or corrupt the token stream
 * (`long` + `long` -> `longlong`, `return` + `0` -> `return0`).
 * Comments always get exactly one separating space so they read
 * cleanly; string/char literals never trigger this rule themselves
 * (only their presence as a whole token matters for adjacency).
 */
function isWordLike(tok) {
    return tok.kind === 'word' || tok.kind === 'number';
}
function shouldInsertSpace(prev, cur) {
    // An opening brace `{` is always glued directly onto whatever
    // precedes it (`){`, `struct Matrix{`, `else{`, ...) — this overrides
    // every other exception below, matching the target style where
    // `while(e>0){` and `for(...){` never have a space before `{`.
    if (cur.kind === 'punct' && cur.text === '{') {
        return false;
    }
    if (cur.kind === 'comment') {
        return true; // always separate trailing comments from code
    }
    if (isWordLike(prev) && isWordLike(cur) && cur.precededByOriginalSpace) {
        return true; // exception (a)
    }
    if (prev.kind === 'punct' && prev.text === ';' && cur.precededByOriginalSpace) {
        // exception (b): space after `;` — most relevant inside a
        // `for (init; cond; step)` header, but harmless (and matches the
        // "keep it readable" intent) for any statement-separating `;`
        // that already had a space after it in the source.
        return true;
    }
    return false;
}
/**
 * Detects, on the *tokenized* line, whether the code ends with a
 * braceless `if(...)`, `for(...)`, `while(...)`, or `else if(...)`
 * header (i.e. the header's closing `)` is the last non-comment
 * token and no `{` follows it on the same line).
 */
function endsWithBracelessHeader(tokens) {
    const codeTokens = tokens.filter((t) => t.kind !== 'comment');
    if (codeTokens.length === 0)
        return false;
    const last = codeTokens[codeTokens.length - 1];
    if (!(last.kind === 'punct' && last.text === ')'))
        return false;
    const first = codeTokens[0];
    if (first.kind === 'word' && (first.text === 'if' || first.text === 'for' || first.text === 'while')) {
        return true;
    }
    if (first.kind === 'word' &&
        first.text === 'else' &&
        codeTokens[1]?.kind === 'word' &&
        codeTokens[1].text === 'if') {
        return true;
    }
    return false;
}
function isBareElse(tokens) {
    const codeTokens = tokens.filter((t) => t.kind !== 'comment');
    return codeTokens.length === 1 && codeTokens[0].kind === 'word' && codeTokens[0].text === 'else';
}
function splitTrailingComment(line) {
    let inString = null;
    for (let i = 0; i < line.length; i++) {
        const ch = line[i];
        const prev = i > 0 ? line[i - 1] : '';
        if (inString) {
            if (ch === inString && prev !== '\\') {
                inString = null;
            }
            continue;
        }
        if (ch === '"' || ch === "'") {
            inString = ch;
            continue;
        }
        if (ch === '/' && line[i + 1] === '/') {
            return { code: line.slice(0, i), comment: line.slice(i) };
        }
    }
    return { code: line, comment: null };
}
function braceDelta(code) {
    let opens = 0;
    let closes = 0;
    let inString = null;
    for (let i = 0; i < code.length; i++) {
        const ch = code[i];
        const prev = i > 0 ? code[i - 1] : '';
        if (inString) {
            if (ch === inString && prev !== '\\') {
                inString = null;
            }
            continue;
        }
        if (ch === '"' || ch === "'") {
            inString = ch;
            continue;
        }
        if (ch === '{')
            opens++;
        if (ch === '}')
            closes++;
    }
    return { opens, closes };
}
/**
 * Main entry point: reformats a block of C++-like source into the
 * maximally compact house style described above.
 */
function formatCompact(source, indentSize = DEFAULT_INDENT_SIZE) {
    const rawLines = source.split(/\r?\n/);
    // Pass 1: drop blank lines, and join a line that is only `{`
    // (optionally with a trailing comment) onto the previous non-blank line.
    const joined = [];
    for (const rawLine of rawLines) {
        const trimmed = rawLine.trim();
        if (trimmed.length === 0) {
            continue; // drop blank lines entirely
        }
        const { code } = splitTrailingComment(trimmed);
        const codeTrimmed = code.trim();
        if (codeTrimmed === '{' && joined.length > 0) {
            joined[joined.length - 1] = joined[joined.length - 1] + '{';
            continue;
        }
        joined.push(trimmed);
    }
    // Pass 2: tokenize + compact-join each line's code portion, then
    // re-indent based on running brace depth. A trailing `if (...)` /
    // `for (...)` / `while (...)` with no opening brace on the same line
    // implies its single-statement body is indented one extra level on
    // the next line only.
    const output = [];
    let depth = 0;
    let pendingBracelessBodyIndent = false;
    for (const line of joined) {
        const { code, comment } = splitTrailingComment(line);
        const codeTrimmed = code.trim();
        const isLeadingCloser = /^}/.test(codeTrimmed);
        if (isLeadingCloser) {
            depth = Math.max(0, depth - 1);
        }
        const tokens = tokenizeLine(codeTrimmed);
        const compactedCode = tokens.length > 0 ? joinTokens(tokens) : '';
        const extraIndent = pendingBracelessBodyIndent && !isLeadingCloser ? 1 : 0;
        const indent = ' '.repeat((depth + extraIndent) * indentSize);
        const rebuilt = comment
            ? (compactedCode.length > 0 ? `${indent}${compactedCode} ${comment.trim()}` : `${indent}${comment.trim()}`)
            : `${indent}${compactedCode}`;
        output.push(rebuilt);
        pendingBracelessBodyIndent = false;
        const { opens, closes } = braceDelta(codeTrimmed);
        const netOpens = opens;
        const netCloses = isLeadingCloser ? closes - 1 : closes;
        depth = Math.max(0, depth + netOpens - netCloses);
        if (opens === 0 && (endsWithBracelessHeader(tokens) || isBareElse(tokens))) {
            pendingBracelessBodyIndent = true;
        }
    }
    return output.join('\n');
}
//# sourceMappingURL=formatter.js.map