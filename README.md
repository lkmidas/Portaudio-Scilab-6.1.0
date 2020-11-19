# Portaudio Toolbox for Scilab 6.1.0
The official Portaudio Toolbox v0.2 is only for Scilab 5.4.0 and is not compatible with Scilab 6.1.0. The old source code is also cannot be built with the latest Microsoft Visual Studio. Therefore, I reverse engineered and modified it a bit to make it buildable and loadable by Scilab 6.1.0. This is the modified source.

## Build
Run `builder.sce` with Scilab.

## Installation
Zip the built folder and install it normally using `atomsInstall("/path/to/zipfile")`.

## Steps to modify & build
In case you want to modify the official source code to see for yourself, here are the steps that I did:
1. Download the official source and built binaries from [this link](https://atoms.scilab.org/toolboxes/portaudio/0.2).
2. In `builder.sce` line 20: replace `if v(2) < 4 then` with `if v(1) <= 5 && v(2) < 4 then`, also fix a string at line 28.
3. In some `src/c` files: replace uppercase `MALLOC` and `FREE` with lowercase `malloc` and `free`.
4. Also in some `src/c` files: remove `#include "strdup_windows.h"`.
5. In `etc/portaudio_toolbox.start` line 12: replace `portaudio.start` with `portaudio_toolbox.start`.
6. In all `sci_gateway/c` files: add `void* pvApiCtx` as a 2nd parameter to all functions' declaration.
7. Copy `DESCRIPTION` file from official source archive to modified source.
8. Run `builder.sce`.
