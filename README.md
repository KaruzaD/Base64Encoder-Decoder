# Base64 Encoder/Decoder

A command-line base64 encoder/decoder program.

Running
========
base64enc [InputStream] [-d=decrypt]  
- InputStream is the file or stream to use, default is `stdin`. Can also be replaced with `<` in most shells
- -d used as the first or second argument will decrypt encrypted base64 ASCII  
If using `stdin` as input stream, then press `CTRL-D` on Linux (`ENTER` then `CTRL-Z` on Windows) to stop reading input and finish the program.

Linux
-----
- Copy files to a separate folder
- Open a terminal to the application/build_linux folder
- Run `chmod +x base64enc`
- Run `./base64enc` with desired arguments

Windows
-------
- Copy files to a separate folder
- Open a terminal/command prompt to the application/build_windows/Debug folder
- Run `./base64enc` with desired arguments

Building
========
Linux
-----
- Install GCC compiler
- Copy all files and directories
- Navigate to base directory/build_linux in terminal, containing `makefile`
- Run `make base64enc`

Windows
-------
- Install CMake or Visual Studio with C++ desktop extension
- (with CMake) navigate to build_windows folder in a terminal
- (with CMAKE) run `cmake --build .`
- (with Visual Studio) open up build_windows/base64enc.sln in Visual Studio; press F5
