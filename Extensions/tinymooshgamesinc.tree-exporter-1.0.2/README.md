# Tree Exporter

Tree Exporter is a Visual Studio Code extension that exports the directory structure of your project as a text-based tree. It's a great utility for generating visual trees of files and folders, making it easy to share or document your project's structure.

## Features

The Tree Exporter extension allows you to:

- Export the directory structure of your project as a text-based tree.
- Generate visual trees of files and folders for easy sharing or documentation.
- Exclude specific directories from the export.
- Include previously excluded directories in the export.
- Run the command from the command palette or the explorer context menu.

![Tree Exporter in action](https://github.com/glenwrhodes/tree-exporter/raw/HEAD/images/screenshot.png)

## Usage

1. Open a folder in Visual Studio Code.
2. Press `Ctrl+Shift+P` (or `Cmd+Shift+P` on macOS) to open the command palette.
3. Search for "Tree Exporter: Export" and run the command.
4. A new text document containing the directory structure will open.

Alternatively, you can right-click on a folder in the VS Code explorer and select "Export Tree" from the context menu.

To exclude a directory from the tree export, right-click on the folder and select "Exclude from tree export" from the context menu. To include a previously excluded directory, right-click on the folder and select "Include in tree export" from the context menu.

[License](https://github.com/glenwrhodes/tree-exporter/blob/HEAD/LICENSE.md)

## Requirements

There are no specific requirements or dependencies for this extension.

## Known Issues

There are no known issues at this time.

## Changelog

### 1.0.2
- Grouped context menu items under a horizontal separator for better organization.
### 1.0.1
Added ability to exclude and include directories, as well as excluding .git folders.

**Enjoy!**