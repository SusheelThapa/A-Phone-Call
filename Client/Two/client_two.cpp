#include <iostream>
#include <fstream>

#include "window.hpp"
#include "phone.hpp"

#define SERVER_FILE "Server/server.txt"
#define CLIENT_TWO_FILE "Client/Two/client_two.txt"

int main(int argc, char const *argv[])
{

    /*Variable required for communication with server*/
    std::fstream server_file;
    std::fstream client_two_file;
    std::string message;
    int previous_client_two_file_size = 0;
    int current_client_two_file_size = 0;

    /*Variable used by Client One GUI*/
    Window window("Client Two");
    Phone client_two(window, "Client Two");
    SDL_Event e;
    std::string NumberString;

    while (!window.isWindowClosed())
    {

        /*This is for communication with other client via server. I will work over it later on*/
        {
            /*Opening server and client file*/
            client_two_file.open(CLIENT_TWO_FILE, std::ios::in);

            /*Getting the total charcter of the file*/
            client_two_file.seekg(0, std::ios::end);

            /*Updating the value of file size*/
            previous_client_two_file_size = current_client_two_file_size;
            current_client_two_file_size = client_two_file.tellg();

            /*Client File*/
            if (client_two_file)
            {
                if (previous_client_two_file_size != current_client_two_file_size)
                {
                    /*Resetting the file pointer*/
                    client_two_file.seekg(0, std::ios::beg);

                    /*Reading the content of the file*/
                    getline(client_two_file, message);

                    /*Handling based on the message*/
                    if (message == "CALLFROMCLIENTONE")
                    {
                        /*Show incoming call screen*/
                        client_two.setScreen(INCOMING_CALL);

                        /*Set the name of person who have called*/
                        client_two.setCallingPersonName("Client One");

                        /*Play the incoming call sound*/
                        client_two.playRingtone();
                    }
                    else if (message == "CALLDECLINEDFROMCLIENTONE")
                    {
                        /*Client Two has reject our call*/
                        client_two.setScreen(DIALPAD); // Later on we will say to user sth like besta xa

                        client_two.stopOutgoingTone();
                    }
                    else if (message == "CALLRECEIVEDFROMCLIENTONE")
                    {
                        /*Client one has receive our call*/
                        client_two.setScreen(CALL_CONNECTED); /*later it will be replaced by received call screen*/

                        client_two.setCallingPersonName("Client One");

                        client_two.stopOutgoingTone();
                    }
                    else if (message == "CALLENDEDFROMCLIENTONE")
                    {
                        /*Call had been ended by client two*/
                        client_two.setScreen(DIALPAD); /*Later on we will display sth like money deducted*/

                        client_two.setCallingPersonName(" ");

                        client_two.stopRingtone();
                    }
                }

                /*Erase Everything*/
                client_two_file.close();
                client_two_file.open(CLIENT_TWO_FILE, std::ios::out);

                client_two_file << "";
                client_two_file.close();
            }
        }

        /*Handle the events*/
        while (SDL_PollEvent(&e) != 0)
        {
            /*Handle the event related to window*/
            window.handleEvent(e);

            /*Dialpad Section*/
            if (e.type == SDL_MOUSEBUTTONDOWN && client_two.getScreen() == DIALPAD)
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
                        server_file << "CALLCLIENTONE" << std::endl;
                    }
                    else
                    {
                        std::cout << "Server file doesn't exist";
                    }
                    server_file.close();

                    client_two.setCallingPersonName("Client One");

                    /*Display the calling screen*/
                    client_two.setScreen(OUTGOING_CALL);

                    /*Play outgoing call sound*/
                    client_two.playOutgoingTone();
                }

               
                /*1 number is clicked*/
                // Print the number that is being clicked
                // Play the sound of respect number
                if ( (x >= 63 && x <= 120) && ( y >= 160 && y <= 210) )
                {
    
                    client_two.playDialpadTone(1);
                }

                /*2 number is clicked*/
                // Print the number that is being clicked
                // Play the sound of respect number

                if ( (x >= 180 && x <= 235 ) && ( y >= 155 && y <= 205) )
                {
 
                    client_two.playDialpadTone(2);
                }

                /*3 number is clicked*/
                // Print the number that is being clicked
                // Play the sound of respect number
                if (x >= 295 && x <= 350 && y >= 160 && y <= 205)
                {
    
                    client_two.playDialpadTone(3);
                }

                /*4 number is clicked*/
                // Print the number that is being clicked
                // Play the sound of respect number
                if (x >= 65 && x <= 120 && y >= 265 && y <= 315)
                {
         
                    client_two.playDialpadTone(4);
                }

                /*5 number is clicked*/
                // Print the number that is being clicked
                // Play the sound of respect number
                if (x >= 180 && x <= 235 && y >= 260 && y <= 315)
                {
           
                    client_two.playDialpadTone(5);
                }

                /*6 number is clicked*/
                // Print the number that is being clicked
                // Play the sound of respect number
                if (x >= 300 && x <= 355 && y >= 265 && y <= 315)
                {
         
                    client_two.playDialpadTone(6);
                }

                /*7 number is clicked*/
                // Print the number that is being clicked
                // Play the sound of respect number
                if (x >= 65 && x <= 120 && y >= 375 && y <= 425)
                {
              
                    client_two.playDialpadTone(7);
                }

                /*8 number is clicked*/
                // Print the number that is being clicked
                // Play the sound of respect number
                if (x >=180  && x <= 235 && y >= 375 && y <= 425 )
                {
              
                    client_two.playDialpadTone(8);
                }

                /*9 number is clicked*/
                // Print the number that is being clicked
                // Play the sound of respect number
                if (x >= 295 && x <= 350 && y >= 380 && y <= 425 )
                {
                
                    client_two.playDialpadTone(9);
                }

                /* * number is clicked*/
                // Print the number that is being clicked
                // Play the sound of respect number
                if (x >= 62 && x <= 120 && y >= 485 && y <= 535 )
                {
  
                }

                /* 0 number is clicked*/
                // Print the number that is being clicked
                // Play the sound of respect number
                if (x >= 180 && x <= 235 && y >= 485 && y <= 531 )
                {
                  
                    client_two.playDialpadTone(0);
                }

                /* # number is clicked*/
                // Print the number that is being clicked
                // Play the sound of respect number
                if (x >= 295 && x <= 350 && y >= 485 && y <= 530 )
                {
                  
                }
            }

            /*Outgoing Call*/
            else if (e.type == SDL_MOUSEBUTTONDOWN && client_two.getScreen() == OUTGOING_CALL)
            {
                /*Getting the position of the place where we have click on the window*/
                int x, y;
                SDL_GetMouseState(&x, &y);

                /*End button is pressed*/
                if (x >= 179 && x <= 235 && y >= 544 && y <= 597)
                {
                    /*Print in server file that i want to edn call with client two*/
                    server_file.open(SERVER_FILE, std::ios::out);
                    if (server_file)
                    {

                        server_file << "CALLENDEDBYCLIENTTWO" << std::endl;
                    }
                    else
                    {
                        std::cout << "Server file doesn't exist";
                    }
                    server_file.close();

                    /*Display the calling screen*/
                    client_two.setScreen(DIALPAD);

                    /*Play outgoing call sound*/
                    client_two.playOutgoingTone();
                }
            }

            /*Incoming Call*/
            else if (e.type == SDL_MOUSEBUTTONDOWN && client_two.getScreen() == INCOMING_CALL)
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

                        server_file << "CALLDECLINEDBYCLIENTTWO" << std::endl;
                    }
                    else
                    {
                        std::cout << "Server file doesn't exist";
                    }
                    server_file.close();

                    client_two.setCallingPersonName(" ");

                    /*Display the calling screen*/
                    client_two.setScreen(DIALPAD);

                    /*Stop the ringtone*/
                    client_two.stopRingtone();
                }

                /*Receive button is pressed*/
                if (x >= 280 && x <= 344 && y >= 543 && y <= 593)
                {
                    /*Print in server file that i want to end call with client two*/
                    server_file.open(SERVER_FILE, std::ios::out);
                    if (server_file)
                    {

                        server_file << "CALLRECEIVEDBYCLIENTTWO" << std::endl;

                        server_file.close();
                    }
                    else
                    {
                        std::cout << "Server file doesn't exist";
                    }

                    client_two.setCallingPersonName("Client One");

                    /*Display the calling screen*/
                    client_two.setScreen(CALL_CONNECTED);

                    /*Stop the ringtone*/
                    client_two.stopRingtone();
                }
            }

            else if (e.type == SDL_MOUSEBUTTONDOWN && client_two.getScreen() == CALL_CONNECTED)
            {
                /*Getting the position of the place where we have click on the window*/
                int x, y;
                SDL_GetMouseState(&x, &y);

                /*End button is pressed*/
                if (x >= 179 && x <= 235 && y >= 544 && y <= 597)
                {

                    std::cout << "End button was pressed";
                    /*Print in server file that i want to edn call with client two*/
                    server_file.open(SERVER_FILE, std::ios::out);
                    if (server_file)
                    {
                        server_file << "CALLENDEDBYCLIENTTWO" << std::endl;
                    }
                    else
                    {
                        std::cout << "Server file doesn't exist";
                    }
                    server_file.close();

                    /*Display the calling screen*/
                    client_two.setScreen(DIALPAD);
                }
            }
        }

        /*Clear the window with the color provided*/
        window.clear({125, 234, 254, 164});

        client_two.render(window);

        /*Render all the context we have written in background in the window*/
        window.present();
    }

    return 0;
}
