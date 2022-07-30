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

## Project Progess

### Phase One

- [x] Design iphone dialpad, incoming screen and outgoing screen
- [x] Create a phone call class(Two client will be created from it)
- [x] Create a server(acts as bridge for two client to communicate)
- [x] Create two client from phone call class
- [x] Implement dialpad screen on both client
- [x] Show the incoming call screen when one client call another(when call button is pressed)
- [x] When client reject the incoming call, drop the call of the client who is calling
- [x] When client accept the call show the time they are calling each other
- [x] Display the name of the client who is called to who.
- [x] After the call has been connected when one user pressed the end call button drop the call.
- [x] Add the script file to to download necessary libraries for compilation of this project

### Phase Two

- [x] Opening screen animation with different color for different clients
- [x] Made every button clickable playing specific sound for specific button
- [x] Dial pad number appearing when we press numbers
- [x] Limited number length to 10 digits
- [x] Backspace button added with functionality to remove one number when pressed
- [x] Refreshing dialpad entered number when green call button is pressed
- [x] Ongoing call sound apperance after call button is pressed
- [x] When pressed end button, shows red text as "Call Ended"
- [x] When the receiver cuts the call, specific NCELL, unable to call sound appearance
- [x] Iphone incoming call ringtone set with required amplitude
- [x] Outgoing call sound and Incoming call sound set nearly to equal intensity
- [x] Fixed different bugs related to backspace error when no number is pressed, 
## Screenshots

1. Dial Pad Screen

   ![Dial Pad Screen](/Screenshots/dial_pad.png)

2. Incoming Call Screen

   ![Incoming Call Screen](/Screenshots/incoming-call.png)

3. Outgoing Call Screen

   ![Outgoing Call Screen](/Screenshots/outgoing-call.png)

4. Call in progress screen

   ![Call in Progress](/Screenshots/call-in-progess.png)

## Installation

This project has been created and tested in linux platform.

For other platform, ..............

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
