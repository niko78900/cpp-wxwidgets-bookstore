# Library System (wxWidgets)

This is a simple desktop GUI app that demonstrates a bookstore/library
workflow: browse available items, view details, add or edit entries, move
items to a shopping cart, and checkout.

## Purpose
- Showcase OOP with a base Book type and Magazine specialization
- Practice wxWidgets UI layout and event handling
- Provide a small CRUD + cart demo

## Tech
- C++
- wxWidgets (GUI)
- MSYS2 MinGW64 toolchain (g++, wx-config)

## How to build/run
See `WXWIDGETS_SETUP.md` for full setup steps.
Quick run:
- Build task: "Build wxWidgets app (MSYS2 MINGW64)"
- Debug/Run: "Launch wxWidgets app"

## Project layout
- `App.h` / `App.cpp`: wxApp entry point
- `MainFrame.h` / `MainFrame.cpp`: main window, UI, and event handlers
- `Book.h` / `Book.cpp`: base model for library items
- `Magazine.h` / `Magazine.cpp`: Book subclass with publisher/issue
