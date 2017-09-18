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
Visual Studio project. You can then paste them into **C:\Windows** or
**C:\Windows\System32** so that they can be run anywhere in the command prompt.

Build the executables.

![dir](https://github.com/hanstxu/bash.exe/blob/master/screenshots/bash_build.gif)

Move the executables to a PATH folder (e.g. **C:\Windows** or
**C:\Windows\System32**).

![dir](https://github.com/hanstxu/bash.exe/blob/master/screenshots/bash_move.gif)

Run the executables.

![dir](https://github.com/hanstxu/bash.exe/blob/master/screenshots/bash_example.gif)

## Progress

Implemented ls.exe without options

Implement touch.exe w/o options

## TODO

~~Implement rm.exe w/o options~~ del adequately performs this function well

Implement options and error handling