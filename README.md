# Portaudio Toolbox for Scilab 6.1.0
The official Portaudio Toolbox v0.2 is only for Scilab 5.4.0 and is not compatible with Scilab 6.1.0. The old source code is also cannot be built with the latest Microsoft Visual Studio. Therefore, I modified it a bit to make it buildable and loadable by Scilab 6.1.0. This is the modified source.
## Build
Run `builder.sce` with Scilab.
## Installation
Zip the built folder and install it normally using `atomInstall("/path/to/zipfile")`.