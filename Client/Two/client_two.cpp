#include <iostream>
#include <fstream>

#include "window.hpp"
#include "phone.hpp"
#include "clientfile.hpp"

#define SERVER_FILE "Server/server.txt"
#define CLIENT_TWO_FILE "Client/Two/client_two.txt"

int main(int argc, char const *argv[])
{
    /*Variable used by Client One GUI*/
    Window window("Client Two");
    Phone client_two(window, "Client Two");
    ClientFile client_two_file(CLIENT_TWO_FILE);
    SDL_Event e;

    while (!window.isWindowClosed())
    {
        if (client_two_file.isClientFileSizeChanged())
        {
            /*Receive the message that has been send by the server*/
            std::string message_from_server = client_two_file.receiveMessageFromServer();

            /*Processing the message that has been send by the server*/
            if (message_from_server == "CALLFROMCLIENTONE")
            {
                /*Show incoming call screen*/
                client_two.setCurrentScreen(INCOMING_CALL);

                /*Set the name of person who have called*/
                client_two.setCallingPersonName("Client One");

                /*Play the incoming call sound*/
                client_two.playRingtone();

                /*Start incoming call time*/
                client_two.startIncomingCallTime();
            }
            else if (message_from_server == "CALLDECLINEDFROMCLIENTONE")
            {
                /*Client Two has reject our call*/
                client_two.setCurrentScreen(CALL_REJECTED);

                /*Stop the outgoing call Tone*/
                client_two.stopOutgoingTone();

                /*Start the outgoing call time*/
                client_two.startOutgoingCallTime();

                /*Play the busy tone*/
                client_two.playBusyTone();
            }
            else if (message_from_server == "CALLRECEIVEDFROMCLIENTONE")
            {
                /*Client one has receive our call*/
                client_two.setCurrentScreen(CALL_CONNECTED);

                /*Set the name of the person who is calling*/
                client_two.setCallingPersonName("Client One");

                /*Stop the outgoing call tone*/
                client_two.stopOutgoingTone();

                /*Stop the outgoing call time*/
                client_two.endOutgoingCallTime();
            }
            else if (message_from_server == "CALLENDEDFROMCLIENTONE")
            {
                /*Call had been ended by client two*/
                client_two.setCurrentScreen(CALL_ENDED); /*Later on we will display sth like money deducted*/

                /*Stop the ringtone*/
                client_two.stopRingtone();
            }
            else if (message_from_server == "AUDIOMESSAGESENDFROMCLIENTONE")
            {
                client_two.setCallConnectedRecordingStatus(PLAYING);

                client_two.startPlayingAudioMessage();
            }
        }

        /*Handle the events*/
        while (SDL_PollEvent(&e) != 0)
        {
            /*Handle the event related to window*/
            window.handleEvent(e);

            /*Dialpad Section*/
            if (e.type == SDL_MOUSEBUTTONDOWN && client_two.getCurrentScreen() == DIALPAD)
            {
                /*Getting the position of the place where we have click on the window*/
                int x, y;
                SDL_GetMouseState(&x, &y);

                /*Call button is pressed*/
                if (x >= 179 && x <= 238 && y >= 594 && y <= 648)
                {
                    /*Sending server to call client one*/
                    client_two_file.sendMessageToServer("CALLCLIENTONE");

                    client_two.setCallingPersonName("Client One");

                    /*Display the calling screen*/
                    client_two.setCurrentScreen(OUTGOING_CALL);

                    /*Play outgoing call sound*/
                    client_two.playOutgoingTone();

                    /*Start the outgoing call time*/
                    client_two.startOutgoingCallTime();

                    /*Resetting dialpad number status after we press calling green button*/
                    client_two.resetDialNumber();
                }

                /* Section for back press in dial pad */
                if ((x >= 300 && x <= 350) && (y >= 610 && y <= 635))
                {
                    client_two.removeOneDialNumber();
                }

                /*1 number is clicked*/
                else if ((x >= 63 && x <= 120) && (y >= 160 && y <= 210))
                {
                    client_two.appendDialNumber("1");
                    client_two.playDialpadTone(1);
                }

                /*2 number is clicked*/
                else if ((x >= 180 && x <= 235) && (y >= 155 && y <= 205))
                {
                    client_two.appendDialNumber("2");
                    client_two.playDialpadTone(2);
                }

                /*3 number is clicked*/
                else if (x >= 295 && x <= 350 && y >= 160 && y <= 205)
                {
                    client_two.appendDialNumber("3");
                    client_two.playDialpadTone(3);
                }

                /*4 number is clicked*/
                else if (x >= 65 && x <= 120 && y >= 265 && y <= 315)
                {
                    client_two.appendDialNumber("4");
                    client_two.playDialpadTone(4);
                }

                /*5 number is clicked*/
                else if (x >= 180 && x <= 235 && y >= 260 && y <= 315)
                {
                    client_two.appendDialNumber("5");
                    client_two.playDialpadTone(5);
                }

                /*6 number is clicked*/
                else if (x >= 300 && x <= 355 && y >= 265 && y <= 315)
                {
                    client_two.appendDialNumber("6");
                    client_two.playDialpadTone(6);
                }

                /*7 number is clicked*/
                else if (x >= 65 && x <= 120 && y >= 375 && y <= 425)
                {
                    client_two.appendDialNumber("7");
                    client_two.playDialpadTone(7);
                }

                /*8 number is clicked*/
                else if (x >= 180 && x <= 235 && y >= 375 && y <= 425)
                {
                    client_two.appendDialNumber("8");
                    client_two.playDialpadTone(8);
                }

                /*9 number is clicked*/
                else if (x >= 295 && x <= 350 && y >= 380 && y <= 425)
                {
                    client_two.appendDialNumber("9");
                    client_two.playDialpadTone(9);
                }

                /* 0 number is clicked*/
                else if (x >= 180 && x <= 235 && y >= 485 && y <= 531)
                {
                    client_two.appendDialNumber("0");
                    client_two.playDialpadTone(0);
                }
            }

            /*Outgoing Call*/
            else if (e.type == SDL_MOUSEBUTTONDOWN && client_two.getCurrentScreen() == OUTGOING_CALL)
            {
                /*Getting the position of the place where we have click on the window*/
                int x, y;
                SDL_GetMouseState(&x, &y);

                /*End button is pressed*/
                if (x >= 179 && x <= 235 && y >= 544 && y <= 597)
                {
                    /*Sending server that the call has been ended*/
                    client_two_file.sendMessageToServer("CALLENDEDBYCLIENTTWO");

                    /*Display the calling screen*/
                    client_two.setCurrentScreen(CALL_ENDED);

                    /*Stop the outgoing call tone*/
                    client_two.stopOutgoingTone();

                    /*Stop the count of outgoing call*/
                    client_two.endOutgoingCallTime();

                    /*Stop the busy tone(if there is )*/
                    client_two.stopBusyTone();

                    /*Play end call tone*/
                    client_two.playEndCallTone();
                }
            }
            /*Incoming Call*/
            else if (e.type == SDL_MOUSEBUTTONDOWN && client_two.getCurrentScreen() == INCOMING_CALL)
            {
                /*Getting the position of the place where we have click on the window*/
                int x, y;
                SDL_GetMouseState(&x, &y);

                /*End button is pressed*/
                if (x >= 74 && x <= 134 && y >= 543 && y <= 593)
                {
                    /*Sending server that call has been declined*/
                    client_two_file.sendMessageToServer("CALLDECLINEDBYCLIENTTWO");

                    client_two.setCallingPersonName(" ");

                    /*Display the calling screen*/
                    client_two.setCurrentScreen(DIALPAD);

                    /*Stop the ringtone*/
                    client_two.stopRingtone();

                    /*Stop the incoming call time*/
                    client_two.endIncomingCallTime();
                }

                /*Receive button is pressed*/
                if (x >= 280 && x <= 344 && y >= 543 && y <= 593)
                {
                    /*Sending server that  call has been recieved*/
                    client_two_file.sendMessageToServer("CALLRECEIVEDBYCLIENTTWO");

                    client_two.setCallingPersonName("Client One");

                    /*Display the calling screen*/
                    client_two.setCurrentScreen(CALL_CONNECTED);

                    /*Stop the ringtone*/
                    client_two.stopRingtone();

                    /*Stop the incoming call time*/
                    client_two.endIncomingCallTime();
                }
            }

            /*Call get Connected with another client*/
            else if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_KEYDOWN && client_two.getCurrentScreen() == CALL_CONNECTED)
            {
                /*Getting the position of the place where we have click on the window*/
                int x, y;
                SDL_GetMouseState(&x, &y);

                /*End button is pressed*/
                if (x >= 179 && x <= 235 && y >= 544 && y <= 597)
                {
                    /*Sending message to server that call has been ended*/
                    client_two_file.sendMessageToServer("CALLENDEDBYCLIENTTWO");

                    /*Display the calling screen*/
                    client_two.setCurrentScreen(CALL_ENDED);

                    client_two.playEndCallTone();
                }

                if (e.type == SDL_KEYDOWN)
                {
                    if (e.key.keysym.sym == SDLK_r)
                    {
                        client_two.startRecordingAudioMessage();
                        client_two.setCallConnectedRecordingStatus(AudioRecordingStatus::RECORDING);
                    }
                    else if (e.key.keysym.sym == SDLK_s)
                    {
                        client_two_file.sendMessageToServer("AUDIOMESSAGESENDBYCLIENTTWO");

                        client_two.setCallConnectedRecordingStatus(AudioRecordingStatus::SENDING);
                    }
                }
            }

            /*Call Rejected*/
            else if (e.type == SDL_MOUSEBUTTONDOWN && client_two.getCurrentScreen() == CALL_REJECTED)
            {
                /*Getting the position of the place where we have click on the window*/
                int x, y;
                SDL_GetMouseState(&x, &y);

                /*End button is pressed*/
                if (x >= 179 && x <= 235 && y >= 544 && y <= 597)
                {
                    /*Display the calling screen*/
                    client_two.setCurrentScreen(DIALPAD);

                    /*Stop the busy tone(if there is )*/
                    client_two.stopBusyTone();
                }
            }
        }

        /*Clear the window with the color provided*/

        window.clear({237, 5, 206, 200});

        client_two.render(window);

        /*Render all the context we have written in background in the window*/
        window.present();

        /*This is used to render the CALL_ENDED screen so that call end tone get played*/
        if (client_two.getCurrentScreen() == CALL_ENDED)
        {
            SDL_Delay(1500);

            client_two.setCurrentScreen(DIALPAD);
        }
    }

    return 0;
}
