#include <iostream>
#include <fstream>

#include "Client/window.hpp"
#include "Client/phone.hpp"

#define SERVER_FILE "Server/server.txt"
#define CLIENT_TWO_FILE "Client/Two/client_two.txt"

int main(int argc, char const *argv[])
{
    /*Variable used by Client One GUI*/
    Window window("Client Two");
    Phone client_two(window, "Client Two");
    client_two.setClientFilePath(CLIENT_TWO_FILE);
    SDL_Event e;

    while (!window.isWindowClosed())
    {
        if (client_two.isClientFileSizeChanged())
        {
            /*Receive the message that has been send by the server*/
            std::string message_from_server = client_two.receiveMessageFromServer();

            /*Processing the message that has been send by the server*/
            if (message_from_server.substr(0, 17) == "CALLFROMCLIENTONE")
            {
                /*Show incoming call screen*/
                client_two.setCurrentScreen(INCOMING_CALL);

                /*Set the name of person who have called*/
                client_two.setCallingPersonName("Client One");

                /*Set the number of calling person*/
                client_two.setCallingPersonNumber(message_from_server.substr(17, 10));

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
            else if (message_from_server == "NUMBERUNMATCHED")
            {
                /*Set the screen to call declined*/
                client_two.setCurrentScreen(NUMBER_UNMATCHED);

                /*Stop the outgoing call Tone*/
                client_two.stopOutgoingTone();

                /*Stop the outgoing call time*/
                client_two.endOutgoingCallTime();

                /*Play the busy tone*/
                client_two.playNumberUnmatchedTone();
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
                client_two.setCallConnectedStatus(CALLCONNECTEDPLAYING);

                client_two.setCallConnectedRecordingStatus(PLAYING);

                client_two.startPlayingAudioMessage();
            }
        }

        /*Clear the content of the files*/
        client_two.clearFileContent();

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
                    /*If the dial number is of 10 then only call will take place*/
                    if (client_two.getDialNumber().length() == 11)
                    {
                        /*Sending server to call client one*/
                        client_two.sendMessageToServer("CALLCLIENTONE" + client_two.getDialNumber());

                        /*Set the name of the personn calling */
                        client_two.setCallingPersonName("Client One");

                        /*Set the number of calling person*/
                        client_two.setCallingPersonNumber(client_two.getDialNumber());

                        /*Display the calling screen*/
                        client_two.setCurrentScreen(OUTGOING_CALL);

                        /*Play outgoing call sound*/
                        client_two.playOutgoingTone();

                        /*Start the outgoing call time*/
                        client_two.startOutgoingCallTime();
                    }
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
                    client_two.sendMessageToServer("CALLENDEDBYCLIENTTWO");

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
                    client_two.sendMessageToServer("CALLDECLINEDBYCLIENTTWO");

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
                    client_two.sendMessageToServer("CALLRECEIVEDBYCLIENTTWO");

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
            else if ((e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_KEYDOWN) && client_two.getCurrentScreen() == CALL_CONNECTED)
            {
                /*Getting the position of the place where we have click on the window*/
                int x, y;
                SDL_GetMouseState(&x, &y);

                if (e.type == SDL_MOUSEBUTTONDOWN)
                { /*End button is pressed*/
                    if (x >= 179 && x <= 235 && y >= 544 && y <= 597)
                    {
                        /*Sending message to server that call has been ended*/
                        client_two.sendMessageToServer("CALLENDEDBYCLIENTTWO");

                        /*Display the calling screen*/
                        client_two.setCurrentScreen(CALL_ENDED);

                        client_two.playEndCallTone();
                    }
                }

                if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN)
                {
                    if ((e.key.keysym.sym == SDLK_r || (x >= 62 && x <= 120 && y >= 240 && y <= 297)) && client_two.getCallConnectedRecordingStatus() == NONE)
                    {
                        client_two.setCallConnectedStatus(CALLCONNECTEDRECORDING);

                        client_two.startRecordingAudioMessage();
                        client_two.setCallConnectedRecordingStatus(AudioRecordingStatus::RECORDING);
                    }
                    else if ((e.key.keysym.sym == SDLK_s || (x >= 291 && x <= 355 && y >= 247 && y <= 297)) && client_two.getCallConnectedRecordingStatus() == NONE)
                    {
                        client_two.setCallConnectedStatus(CALLCONNECTEDSENDING);

                        client_two.sendMessageToServer("AUDIOMESSAGESENDBYCLIENTTWO");

                        client_two.setCallConnectedRecordingStatus(AudioRecordingStatus::SENDING);
                    }
                }
            }

            /*Call Rejected*/
            else if (e.type == SDL_MOUSEBUTTONDOWN && (client_two.getCurrentScreen() == CALL_REJECTED || client_two.getCurrentScreen() == NUMBER_UNMATCHED))
            {
                /*Getting the position of the place where we have click on the window*/
                int x, y;
                SDL_GetMouseState(&x, &y);

                /*End button is pressed*/
                if (x >= 179 && x <= 235 && y >= 544 && y <= 597)
                {

                    /*Display the calling screen*/
                    client_two.setCurrentScreen(DIALPAD);

                    if (client_two.getCurrentScreen() == CALL_REJECTED)
                    {
                        /*Stop the busy tone(if there is )*/
                        client_two.stopBusyTone();
                    }
                    else
                    {
                        /*Stop the number mismatched*/
                        client_two.stopNumberUnmatchedTone();

                        /*Reset the dial number*/
                        client_two.resetDialNumber();
                    }
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
