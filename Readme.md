# A Phone Call

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
