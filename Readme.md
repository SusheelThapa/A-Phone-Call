# A Phone Call

A Phone call is a project which aims to demonstrate how the working of call app that exist in every smart phone.

## Tool we will be using

1. [Visual Studio Code](https://code.visualstudio.com/): As our code editor
2. [g++](https://www.msys2.org/): As our compiler
3. [SDL2](https://www.libsdl.org/download-2.0.php) : As our Library to create GUI interface
4. [Git](https://git-scm.com/) : As our local version control system
5. [Github](https://github.com/) : As our central version control system
6. [Latex](https://www.latex-project.org/) : As our document preparation software
7. [Kali Linux](https://www.kali.org/): As our working operating system

## Project Compilation

We are using [Makefile](Makefile) to compile our project.

**_Basic Command_**

1. Compiling Client Code

   ```make
    make client_one client
   ```

   It will create two client `client_one` and `client_two`.

2. Compiling Server Code

   ```make
    make server
   ```

   It will create `server`.

3. Clean command

   ```make
    make clean
   ```

   It will clean the working directory by removing all those file created using [Makefile](Makefile)

**_Helping Command_**

4. Compiling `client_one` and running

   ```make
   make client_one_run
   ```

5. Compiling `client_two` and running

   ```make
   make client_two_run
   ```

6. Compile `client_one`, `client_two` and `server` at once

   ```make
   make all
   ```

7. Run `server`, `client_one` and `client_two` at once.

   ```make
   make run
   ```
