# bash.exe

bash commands for windows implemented with C++ and the Windows API

**ls**

![ls](https://github.com/hanstxu/bash.exe/blob/master/screenshots/ls.png)

looks much better than **dir**

![dir](https://github.com/hanstxu/bash.exe/blob/master/screenshots/dir.png)

For now, I'll just include the sources files and not all the extra
files that Visual Studio includes with every project (e.g. project
configuration, solution files). They are compiled using the Visual
Studio C++ compiler.

This is a low-priority project so I'll work on it when I have free time.

## How to Use

Once built, the executables can be found in the **Debug** folder of your
Visual Studio project or from **ls_touch.zip** in
[release v0.1.0](https://github.com/hanstxu/bash.exe/releases). You can then
paste them into **C:\Windows** or **C:\Windows\System32** so that they can be
run anywhere in the command prompt.

1. Build the executables.

![bash_build](https://github.com/hanstxu/bash.exe/blob/master/screenshots/bash_build.gif)

2. Move the executables to a PATH folder (e.g. **C:\Windows** or
**C:\Windows\System32**).

![bash_move](https://github.com/hanstxu/bash.exe/blob/master/screenshots/bash_move.gif)

3. Run the executables.

![bash_example](https://github.com/hanstxu/bash.exe/blob/master/screenshots/bash_example.gif)

## Progress

Implemented ls.exe without options

Implement touch.exe w/o options

## TODO

~~Implement rm.exe w/o options~~ del adequately performs this function well

Implement options and error handling