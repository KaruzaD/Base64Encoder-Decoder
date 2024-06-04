# Base64 Encoder/Decoder

A command-line base64 encoder/decoder program.

Running
========
base64enc [InputStream] [-d=decrypt]  
- InputStream is the file or stream to use, default is `stdin`. Can also be replaced with `<` in most shells
- -d used as the first or second argument will decrypt encrypted base64 ASCII  
If using `stdin` as input stream, then press `CTRL-D` to stop reading input and finish the program.  

Linux
-----
- Copy files to a separate folder
- Open a terminal to the application folder
- Run `chmod +x base64enc`
- Run `./base64enc` with desired arguments  

Windows
-------


Building
========
Linux
-----
- Copy all files and directories
- Navigate to base directory in terminal with `makefile`
- Run `make base64enc`
 
