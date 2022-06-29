# Shape

This is the documentation of [shape.hpp](../include/headers/shape.hpp) and [shape.cpp](../src/shape.cpp) along with all the class that are made via inheritance from this class also like [rectangle.hpp](../include/headers/rectangle.hpp), [triangle.hpp](../include/headers/triangle.hpp) and [line.hpp](../include/headers/line.hpp).

Up to now, only line, triangle, rectangle have been implemented. Later on we will implement other if possible.

## Base Class : Shape

### Private Variable

1. `color`:

It denote the color of the shape we are going to create on our window.

### Public Function

1. `setColor(int, int, int, int)`:

    It is used to set the color of we are going to use while create shape.
    Here, the four integer argument are **r**, **g**,**b** and **a** i.e red, blue, green and alpha value of the color that we are using.

2. `getColor()`:

    It is used to return the color value that we are going to use while creating shape.

3. `render(Window &)`:

    It is used to render the shape in the window.
    But this function is **virtual function** are will be overriden when we create derived class.

    And it takes **Window** object as an argument which is avaliable in [window](../include/headers/window.hpp).

## Derived Class

To till now, there is three derived class:

1. [Rectangle](#rectangle)
2. [Line](#line)
3. [Triangle](#triangle)

### Rectangle

#### Private Variable

1. `starting_point`

    It is the point from where we start drawing rectangle.

2. `width` and `height`

    It is the height and width of the rectangle.

#### Public Function

1. `render()`:

    This is function we are overriding form Base class [shape](../include/headers/shape.hpp) as it was declare **virutal**.

    And this function is used to render the rectangle in the window.

    **Usage:**
    - First of all set the color, starting_point, width and height of the rectangle.
    - And use render function whenever you want to draw it over window.

    ```C++
        rect.render(window)
    ```

### Line

#### Private Variable

1. `point_one` and `point_two`

    It is used to store the  value of end point of the line that we want to render.

#### Private Function

1. `setPoint(int point_value, SDL_Point)`

    It is used to set the value of private variable one at a time.
    The value of argument **point_value** will determine whose point we are setting.

#### Public Function

1. `setPoints(int x1, int y1 ,int x2, int y2)`:

    It is used to set the value of point.

    Internally, it calls  **setPoint** private function to set the value of individual point.

2. `render(Window &window)`

    It is used to render the line over the screen.

    **Usage:**

    - First of all set the color and point value of Line.
    - And use render function whenever you want to draw it over window.

    ```C++
        lin.render(window)
    ```

### Triangle

#### Private Variable

1. `point_one`, `point_two` and `point_three`:

    It is used to store the three co-ordinate of the triangle that we are going to render.

#### Private Function

1. `setPoint(int point_value, SDL_Point)`

    It is used to set the value of private variable one at a time.
    The value of argument **point_value** will determine whose point we are setting.

#### Public Function

1. `setPoints(int x1, int y1 ,int x2, int y2, int x3, int y3)`:

    It is used to set the value of point.

    Internally, it calls  **setPoint** private function to set the value of individual point one at a time.

2. `render(Window &window)`

    It is used to render the triangle over the screen.

    **Usage:**

    - First of all set the color and three point value of triangle.
    - And use render function whenever you want to draw it over window.

    ```C++
        triang.render(window)
    ```
