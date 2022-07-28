#include "phone.hpp"

Phone::Phone(Window &window, std::string name)
{
    /*Loading the required Texture*/
    dialpad_screen.loadFromFile(window, "resources/images/dial_pad.png");
    outgoing_call.loadFromFile(window, "resources/images/outgoing_call.png");
    incoming_call.loadFromFile(window, "resources/images/incoming_call.png");

    /*Setting the default screen*/
    this->current_screen = DIALPAD;

    /*Setting the name of the phone*/
    this->name = name;
}

void Phone::setScreen(PhoneScreen screen)
{
    this->current_screen = screen;
}

PhoneScreen Phone::getScreen()
{
    return current_screen;
}

void Phone::render(Window &window)
{
    if (current_screen == DIALPAD)
    {
        dialpad_screen.render(window, 0, 0, nullptr, nullptr);
    }
    else if (current_screen == INCOMING_CALL)
    {
        incoming_call.render(window, 0, 0, nullptr, nullptr);
    }
    else if (current_screen == OUTGOING_CALL)
    {
        outgoing_call.render(window, 0, 0, nullptr, nullptr);
    }
    else if (current_screen == CALL_CONNECTED)
    {
        /*Display the name of the person who is called*/

        /*Display the call_time*/
    }
    else if (current_screen == CALL_REJECTED)
    /*Later on we will look into*/
    {
    }
    else if (current_screen == CALL_ENDED)
    {
        /*Later on we will look into*/
    }
}
