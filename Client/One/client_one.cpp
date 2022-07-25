#include <iostream>
#include "window.hpp"
#include <fstream>

#define SERVER_FILE "Server/server.txt"
#define CLIENT_ONE_FILE "Client/One/client_one.txt"
#define CLIENT_Two_FILE "Client/Two/client_two.txt"

int main(int argc, char const *argv[])
{
    Window client_one("Client One");
    SDL_Event e;

    while (!client_one.isWindowClosed())
    {
        while (SDL_PollEvent(&e) != 0)
        {
            client_one.handleEvent(e);

            /*It is used to communicate with server*/
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_s)
            {
                std::fstream out_file;

                out_file.open(SERVER_FILE, std::ios::out);

                if (out_file)
                {

                    out_file << "Calling Client Two from Client One" << std::endl;

                    out_file.close();
                }
                else
                {
                    std::cout << "File doesn't exist";
                }
            }
        }

        client_one.clear({125, 234, 254, 164});
        client_one.present();
    }

    return 0;
}
