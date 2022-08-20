/*

C++ Object Oriented Programming Final Project
Dept. of Electronics and Computer Engineering

Author : Susheel Thapa Saurav Kumar Mahato
Class : BCT CD 090 BCT CD 079
Semester : Third Semester

Filename : window.cpp
Categories : C++ Header File
Description : It represent the screen that are present in the phone.
*/

#pragma once

#include <Client/texture.hpp>
#include <Client/window.hpp>

enum PhoneScreen
{
    DIALPAD,
    INCOMING_CALL,
    OUTGOING_CALL,
    CALL_CONNECTED,
    CALL_REJECTED,
    CALL_ENDED,
    NUMBER_UNMATCHED,
};

enum CallConnectedStatus
{
    CALLCONNECTEDNONE,
    CALLCONNECTEDRECORDING,
    CALLCONNECTEDPLAYING,
    CALLCONNECTEDSENDING
};

class Screen
{
private:
    Texture dialpad_screen;
    Texture outgoing_call;
    Texture *incoming_call;

    Texture *call_connected;
    int incoming_call_texture_to_load;

    PhoneScreen current_screen;
    CallConnectedStatus call_connected_status;

public:
    Screen(Window &window);

    ~Screen();

    void setCurrentScreen(PhoneScreen screen);

    PhoneScreen getCurrentScreen();

    void renderScreen(Window &window);

    void setCallConnectedStatus(CallConnectedStatus status);
};