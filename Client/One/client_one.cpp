#include <iostream>
#include <fstream>
#include <string>

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

                        /*Start incoming call time*/
                        client_one.startIncomingCallTime();
                    }
                    else if (message == "CALLDECLINEDFROMCLIENTTWO")
                    {
                        /*Set the screen to call declined*/
                        client_one.setScreen(CALL_REJECTED);

                        /*Stop the outgoing call Tone*/
                        client_one.stopOutgoingTone();

                        /*Stop the outgoing call time*/
                        client_one.endOutgoingCallTime();

                        /*Play the busy tone*/
                        client_one.playBusyTone();
                    }
                    else if (message == "CALLRECEIVEDFROMCLIENTTWO")
                    {
                        /*Client two has receive our call*/
                        client_one.setScreen(CALL_CONNECTED);

                        /*Set the name of person who is calling*/
                        client_one.setCallingPersonName("Client Two");

                        /*Stop the outgoing call tone*/
                        client_one.stopOutgoingTone();

                        /*Stop outgoing call time*/
                        client_one.endOutgoingCallTime();

                        /*Start call time connected*/
                        client_one.startCallConnectedTime();
                    }
                    else if (message == "CALLENDEDFROMCLIENTTWO")
                    {
                        /*Call had been ended by client two*/
                        client_one.setScreen(DIALPAD); /*Later on we will display sth like money deducted*/

                        /*Reset the calling person name*/
                        client_one.setCallingPersonName(" ");

                        /*Stop the ringtone*/
                        client_one.stopRingtone();

                        /*Reset the call connected time*/
                        client_one.resetCallConnectedTime();
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

                    /*Start the outgoing call time*/
                    client_one.startOutgoingCallTime();

                    /*Resetting dialpad number status after we press calling green button*/
                    client_one.resetDialNumber();
                }

                /*1 number is clicked*/
                if ((x >= 63 && x <= 120) && (y >= 160 && y <= 210))
                {
                    client_one.appendDialNumber("1");
                    client_one.playDialpadTone(1);
                }

                /*2 number is clicked*/
                if ((x >= 180 && x <= 235) && (y >= 155 && y <= 205))
                {
                    client_one.appendDialNumber("2");
                    client_one.playDialpadTone(2);
                }

                /*3 number is clicked*/
                if (x >= 295 && x <= 350 && y >= 160 && y <= 205)
                {
                    client_one.appendDialNumber("3");
                    client_one.playDialpadTone(3);
                }

                /*4 number is clicked*/
                if (x >= 65 && x <= 120 && y >= 265 && y <= 315)
                {
                    client_one.appendDialNumber("4");
                    client_one.playDialpadTone(4);
                }

                /*5 number is clicked*/
                if (x >= 180 && x <= 235 && y >= 260 && y <= 315)
                {
                    client_one.appendDialNumber("5");
                    client_one.playDialpadTone(5);
                }

                /*6 number is clicked*/
                if (x >= 300 && x <= 355 && y >= 265 && y <= 315)
                {
                    client_one.appendDialNumber("6");
                    client_one.playDialpadTone(6);
                }

                /*7 number is clicked*/
                if (x >= 65 && x <= 120 && y >= 375 && y <= 425)
                {
                    client_one.appendDialNumber("7");
                    client_one.playDialpadTone(7);
                }

                /*8 number is clicked*/
                if (x >= 180 && x <= 235 && y >= 375 && y <= 425)
                {
                    client_one.appendDialNumber("8");
                    client_one.playDialpadTone(8);
                }

                /*9 number is clicked*/
                if (x >= 295 && x <= 350 && y >= 380 && y <= 425)
                {
                    client_one.appendDialNumber("9");
                    client_one.playDialpadTone(9);
                }

                /* 0 number is clicked*/
                if (x >= 180 && x <= 235 && y >= 485 && y <= 531)
                {
                    client_one.appendDialNumber("0");
                    client_one.playDialpadTone(0);
                }
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

                    /*Stop the count of outgoing call*/
                    client_one.endOutgoingCallTime();

                    /*Stop the busy tone(if there is )*/
                    client_one.stopBusyTone();
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

                    /*Stop incoming call time*/
                    client_one.endIncomingCallTime();
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

                    /*Stop incoming call time*/
                    client_one.endIncomingCallTime();
                }
            }

            /*Call get Connected with another client*/
            else if (e.type == SDL_MOUSEBUTTONDOWN && client_one.getScreen() == CALL_CONNECTED)
            {
                /*Getting the position of the place where we have click on the window*/
                int x, y;
                SDL_GetMouseState(&x, &y);

                /*End button is pressed*/
                if (x >= 179 && x <= 235 && y >= 544 && y <= 597)
                {

                    /*Play the end call tone*/
                    client_one.playEndCallTone();

                    /*Program is delay so the we can end call tone running finish in other thread*/
                    SDL_Delay(1200);

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

            /*Call Rejected*/
            else if (e.type == SDL_MOUSEBUTTONDOWN && client_one.getScreen() == CALL_REJECTED)
            {
                /*Getting the position of the place where we have click on the window*/
                int x, y;
                SDL_GetMouseState(&x, &y);

                /*End button is pressed*/
                if (x >= 179 && x <= 235 && y >= 544 && y <= 597)
                {

                    /*Display the calling screen*/
                    client_one.setScreen(DIALPAD);

                    /*Stop the busy tone(if there is )*/
                    client_one.stopBusyTone();
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
