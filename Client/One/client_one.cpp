#include <iostream>
#include <fstream>
#include <string>

#include "Client/window.hpp"
#include "Client/phone.hpp"

#define SERVER_FILE "Server/server.txt"
#define CLIENT_ONE_FILE "Client/One/client_one.txt"

int main(int argc, char const *argv[])
{

    /*Variable used by Client One GUI*/
    Window window("Client One");
    Phone client_one(window, "Client One");
    client_one.setClientFilePath(CLIENT_ONE_FILE);
    SDL_Event e;

    while (!window.isWindowClosed())
    {

        /*Runs if the size of the file has been changed or not*/
        if (client_one.isClientFileSizeChanged())
        {
            /*Receive the message that has been send by the server*/
            std::string message_from_server = client_one.receiveMessageFromServer();

            /*Processing the message that has been send by the server*/
            if (message_from_server == "CALLFROMCLIENTTWO")
            {
                /*Show incoming call screen*/
                client_one.setCurrentScreen(INCOMING_CALL);

                /*Set the name of person who have called*/
                client_one.setCallingPersonName("Client Two");

                /*Play the incoming call sound*/
                client_one.playRingtone();

                /*Start incoming call time*/
                client_one.startIncomingCallTime();
            }
            else if (message_from_server == "CALLDECLINEDFROMCLIENTTWO")
            {
                /*Set the screen to call declined*/
                client_one.setCurrentScreen(CALL_REJECTED);

                /*Stop the outgoing call Tone*/
                client_one.stopOutgoingTone();

                /*Stop the outgoing call time*/
                client_one.endOutgoingCallTime();

                /*Play the busy tone*/
                client_one.playBusyTone();
            }
            else if (message_from_server == "CALLRECEIVEDFROMCLIENTTWO")
            {
                /*Client two has receive our call*/
                client_one.setCurrentScreen(CALL_CONNECTED);

                /*Set the name of person who is calling*/
                client_one.setCallingPersonName("Client Two");

                /*Stop the outgoing call tone*/
                client_one.stopOutgoingTone();

                /*Stop outgoing call time*/
                client_one.endOutgoingCallTime();
            }
            else if (message_from_server == "CALLENDEDFROMCLIENTTWO")
            {
                /*Call had been ended by client two*/
                client_one.setCurrentScreen(CALL_ENDED); /*Later on we will display sth like money deducted*/

                /*Stop the ringtone*/
                client_one.stopRingtone();
            }
            else if (message_from_server == "AUDIOMESSAGESENDFROMCLIENTTWO")
            {
                client_one.setCallConnectedStatus(CALLCONNECTEDPLAYING);

                client_one.setCallConnectedRecordingStatus(PLAYING);

                client_one.startPlayingAudioMessage();
            }
        }

        /*Clear the content of the file*/
        client_one.clearFileContent();

        /*Handle the events*/
        while (SDL_PollEvent(&e) != 0)
        {
            /*Handle the event related to window*/
            window.handleEvent(e);

            /*Dialpad Section*/
            if (e.type == SDL_MOUSEBUTTONDOWN && client_one.getCurrentScreen() == DIALPAD)
            {
                /*Getting the position of the place where we have click on the window*/
                int x, y;
                SDL_GetMouseState(&x, &y);

                /*Call button is pressed*/
                if (x >= 179 && x <= 238 && y >= 594 && y <= 648)
                {

                    if ( client_one.getDialNumber() == " 2222222222" )
                    {
                        /*Sending server to call client two*/
                        client_one.sendMessageToServer("CALLCLIENTTWO1111111111");

                        /*Set the name of the person calling*/
                        client_one.setCallingPersonName("Client Two");
                       
                        /*Display the calling screen*/
                        client_one.setCurrentScreen(OUTGOING_CALL);

                        /*Play outgoing call sound*/
                        client_one.playOutgoingTone();

                        /*Start the outgoing call time*/
                        client_one.startOutgoingCallTime();
                    }
                        /*Resetting dialpad number status after we press calling green button*/
                        client_one.resetDialNumber();

                }

                /* Section for back press in dial pad */
                if ((x >= 300 && x <= 350) && (y >= 610 && y <= 635))
                {
                    client_one.removeOneDialNumber();
                }

                /*1 number is clicked*/
                else if ((x >= 63 && x <= 120) && (y >= 160 && y <= 210))
                {
                    client_one.appendDialNumber("1");
                    client_one.playDialpadTone(1);
                }

                /*2 number is clicked*/
                else if ((x >= 180 && x <= 235) && (y >= 155 && y <= 205))
                {
                    client_one.appendDialNumber("2");
                    client_one.playDialpadTone(2);
                }

                /*3 number is clicked*/
                else if (x >= 295 && x <= 350 && y >= 160 && y <= 205)
                {
                    client_one.appendDialNumber("3");
                    client_one.playDialpadTone(3);
                }

                /*4 number is clicked*/
                else if (x >= 65 && x <= 120 && y >= 265 && y <= 315)
                {
                    client_one.appendDialNumber("4");
                    client_one.playDialpadTone(4);
                }

                /*5 number is clicked*/
                else if (x >= 180 && x <= 235 && y >= 260 && y <= 315)
                {
                    client_one.appendDialNumber("5");
                    client_one.playDialpadTone(5);
                }

                /*6 number is clicked*/
                else if (x >= 300 && x <= 355 && y >= 265 && y <= 315)
                {
                    client_one.appendDialNumber("6");
                    client_one.playDialpadTone(6);
                }

                /*7 number is clicked*/
                else if (x >= 65 && x <= 120 && y >= 375 && y <= 425)
                {
                    client_one.appendDialNumber("7");
                    client_one.playDialpadTone(7);
                }

                /*8 number is clicked*/
                else if (x >= 180 && x <= 235 && y >= 375 && y <= 425)
                {
                    client_one.appendDialNumber("8");
                    client_one.playDialpadTone(8);
                }

                /*9 number is clicked*/
                else if (x >= 295 && x <= 350 && y >= 380 && y <= 425)
                {
                    client_one.appendDialNumber("9");
                    client_one.playDialpadTone(9);
                }

                /* 0 number is clicked*/
                else if (x >= 180 && x <= 235 && y >= 485 && y <= 531)
                {
                    client_one.appendDialNumber("0");
                    client_one.playDialpadTone(0);
                }
            }

            /*Outgoing Call*/
            else if (e.type == SDL_MOUSEBUTTONDOWN && client_one.getCurrentScreen() == OUTGOING_CALL)
            {
                /*Getting the position of the place where we have click on the window*/
                int x, y;
                SDL_GetMouseState(&x, &y);

                /*End button is pressed*/
                if (x >= 179 && x <= 235 && y >= 544 && y <= 597)
                {
                    /*Sending server that the call has been ended*/
                    client_one.sendMessageToServer("CALLENDEDBYCLIENTONE");

                    /*Display the calling screen*/
                    client_one.setCurrentScreen(CALL_ENDED);

                    /*Stop the outgoing call tone*/
                    client_one.stopOutgoingTone();

                    /*Stop the count of outgoing call*/
                    client_one.endOutgoingCallTime();

                    /*Stop the busy tone(if there is )*/
                    client_one.stopBusyTone();

                    /*Play end call tone*/
                    client_one.playEndCallTone();
                }
            }

            /*Incoming Call*/
            else if (e.type == SDL_MOUSEBUTTONDOWN && client_one.getCurrentScreen() == INCOMING_CALL)
            {
                /*Getting the position of the place where we have click on the window*/
                int x, y;
                SDL_GetMouseState(&x, &y);

                /*End button is pressed*/
                if (x >= 74 && x <= 134 && y >= 543 && y <= 593)
                {
                    /*Sending server that call has been declined*/
                    client_one.sendMessageToServer("CALLDECLINEDBYCLIENTONE");

                    client_one.setCallingPersonName(" ");

                    /*Display the calling screen*/
                    client_one.setCurrentScreen(DIALPAD);

                    /*Stop the ringtone*/
                    client_one.stopRingtone();

                    /*Stop incoming call time*/
                    client_one.endIncomingCallTime();
                }

                /*Receive button is pressed*/
                if (x >= 280 && x <= 344 && y >= 543 && y <= 593)
                {
                    /*Sending server that  call has been recieved*/
                    client_one.sendMessageToServer("CALLRECEIVEDBYCLIENTONE");

                    client_one.setCallingPersonName("Client Two");

                    /*Display the calling screen*/
                    client_one.setCurrentScreen(CALL_CONNECTED);

                    /*Stop the ringtone*/
                    client_one.stopRingtone();

                    /*Stop incoming call time*/
                    client_one.endIncomingCallTime();
                }
            }

            /*Call get Connected with another client*/
            else if ((e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_KEYDOWN) && client_one.getCurrentScreen() == CALL_CONNECTED)
            {
                int x, y;
                SDL_GetMouseState(&x, &y);

                if (e.type == SDL_MOUSEBUTTONDOWN)
                {
                    /*End button is pressed*/
                    if (x >= 179 && x <= 235 && y >= 544 && y <= 597)
                    {
                        /*Sending message to server that call has been ended*/
                        client_one.sendMessageToServer("CALLENDEDBYCLIENTONE");

                        /*Display the calling screen*/
                        client_one.setCurrentScreen(CALL_ENDED);

                        /*Playing End Call Tone*/
                        client_one.playEndCallTone();
                    }
                }
                if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN)
                {
                    if ((e.key.keysym.sym == SDLK_r || (x >= 62 && x <= 120 && y >= 240 && y <= 297)) && client_one.getCallConnectedRecordingStatus() == NONE)
                    {
                        client_one.setCallConnectedStatus(CALLCONNECTEDRECORDING);

                        client_one.startRecordingAudioMessage();
                        client_one.setCallConnectedRecordingStatus(AudioRecordingStatus::RECORDING);
                    }
                    else if ((e.key.keysym.sym == SDLK_s || (x >= 291 && x <= 355 && y >= 247 && y <= 297)) && client_one.getCallConnectedRecordingStatus() == NONE)
                    {
                        client_one.setCallConnectedStatus(CALLCONNECTEDSENDING);

                        client_one.sendMessageToServer("AUDIOMESSAGESENDBYCLIENTONE");

                        client_one.setCallConnectedRecordingStatus(AudioRecordingStatus::SENDING);
                    }
                }
            }

            /*Call Rejected*/
            else if (e.type == SDL_MOUSEBUTTONDOWN && client_one.getCurrentScreen() == CALL_REJECTED)
            {
                /*Getting the position of the place where we have click on the window*/
                int x, y;
                SDL_GetMouseState(&x, &y);

                /*End button is pressed*/
                if (x >= 179 && x <= 235 && y >= 544 && y <= 597)
                {

                    /*Display the calling screen*/
                    client_one.setCurrentScreen(DIALPAD);

                    /*Stop the busy tone(if there is )*/
                    client_one.stopBusyTone();
                }
            }
        }

        /*Clear the window with the color provided*/
        window.clear({0, 255, 0, 255});

        client_one.render(window);

        /*Render all the context we have written in background in the window*/
        window.present();

        /*This is used to render the CALL_ENDED screen so that call end tone get played*/
        if (client_one.getCurrentScreen() == CALL_ENDED)
        {
            SDL_Delay(1500);

            client_one.setCurrentScreen(DIALPAD);
        }
    }

    return 0;
}
