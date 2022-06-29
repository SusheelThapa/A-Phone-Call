# SDL Templates

SDL stands for simple media direct layer which is simple language is the library that is used to add graphics and create projects/games/application using C/C++ language.

The best learning platform for SDL is [lazyfoo website](https://lazyfoo.net). Moreover, you can find alot of youtube video that is teaching SDL you can refer to them also.

Moreover, you will figure out that all the code contain here may ressamble with that present in the [lazyfoo website](https://lazyfoo.net)

And the credit for this concept goes to [Rohan Acharya](https://github.com/rohanacharya98)

---

## Objective

In simple language, SDL is a graphics library that is used in C/C++ to make various simple application.

Even though learning SDL is not that must hard, but when you have a brief idea on how SDL work. Then, even for small things you need to write alot of code and remember those new function

```C++
// CODE PICKED FROM lazyfoo.net
/* A piece of code to create window */
int main(int argc, char *args[])
{
    // Creating SDL variable
    SDL_Window *window = nullptr;
    SDL_Surface *screen_surface = nullptr;

    // Initialize SDL parameter that will be used
    SDL_Init(SDL_INIT_VIDEO);

    // Creating window
     window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_SHOWN);

    // Getting the surface of the Screen
    screen_surface = SDL_GetWindowSurface(window);

    // Draw over the screen
    SDL_FillRect(screen_surface, nullptr, SDL_MapRGB(screen_surface->format,0xFF,0xFF,0xFF));

    // Updating the screen of the window
    SDL_UpdateWindowSurface(window);

    // Pause the program for 2000 milli second so that the user can see the window.
    SDL_Delay(2000);

    // Destroy the window.
    SDL_DestroyWindow(window);

    // Quit SDL
    SDL_Quit();

    return 0;
}

```

SDL indeed make our work easier, but it would be easy if we have an object `Window` and initialize all the `SDL parameter` when it is created and display it content over the screen with just one function click.

This is the goal of the this repository to provide you an easy interface to interact and code in SDL to make great projects in a short period of time.

To conclude, SDL is like the part of the vehicle and we need to assemble those part and model the car we want to model. And we aims to assemble all those part and make a simple prototyppe of that car and hand over to you and your job is to model the car the way you like. But it mayn't include all those material that you wish and need to add yourself.

---

## How should you approach?

Here are some few suggestion on how you should approach:

1. *It is to be noted that SDL is written in C*. So, if you know C you can write program using SDL
2. Here, we are making use of OOPs to make our template so that you must be familiar with OOPs concept
3. We are using C++ as our language to code so it is recommended to know OOPs in C++.
4. Before going through all the template, you first need learn SDL else you wonot be able to use it properly to 100%.
5. You can learn SDL from [lazyfoo website](https://lazyfoo.net/tutorials/SDL/index.php)
6. It is not necessary that you need to know all the things that are mention over [lazyfoo website](https://lazyfoo.net/tutorials/SDL/index.php)
7. You can learn below topics to be familar with and start coding SDL program.
    - Hello SDL
    - Getting Image on the screen
    - Event Driven Programming
    - Key Presses
    - Optimized Surface loading
    - Loading other Image format
    - Texture Loading
    - Geometry rendering
    - Color Keyring
    - Clip Rendering
    - Color Modulation
    - Animated sprited and Vsync
    - Rotaion and Flipping
    - True Type font
    - Mouse Events
    - Key States
    - Text Input and ClipBoard Handling
    - File Reading and Writing
    - Window Events

8. More over the template here written are to some extent similar to the code written there as most of the people learn SDL from that website.

## Documentation

Since, now we have made a prototype of the car now its time tell how it workd where documentation comes in.

When we have written our `.hpp` and `.cpp` file we will be writing `.md` which provide you idea how to use what we have made.

And here we will provide you link to that `.md` file

- [Window](documentation/window.md)
- [Texture](documentation/texture.md)
- [Shape](documentation/shape.md)

---

## Project Setup

### Linux

1. Clone the repository.
2. Build and run project using command.

    ```bash
        bash run.sh
    ```

---

### Window

1. Clone the repository
2. Build the project using the command.

    ```cmake
    mingw32-make.exe
    ```
    *Sometime this mightn't work in that case use the below commmand*

    ```terminal
    g++ main.cpp src/*.cpp -I include/headers -I include -L include/lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o main
    ```
    
3 It will create an executable and run the executable

---

## Contribution

Check out [contribution.md](CONTRIBUTION.md) to contribute in this repository

---

## Author

- [@susheel_thapa](https://github.com/SusheelThapa)
- [@raj_kumar_paneru](https://github.com/Rajkumarpaneru18)
  