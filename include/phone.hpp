#pragma once

#include "texture.hpp"
#include "window.hpp"
#include <string>
#include <SDL2/SDL_ttf.h>

enum PhoneScreen
{
    DIALPAD,
    INCOMING_CALL,
    OUTGOING_CALL,
    CALL_CONNECTED,
    CALL_REJECTED,
    CALL_ENDED
};

class Time
{
private:
    int min;
    int sec;

public:
    Time(int m = 0, int s = 0)
    {
        min = m;
        sec = s;
    }

    int getMinutes();

    int getSeconds();

    Time operator++(int);
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

    TTF_Font *big_font;
    TTF_Font *medium_font;

    int start_time; // Dummy argument to keep track how call connected time

    Time call_connected_time;

public:
    Phone(Window &window, std::string name);

    void setScreen(PhoneScreen screen);

    void setCallingPersonName(std::string name);

    PhoneScreen getScreen();

    void render(Window &window);

    void startCallTime();

    void endCallTime();

    ~Phone() {}
};
