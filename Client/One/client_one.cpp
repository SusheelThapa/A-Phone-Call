#include <iostream>
#include "window.hpp"
#include <fstream>

#define SERVER_FILE "Server/server.txt"
#define CLIENT_ONE_FILE "Client/One/client_one.txt"

int main(int argc, char const *argv[])
{
    Window client_one("Client One");
    SDL_Event e;

    std::fstream server_file;
    std::fstream client_one_file;
    std::string message;
    int previous_client_one_file_size = 0;
    int current_client_one_file_size = 0;

    while (!client_one.isWindowClosed())
    {
        {

            /*Opening server and client file*/
            client_one_file.open(CLIENT_ONE_FILE, std::ios::in);
            server_file.open(SERVER_FILE, std::ios::out);

            /*Getting the total charcter of the file*/
            client_one_file.seekg(0, std::ios::end);

            /*Updating the value of file size*/
            previous_client_one_file_size = current_client_one_file_size;
            current_client_one_file_size = client_one_file.tellg();

            /*Server File*/
            if (server_file)
            {

                server_file << "CALLC2" << std::endl;

                server_file.close();
            }
            else
            {
                std::cout << "Server file doesn't exist";
            }

            /*Client File*/
            if (client_one_file)
            {
                if (previous_client_one_file_size != current_client_one_file_size)
                {
                    /*Resetting the file pointer*/
                    client_one_file.seekg(0, std::ios::beg);

                    /*Reading the content of the file*/
                    getline(client_one_file, message);

                    /*Handling based on the message*/
                    if (message == "INCOMING CALL")
                    {
                        /*Show incoming call screen*/
                    }
                }

                /*Erase Everything*/
                client_one_file.close();
                client_one_file.open(CLIENT_ONE_FILE, std::ios::out);

                client_one_file << "";
                client_one_file.close();
            }
        }

        while (SDL_PollEvent(&e) != 0)
        {
            client_one.handleEvent(e);

            /*It is used to communicate with server*/
        }

        client_one.clear({125, 234, 254, 164});
        client_one.present();
    }

    return 0;
}
