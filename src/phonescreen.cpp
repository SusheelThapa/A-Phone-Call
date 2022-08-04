#include "phonescreen.hpp"

Screen::Screen(Window &window)
{
    /*Dynamically allocating the memory for texture of incoming call*/
    incoming_call = new Texture[5];

    /*Loading the required Texture*/
    dialpad_screen.loadFromFile(window, "resources/images/dial_pad.png");
    outgoing_call.loadFromFile(window, "resources/images/outgoing_call.png");
    incoming_call[0].loadFromFile(window, "resources/images/incoming_call_0.png");
    incoming_call[1].loadFromFile(window, "resources/images/incoming_call_1.png");
    incoming_call[2].loadFromFile(window, "resources/images/incoming_call_2.png");
    incoming_call[3].loadFromFile(window, "resources/images/incoming_call_3.png");
    incoming_call[4].loadFromFile(window, "resources/images/incoming_call_4.png");

    incoming_call_texture_to_load = 3;

    /*Setting the default screen*/
    this->current_screen = DIALPAD;
}

void Screen::setCurrentScreen(PhoneScreen screen)
{
    if (screen == CALL_REJECTED)
    {
        std::cout << "Call Rejected";
    }
    else if (screen == CALL_CONNECTED)
    {
        std::cout << "Call Connected";
    }
    this->current_screen = screen;
}

PhoneScreen Screen::getCurrentScreen()
{
    return current_screen;
}

void Screen::renderScreen(Window &window)
{

    if (current_screen == DIALPAD)
    {
        dialpad_screen.render(window, 0, 0, nullptr, nullptr);
    }
    else if (current_screen == INCOMING_CALL)
    {

        /*Loading the texture of incoming call*/
        incoming_call[(incoming_call_texture_to_load / 5)].render(window, 0, 0, nullptr, nullptr);

        /*Choose the texture to render for incoming call*/
        incoming_call_texture_to_load++;

        if (incoming_call_texture_to_load > 20)
        {
            incoming_call_texture_to_load = 0;
        }
    }
    else if (current_screen == OUTGOING_CALL || current_screen == CALL_CONNECTED || current_screen == CALL_REJECTED || current_screen == CALL_ENDED)
    {

        outgoing_call.render(window, 0, 0, nullptr, nullptr);
    }
}
