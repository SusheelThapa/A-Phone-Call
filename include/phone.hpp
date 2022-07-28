#pragma once

#include "texture.hpp"
#include "window.hpp"
#include <string>

enum PhoneScreen
{
    DIALPAD,
    INCOMING_CALL,
    OUTGOING_CALL,
    CALL_CONNECTED,
    CALL_REJECTED,
    CALL_ENDED
};

class Phone
{
private:
    std::string name;

    std::string calling_person_name;

    PhoneScreen current_screen;

    Texture dialpad_screen;
    Texture outgoing_call;
    Texture incoming_call;

    Texture calling_person;
    Texture call_time;

public:
    Phone(Window &window, std::string name);

    void setScreen(PhoneScreen screen);

    PhoneScreen getScreen();

    void render(Window &window);

    ~Phone() {}
};
