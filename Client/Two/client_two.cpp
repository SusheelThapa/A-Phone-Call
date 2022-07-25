#include <iostream>
#include "window.hpp"

int main(int argc, char const *argv[])
{
    Window client_two("Client Two");
    SDL_Event e;

    while (!client_two.isWindowClosed())
    {
        while (SDL_PollEvent(&e) != 0)
        {
            client_two.handleEvent(e);
        }

        client_two.clear({125, 234, 254, 164});
        client_two.present();
    }

    return 0;
}
