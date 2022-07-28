#include <iostream>
#include "window.hpp"
#include <fstream>
#include "texture.hpp"

#define SERVER_FILE "Server/server.txt"
#define CLIENT_ONE_FILE "Client/One/client_one.txt"

int main(int argc, char const *argv[])
{

    /*Variable required for communication with server*/
    std::fstream server_file;
    std::fstream client_one_file;
    std::string message;
    int previous_client_one_file_size = 0;
    int current_client_one_file_size = 0;

    /*Variable used by Client One GUI*/
    SDL_Event e;
    Window client_one("Client One");

    Texture dialpad_screen;
    Texture outgoing_call;
    Texture incoming_call;

    /*Loading the image that are required*/
    dialpad_screen.loadFromFile(client_one, "resources/images/dial_pad.png");
    ~outgoing_call.loadFromFile(client_one, "resources/images/outgoing_call.png");
    incoming_call.loadFromFile(client_one, "resources/images/incoming_call.png");

    while (!client_one.isWindowClosed())
    {

        /*This is for communication with other client via server. I will work over it later on*/
        {
            /*Opening server and client file*/
            client_one_file.open(CLIENT_ONE_FILE, std::ios::in);

            /*Getting the total charcter of the file*/
            client_one_file.seekg(0, std::ios::end);

            /*Updating the value of file size*/
            previous_client_one_file_size = current_client_one_file_size;
            current_client_one_file_size = client_one_file.tellg();

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
                        client_one.screen = INCOMING_CALL;
                    }
                }

                /*Erase Everything*/
                client_one_file.close();
                client_one_file.open(CLIENT_ONE_FILE, std::ios::out);

                client_one_file << "";
                client_one_file.close();
            }
        }

        /*Handle the events*/
        while (SDL_PollEvent(&e) != 0)
        {
            /*Handle the event related to window*/
            client_one.handleEvent(e);

            if (e.type == SDL_MOUSEBUTTONDOWN && client_one.screen == DIALPAD)
            {
                /*Getting the position of the place where we have click on the window*/
                int x, y;
                SDL_GetMouseState(&x, &y);

                /*Call button maximum square coordinate checking*/
                if (x >= 179 && x <= 238 && y >= 594 && y <= 648)
                {
                    /*Print in server file that i want to call client two*/
                    server_file.open(SERVER_FILE, std::ios::out);
                    if (server_file)
                    {

                        server_file << "CALLCLIENTTWO" << std::endl;

                        server_file.close();
                    }
                    else
                    {
                        std::cout << "Server file doesn't exist";
                    }

                    /*Display the calling screen*/
                    client_one.screen = OUTGOING_CALL;
                }
            }
            if (e.type == SDL_MOUSEBUTTONDOWN && client_one.screen == OUTGOING_CALL)
            {
                /*Getting the position of the place where we have click on the window*/
                int x, y;
                SDL_GetMouseState(&x, &y);

                /*End button maximum square coordinate checking*/
                if (x >= 179 && x <= 235 && y >= 544 && y <= 597)
                {
                    /*Print in server file that i want to edn call with client two*/
                    server_file.open(SERVER_FILE, std::ios::out);
                    if (server_file)
                    {

                        server_file << "ENDCALLCLIENTTWO" << std::endl;
                    }
                    else
                    {
                        std::cout << "Server file doesn't exist";
                    }
                    server_file.close();

                    /*Display the calling screen*/
                    client_one.screen = DIALPAD;
                }
            }
            if (e.type == SDL_MOUSEBUTTONDOWN && client_one.screen == INCOMING_CALL)
            {
                /*Getting the position of the place where we have click on the window*/
                int x, y;
                SDL_GetMouseState(&x, &y);

                /*End button is pressed*/
                if (x >= 74 && x <= 134 && y >= 543 && y <= 593)
                {
                    /*Print in server file that i want to end call with client two*/
                    server_file.open(SERVER_FILE, std::ios::out);
                    if (server_file)
                    {

                        server_file << "ENDCALLCLIENTTWO" << std::endl;
                    }
                    else
                    {
                        std::cout << "Server file doesn't exist";
                    }
                    server_file.close();

                    /*Display the calling screen*/
                    client_one.screen = DIALPAD;
                }

                /*Receive button is pressed*/
                if (x >= 280 && x <= 344 && y >= 543 && y <= 593)
                {
                    /*Print in server file that i want to end call with client two*/
                    server_file.open(SERVER_FILE, std::ios::out);
                    // if (server_file)
                    // {

                    //     server_file << "ENDCALLCLIENTTWO" << std::endl;

                    //     server_file.close();
                    // }
                    // else
                    // {
                    //     std::cout << "Server file doesn't exist";
                    // }

                    /*Display the calling screen*/
                    client_one.screen = OUTGOING_CALL;
                }
            }
        }

        /*Clear the window with the color provided*/
        client_one.clear({125, 234, 254, 164});

        /*Show the dialpad screen*/
        if (client_one.screen == DIALPAD)
        {
            dialpad_screen.render(client_one, 0, 0, nullptr, nullptr);
        }
        /*Show the outgoing call screen*/
        else if (client_one.screen == OUTGOING_CALL)
        {
            outgoing_call.render(client_one, 0, 0, nullptr, nullptr);
        }
        /*Show the incoming call screen*/
        else if (client_one.screen == INCOMING_CALL)
        {
            incoming_call.render(client_one, 0, 0, nullptr, nullptr);
        }

        /*Render all the context we have written in background in the window*/
        client_one.present();
    }

    return 0;
}
