#include "window.hpp"
#include "texture.hpp"
#include "line.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"

int main(int argc, char *argv[])
{
    // An object of window class with 400 * 400 dimension
    Window window("SDL");

    // An instance of shape class
    Line l1;
    Triangle t1;
    Rectangle r1({100, 100}, 50, 50);

    l1.setColor(255, 255, 255, 255);
    l1.setPoints(100, 200, 50, 350);

    t1.setColor(255, 0, 0, 255);
    t1.setPoints(0, 0, 100, 300, 400, 390);

    r1.setColor(0,255,0,255);

    /*Game Loop*/
    while (!window.isWindowClosed())
    {
        // Handle the events
        window.handleEvent();

        // Clear the window
        window.clear({0, 0, 0, 0});

        l1.render(window);
        t1.render(window);
        r1.render(window);

        // Present the window.
        window.present();
    }

    return 0;
}