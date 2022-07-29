#include "phone.hpp"

int Time::getMinutes()
{
    return this->min;
}

int Time::getSeconds()
{
    return this->sec;
}

Time Time::operator++(int)
{

    sec++;
    if (sec == 60)
    {
        min++;
        sec = 0;
    }

    return Time(sec, min);
}

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
    this->calling_person_name = "Client One";

    /*Loading the TTF Font*/
    big_font = TTF_OpenFont("fonts/freesans.ttf", 56);
    medium_font = TTF_OpenFont("fonts/freesans.ttf", 32);

    /*Setting the value of start time after call connected*/
    start_time = 0;
}

void Phone::setScreen(PhoneScreen screen)
{
    this->current_screen = screen;
}

void Phone::setCallingPersonName(std::string name)
{
    this->calling_person_name = name;
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

        /*Add the name of person who is calling*/
    }
    else if (current_screen == OUTGOING_CALL)
    {
        outgoing_call.render(window, 0, 0, nullptr, nullptr);

        /*Add the person name to whom he/she is calling*/
    }
    else if (current_screen == CALL_CONNECTED)
    {
        outgoing_call.render(window, 0, 0, nullptr, nullptr);

        /*Display the name of the person who is called*/
        calling_person.loadFromText(window, big_font, calling_person_name, {0, 0, 0, 0});

        SDL_Rect render_calling_person_rect = {
            (window.getWidth() - calling_person.getWidth()) / 2,
            40,
            calling_person.getWidth(),
            calling_person.getHeight()};

        calling_person.render(window, 0, 0, nullptr, &render_calling_person_rect);

        /*Updating the call time*/
        if ((SDL_GetTicks() - start_time) / 1000 > 1)
        {
            start_time = SDL_GetTicks();

            /*Increase Time object*/
            call_connected_time++;
        }

        /*Display the call_time*/
        call_time.loadFromText(window, medium_font, std::to_string(call_connected_time.getMinutes()) + ":" + std::to_string(call_connected_time.getSeconds()), {0, 0, 0, 0});

        SDL_Rect render_call_time_rect = {
            (window.getWidth() - call_time.getWidth()) / 2,
            120,
            call_time.getWidth(),
            call_time.getHeight()};

        call_time.render(window, 0, 0, nullptr, &render_call_time_rect);
    }
    else if (current_screen == CALL_REJECTED)
    {
        /*Later on we will look into*/
    }
    else if (current_screen == CALL_ENDED)
    {
        /*Later on we will look into*/
    }
}

void Phone::startCallTime()
{
    start_time = SDL_GetTicks();
}
void Phone::endCallTime()
{
    start_time = 0;
}