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

void Time::resetTime()
{
    min = 0;
    sec = 0;
}

Phone::Phone(Window &window, std::string name)
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

    /*Setting the name of the phone*/
    this->name = name;
    this->calling_person_name = " ";

    /*Loading the TTF Font*/
    big_font = TTF_OpenFont("resources/fonts/freesans.ttf", 56);
    medium_font = TTF_OpenFont("resources/fonts/freesans.ttf", 32);

    /*Setting the value of start time after call connected*/
    start_time = 0;

    /*Setting the value of incoming and outgoing call time*/
    incoming_call_time = 0;
    outgoing_call_time = 0;

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
    outgoing_tone.setAudioPath("resources/audio/outgoing-tone.wav");

    /*Set the phone status*/
    phone_status = SWITCH_OFF;

    /*Dynamically allocate memory to load texture for switch on*/
    switch_on = new Texture[10];

    switch_on[0].loadFromFile(window, "resources/images/switch_on/switch_on_0.png");
    switch_on[1].loadFromFile(window, "resources/images/switch_on/switch_on_1.png");
    switch_on[2].loadFromFile(window, "resources/images/switch_on/switch_on_2.png");
    switch_on[3].loadFromFile(window, "resources/images/switch_on/switch_on_3.png");
    switch_on[4].loadFromFile(window, "resources/images/switch_on/switch_on_4.png");
    switch_on[5].loadFromFile(window, "resources/images/switch_on/switch_on_5.png");
    switch_on[6].loadFromFile(window, "resources/images/switch_on/switch_on_6.png");
    switch_on[7].loadFromFile(window, "resources/images/switch_on/switch_on_7.png");
    switch_on[8].loadFromFile(window, "resources/images/switch_on/switch_on_8.png");
    switch_on[9].loadFromFile(window, "resources/images/switch_on/switch_on_9.png");

    /*Set the texture to display while switch on the phone*/
    switch_on_texture_to_display = 0;
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

    /*Switch on animation*/
    if (phone_status == SWITCH_OFF)
    {
        switch_on[(switch_on_texture_to_display / 20)].render(window, 0, 0, nullptr, nullptr);
        switch_on_texture_to_display++;

        if (switch_on_texture_to_display > 190)
        {
            phone_status = SWITCH_ON;
        }

        return;
    }

    if (current_screen == DIALPAD)
    {
        dialpad_screen.render(window, 0, 0, nullptr, nullptr);
    }
    else if (current_screen == INCOMING_CALL)
    {
        this->checkIncomingCallTime();

        /*Loading the texture of incoming call*/
        incoming_call[(incoming_call_texture_to_load / 5)].render(window, 0, 0, nullptr, nullptr);

        /*Choose the texture to render for incoming call*/
        incoming_call_texture_to_load++;

        if (incoming_call_texture_to_load > 20)
        {
            incoming_call_texture_to_load = 0;
        }

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
        this->checkOutgoingCallTime();

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
        this->updateCallConnectedTime();

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

void Phone::startIncomingCallTime()
{
    incoming_call_time = SDL_GetTicks();
}

void Phone::endIncomingCallTime()
{
    incoming_call_time = 0;
}

void Phone::checkIncomingCallTime()
{
    if ((SDL_GetTicks() - incoming_call_time) / 1000 > 15)
    {
        /*Stop the ringtone*/
        this->stopRingtone();

        /*Change the current screen to dial pad*/
        this->current_screen = DIALPAD;

        /*Reset incoming call time*/
        incoming_call_time = 0;
    }
}
void Phone::startOutgoingCallTime()
{
    outgoing_call_time = SDL_GetTicks();
}

void Phone::endOutgoingCallTime()
{
    outgoing_call_time = 0;
}

void Phone::checkOutgoingCallTime()
{
    /*When the outgoing has lasted for more that 10 sec i.e phone hasn't been received then we will play besta tone*/

    /*For now if the outgoing call has gone for 15 sec we will close call*/
    if ((SDL_GetTicks() - outgoing_call_time) / 1000 > 15)
    {
        /*Stop the outgoing call tone*/
        this->stopOutgoingTone();

        /*Change the current screen to dialpad*/
        this->current_screen = DIALPAD;

        /*Reset the outcoming call time*/
        outgoing_call_time = 0;
    }
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
void Phone::playOutgoingTone()
{
    outgoing_tone.play();
}

void Phone::stopOutgoingTone()
{
    outgoing_tone.stop();
}

void Phone::startCallConnectedTime()
{
    this->call_connected_time = 0;
    this->start_time = SDL_GetTicks();
}

void Phone::updateCallConnectedTime()
{
    if ((SDL_GetTicks() - this->start_time) / 1000 > 1)
    {
        this->start_time = SDL_GetTicks();

        /*Increase Time object*/
        this->call_connected_time++;
    }
}

void Phone::resetCallConnectedTime()
{
    call_connected_time.resetTime();
    start_time = 0;
}

void Phone::appendDialNumber(std::string num_string)
{
    number_string += num_string;
    std::cout << number_string << std::endl;
}

void Phone::resetDialNumber()
{
    number_string = " ";
}