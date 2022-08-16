# A Phone Call

A Phone call is a project which aims to demonstrate how the working of call app that exist in every smart phone.

## Installation of Dependencies

This project has been created and tested in **linux platform**.


1. First of all give `install.sh` file executable permission

   ```terminal
   chmod +x install.sh
   ```

   _Note:Make sure you are in the place which has `install.sh`_

2. Run `install.sh`

   ```terminal
   ./install.sh
   ```

   _Give it sometime it will install all the dependencies required by the project. When it completed you can head over to [Project Compilation](#project-compilation)_
## Project Compilation

We are using [Makefile](Makefile) to compile our project.

**_Basic Command_**

1. Compiling Client Code
v
   ```make
    make client_one client_two
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

## Others

You can find the screenshot of the project [here](/resources/markdown/screenshot.md).

Moreover, you can look into other detail of the project [here](/resources/markdown/information.md).