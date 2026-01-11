# wxWidgets Setup (MSYS2 MinGW64)

This project builds with MSYS2's MinGW64 toolchain and wxWidgets.

## 1) Install MSYS2 + wxWidgets (once)
1. Install MSYS2 from https://www.msys2.org/ (default path: C:\msys64).
2. Open the "MSYS2 MinGW 64-bit" shell and run:

   pacman -Syu
   pacman -S --needed mingw-w64-x86_64-gcc mingw-w64-x86_64-wxwidgets gdb make

## 2) Build from PowerShell

C:\msys64\msys2_shell.cmd -mingw64 -defterm -no-start -here -lc 'g++ *.cpp $(wx-config --cxxflags --libs) -o wx_test.exe'

## 3) Run
Option A (inside MSYS2):

C:\msys64\msys2_shell.cmd -mingw64 -defterm -no-start -here -lc './wx_test.exe'

Option B (PowerShell PATH for this session):

$env:PATH = "C:\msys64\mingw64\bin;$env:PATH"
.\wx_test.exe

## VS Code
- Build task: "Build wxWidgets app (MSYS2 MINGW64)" (Ctrl+Shift+B).
- Run/debug: "Launch wxWidgets app" (F5).

## Troubleshooting
- wx-config not found: install `mingw-w64-x86_64-wxwidgets` in MSYS2.
- wx/wx.h not found: build inside MinGW64 and ensure the package is installed.

