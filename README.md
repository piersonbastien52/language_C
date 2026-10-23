# Shape Manager CLI (C Project)

A command-line shape manager (CLI) developed in C (C99). This program allows users to create, edit, display, delete, and export geometric shapes in SVG format.

---

##  Features

Supported Shapes:

- Rectangle (origin, height, width)
- Square (origin, side length)
- Circle (center, radius)
- Ellipse (center, horizontal radius, vertical radius)
- Line (defined by two coordinate points)

## Style Management:

- Fill and stroke colors (hexadecimal format #RRGGBB).
- Adjustable fill and stroke opacity.
- Stroke width customization.
- Geometric transformations (translation tx, ty and rotation angle).

## Data Structure:

- Linked list implementation for dynamically managing the collection of shapes.

## Exporting:

- Generation of an SVG output file to visually render created shapes.

---

## Project architecture

Project/
│
├── All_shapes.c                # Shape implementation (creation, editing, display, deletion)
├── project_CLI.c               # Main entry point and CLI menu management
├── Makefile                    # Build automation file
│
├── CLI/
│   └── CLI_library.c           # Utility functions for CLI display and navigation
│
├── export/
│   ├── export.c                # SVG export logic
│   └── export.h                # SVG export header
│
└── Representation/
    ├── generation.c            # Linked list management and memory deallocation
    └── library/                # Header files and submodules (structures, styles, points, etc.)
        ├── All_shapes.h
        ├── apply_style.h
        ├── circle.h
        ├── color.h
        ├── ellipse.h
        ├── enum.h
        ├── line.h
        ├── point.h
        ├── Points.h
        ├── rectangle.h
        ├── square.h
        └── styles.h
```
