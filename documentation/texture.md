# Texture

This is the documenation of the [texture.hpp](../include/headers/texture.hpp) and [texture.cpp](../include/headers/texture.hpp).

## private variable

1. `texture`

    It is the actually variable where the content that is to be render is store. You can basically thinking it as equivalent as image.

2. `width`

    It store the width of the texture that has been created.
3. `height`

    It store the height of the texture that has been created.

## private function

1. `free()`

    It is basically used to free up all the memory used by the Texture class.
    It is called from **destructor** when the object is destroyed.

    ```c++
    Texture::~Texture()
    {
        this->freee();
    }
    ```

    *destructor are those special method that is called when an obejct is destroyed*

## public function

1. `loadFromFile()`

    *This function is applicable only when **SDL\_image.h** header file is included*

    It is used to load the image that we have in our local machine into texture variable that has be defined above so that we can show it over the screen of the window that we will be created.

    **arguments:**

    1. `Window`: An instance of [Window](../include/headers/window.hpp) class object
    2. `std::string`: path of the image that will be store in texture variable.

    **Usage:**

    ```c++
    Window window;
    Texture t1;

    t1.loadFromFile(window, "1.jpg");
    ```

2. `loadFromText()`

    *Currently it make use of TTF_Font object but sooner we will implement font class and that will be used here.*
    *So that when Font class is made we will document this one*

    **arguments:**

    **Usage**:

3. `getWidth()`

    It is used to get the width of the texture that we have created.

4. `getHeight()`

    It is used to get the height of the texture that we have created.

5. `render()`

    It is used to display the content of texture variable over the screen

    **arguments:**

    1. `Window window`

        An instance of [Window](../include/headers/window.hpp)) class object

    2. `int x, int y`

        The x-coordinate adn y-coordintate of the window from where you want to display the loaded texture on the window

    3. `SDL_Rect render_rect`

        Sometime we donot want to display whole image but a portion of image to display for this we define a rectange of the portion, we want to show from the image.

        *Note the rectangle portion must be relative to render_quad not he actual image size*

    4. `SDL_Rect render_quad`

        It is the a small portion of rectangle of the big window.

        Basically by default, our texture is loaded all over the window.
        What if we want ot load the texture over certain part of the window.
        Then we defined the part interms of rectange and pass it as argument for this so that it can render over specified portion that has been described by passed rectangle.

    5. `double angle`

        If you want to rotate the texture then it describe by what angle you want to rotate the texture.

    6. `SDL_Point center`

        It is the point from which the rotation of the texture is done.

    7. `SDL_RendererFlip flip`

        It isjust used to flip the texture equivalent to reflected image.

        **Usage:**

        ```C++
        ...
        // When you have load the image/text over Texture class object
        t1.render(window,0,0,nullptr,nullptr)
        t2.render(windwo,0,0,nullptr,nullptr,90,{100,100},SDL_FLIP_NONE)
        ...
        ```
