#include <iostream>
#include <fstream>

#include "window.hpp"
#include "phone.hpp"

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
    Window window("Client One");
    Phone client_one(window, "Client One");
    SDL_Event e;

    while (!window.isWindowClosed())
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
                    if (message == "CALLFROMCLIENTTWO")
                    {
                        /*Show incoming call screen*/
                        client_one.setScreen(INCOMING_CALL);

                        /*Set the name of person who have called*/
                        client_one.setCallingPersonName("Client Two");

                        /*Play the incoming call sound*/
                        client_one.playRingtone();
                    }
                    else if (message == "CALLDECLINEDFROMCLIENTTWO")
                    {
                        /*Client Two has reject our call*/
                        client_one.setScreen(DIALPAD); // Later on we will say to user sth like besta xa

                        client_one.stopOutgoingTone();
                    }
                    else if (message == "CALLRECEIVEDFROMCLIENTTWO")
                    {
                        /*Client two has receive our call*/
                        client_one.setScreen(CALL_CONNECTED); /*later it will be replaced by received call screen*/

                        client_one.setCallingPersonName("Client Two");

                        client_one.stopOutgoingTone();
                    }
                    else if (message == "CALLENDEDFROMCLIENTTWO")
                    {
                        /*Call had been ended by client two*/
                        client_one.setScreen(DIALPAD); /*Later on we will display sth like money deducted*/

                        client_one.setCallingPersonName("");

                        client_one.stopRingtone();
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
            window.handleEvent(e);

            /*Dialpad Section*/
            if (e.type == SDL_MOUSEBUTTONDOWN && client_one.getScreen() == DIALPAD)
            {
                /*Getting the position of the place where we have click on the window*/
                int x, y;
                SDL_GetMouseState(&x, &y);

                /*Call button is pressed*/
                if (x >= 179 && x <= 238 && y >= 594 && y <= 648)
                {
                    /*Print in server file that i want to call client two*/
                    server_file.open(SERVER_FILE, std::ios::out);
                    if (server_file)
                    {
                        server_file << "CALLCLIENTTWO" << std::endl;
                    }
                    else
                    {
                        std::cout << "Server file doesn't exist";
                    }
                    server_file.close();

                    /*Set the name of the person calling*/
                    client_one.setCallingPersonName("Client Two");

                    /*Display the calling screen*/
                    client_one.setScreen(OUTGOING_CALL);

                    /*Play outgoing call sound*/
                    client_one.playOutgoingTone();
                }

                /*0 number is clicked*/
                // Print the number that is being clicked
                // Play the sound of respect number

                /*1 number is clicked*/
                // Print the number that is being clicked
                // Play the sound of respect number

                /*2 number is clicked*/
                // Print the number that is being clicked
                // Play the sound of respect number

                /*3 number is clicked*/
                // Print the number that is being clicked
                // Play the sound of respect number

                /*4 number is clicked*/
                // Print the number that is being clicked
                // Play the sound of respect number

                /*5 number is clicked*/
                // Print the number that is being clicked
                // Play the sound of respect number

                /*6 number is clicked*/
                // Print the number that is being clicked
                // Play the sound of respect number

                /*7 number is clicked*/
                // Print the number that is being clicked
                // Play the sound of respect number

                /*8 number is clicked*/
                // Print the number that is being clicked
                // Play the sound of respect number

                /*9 number is clicked*/
                // Print the number that is being clicked
                // Play the sound of respect number
            }

            /*Outgoing Call*/
            else if (e.type == SDL_MOUSEBUTTONDOWN && client_one.getScreen() == OUTGOING_CALL)
            {
                /*Getting the position of the place where we have click on the window*/
                int x, y;
                SDL_GetMouseState(&x, &y);

                /*End button is pressed*/
                if (x >= 179 && x <= 235 && y >= 544 && y <= 597)
                {
                    /*Print in server file that i want to end call with client two*/
                    server_file.open(SERVER_FILE, std::ios::out);
                    if (server_file)
                    {
                        server_file << "CALLENDEDBYCLIENTONE" << std::endl;
                    }
                    else
                    {
                        std::cout << "Server file doesn't exist";
                    }
                    server_file.close();

                    /*Display the calling screen*/
                    client_one.setScreen(DIALPAD);

                    /*Stop the outgoing call tone*/
                    client_one.stopOutgoingTone();
                }
            }

            /*Incoming Call*/
            else if (e.type == SDL_MOUSEBUTTONDOWN && client_one.getScreen() == INCOMING_CALL)
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

                        server_file << "CALLDECLINEDBYCLIENTONE" << std::endl;
                    }
                    else
                    {
                        std::cout << "Server file doesn't exist";
                    }
                    server_file.close();

                    client_one.setCallingPersonName(" ");

                    /*Display the calling screen*/
                    client_one.setScreen(DIALPAD);

                    /*Stop the ringtone*/
                    client_one.stopRingtone();
                }

                /*Receive button is pressed*/
                if (x >= 280 && x <= 344 && y >= 543 && y <= 593)
                {
                    /*Print in server file that i want to end call with client two*/
                    server_file.open(SERVER_FILE, std::ios::out);
                    if (server_file)
                    {

                        server_file << "CALLRECEIVEDBYCLIENTONE" << std::endl;

                        server_file.close();
                    }
                    else
                    {
                        std::cout << "Server file doesn't exist";
                    }

                    client_one.setCallingPersonName("Client Two");

                    /*Display the calling screen*/
                    client_one.setScreen(CALL_CONNECTED);

                    /*Stop the ringtone*/
                    client_one.stopRingtone();
                }
            }

            else if (e.type == SDL_MOUSEBUTTONDOWN && client_one.getScreen() == CALL_CONNECTED)
            {
                /*Getting the position of the place where we have click on the window*/
                int x, y;
                SDL_GetMouseState(&x, &y);

                /*End button is pressed*/
                if (x >= 179 && x <= 235 && y >= 544 && y <= 597)
                {
                    /*Print in server file that i want to end call with client two*/
                    server_file.open(SERVER_FILE, std::ios::out);
                    if (server_file)
                    {

                        server_file << "CALLENDEDBYCLIENTONE" << std::endl;
                    }
                    else
                    {
                        std::cout << "Server file doesn't exist";
                    }
                    server_file.close();

                    /*Display the calling screen*/
                    client_one.setScreen(DIALPAD);
                }
            }
        }

        /*Clear the window with the color provided*/
        window.clear({125, 234, 254, 164});

        client_one.render(window);

        /*Render all the context we have written in background in the window*/
        window.present();
    }

    return 0;
}
