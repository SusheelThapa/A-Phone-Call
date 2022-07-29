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
    big_font = TTF_OpenFont("resources/fonts/freesans.ttf", 56);
    medium_font = TTF_OpenFont("resources/fonts/freesans.ttf", 32);

    /*Setting the value of start time after call connected*/
    start_time = 0;

    /*Loading Dialpad tone*/
    dialpad_tone[0].setTonePath("resources/audio/tone-zero.wav");
    dialpad_tone[1].setTonePath("resources/audio/tone-one.wav");
    dialpad_tone[2].setTonePath("resources/audio/tone-two.wav");
    dialpad_tone[3].setTonePath("resources/audio/tone-three.wav");
    dialpad_tone[4].setTonePath("resources/audio/tone-four.wav");
    dialpad_tone[5].setTonePath("resources/audio/tone-five.wav");
    dialpad_tone[6].setTonePath("resources/audio/tone-six.wav");
    dialpad_tone[7].setTonePath("resources/audio/tone-seven.wav");
    dialpad_tone[8].setTonePath("resources/audio/tone-eight.wav");
    dialpad_tone[9].setTonePath("resources/audio/tone-nine.wav");

    /*Loading ringtone*/
    ringtone.setAudioPath("resources/audio/ringtone.wav");
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
        calling_person.loadFromText(window, big_font, calling_person_name, {0, 0, 0, 0});

        SDL_Rect render_calling_person_rect = {
            (window.getWidth() - calling_person.getWidth()) / 2,
            300,
            calling_person.getWidth(),
            calling_person.getHeight()};

        calling_person.render(window, 0, 0, nullptr, &render_calling_person_rect);
    }
    else if (current_screen == OUTGOING_CALL)
    {
        outgoing_call.render(window, 0, 0, nullptr, nullptr);

        /*Add the person name to whom he/she is calling*/
        calling_person.loadFromText(window, big_font, calling_person_name, {0, 0, 0, 0});

        SDL_Rect render_calling_person_rect = {
            (window.getWidth() - calling_person.getWidth()) / 2,
            40,
            calling_person.getWidth(),
            calling_person.getHeight()};

        calling_person.render(window, 0, 0, nullptr, &render_calling_person_rect);
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

void Phone::playDialpadTone(int dialpad_number)
{
    dialpad_tone[dialpad_number].play();
}

void Phone::playRingtone()
{
    ringtone.play();
}

void Phone::stopRingtone()
{
    ringtone.stop();
}
