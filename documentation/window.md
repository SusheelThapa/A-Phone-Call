# Window

This is documentation of [window.hpp](../include/headers/window.hpp) and [window.cpp](../src/window.cpp).

---

## Private variables

1. `title`

    This is the title of the window we will be rendering.

    In this below window, we can see SDL as the title of the window.

    ![window-title-demonstration](/resources/images/window-title.png)

2. `width` and `height`:

   This is the width and height of the window we will be rendering.

   Both the variable are declared static so if you need to change the dimension of the window you can simply change the value of width and height.

3. `closed`:

   It is used to store whether window is closed or not.

4. `window`:

    It is our main window object.

5. `e`:

    It will store all the events that is happening while we are running the program and later on we can handle all the events.

---

## Public Variables

1. `renderer`:

---

## Private Functions

1. `init()`

    This is used to initialize SDL followed by window creation, window renderer creation and other things like image, true type fonts,etc based on the header files included by the user.

    **Usage**:

    This function is called via constructor.

    ```C++
    Window::Window()
    {
        this->init();
    }
    ```

---

## Public Function

1. `handleEvent()`:

    Since, we have an variable to store all the event that has occured while running the program.

    This function extract all those events one by one and handle it.

    **Usage**:

    ```C++
    // In window.cpp
    while(SDL_PollEvent(&this->e) != 0)
    {
        if(e.type ==SDL_QUIT || e.key.keysym.sym ==SDLK_ESCAPE)
        {
            this->closed = true;
        }
    }
    ```

    - First of all , SDL_PollEvent() is used to extract all those event one by one.
    - And inside while loop all the events are handle.
    - Here, only one events is handle i.e when user press `ESCAPE` key or click `X` of that window we will set `closed = true` so that our window is closed.

        There are other various events we can handle here.

        You can add all those based on your need.

    ---

2. `clear(SDL_Color)`:

    Suppose when we build a house, we first paint it with some color then after that we apply other color.

    Similary, we have created window and renderer object and now its turn to color the window we have created. So this function basically color the window.

    And it takes an arugment color with which it clear the screen of the window.

    **Usage**:

    ```C++
    // Game loop
    while(...)
    {
        // Other code: It show an image of tiger
        window.clear({0,0,0,0});
        // Other code: It show an image of lion
    }
    ```

    First, we have shown a image of tiger and to show the image of lion we first clear the screen and display the image of lion on it.

3. `present()`:

    This function we use to show up the context inside of that window.

    **Usage**:

    This function is called at last of the program loop

    ```C++
    Window window;

    // Game Loop begins
    while(!window.isClosed())
    {
        // Other code
        window.present();
    }
    ```

4. `isWindowClosed()`:

    This is used to check whether the window has been closed or not.

    **Usage**:

    ```C++
    // Game loop
    while(window.isClosed())
    {
        // code
    }
    ```

    Game loop is actualy and infinte loop and it terminate when the window is closed i.e the value of [`closed`](#private-variables) is true.

5. `getWidth()`:

    This is used to get the width of the window.

6. `getHeight()`:

    This is used to get the height of the window.

---
