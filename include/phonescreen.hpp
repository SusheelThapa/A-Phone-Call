#pragma once

#include "texture.hpp"
#include "window.hpp"

enum PhoneScreen
{
    DIALPAD,
    INCOMING_CALL,
    OUTGOING_CALL,
    CALL_CONNECTED,
    CALL_REJECTED,
    CALL_ENDED
};

class Screen
{
private:
    Texture dialpad_screen;
    Texture outgoing_call;
    Texture *incoming_call;

    int incoming_call_texture_to_load;

    PhoneScreen current_screen;

public:
    Screen(Window &window);

    void setCurrentScreen(PhoneScreen screen);

    PhoneScreen getCurrentScreen();

    void renderScreen(Window &window);
};