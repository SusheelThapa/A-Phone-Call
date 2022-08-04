#include "phone.hpp"

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
    dialpad_tone[0].setSoundPath("resources/audio/tone-zero.wav");
    dialpad_tone[1].setSoundPath("resources/audio/tone-one.wav");
    dialpad_tone[2].setSoundPath("resources/audio/tone-two.wav");
    dialpad_tone[3].setSoundPath("resources/audio/tone-three.wav");
    dialpad_tone[4].setSoundPath("resources/audio/tone-four.wav");
    dialpad_tone[5].setSoundPath("resources/audio/tone-five.wav");
    dialpad_tone[6].setSoundPath("resources/audio/tone-six.wav");
    dialpad_tone[7].setSoundPath("resources/audio/tone-seven.wav");
    dialpad_tone[8].setSoundPath("resources/audio/tone-eight.wav");
    dialpad_tone[9].setSoundPath("resources/audio/tone-nine.wav");

    /*Loading ringtone*/
    ringtone.setSoundPath("resources/audio/ringtone.wav");
    outgoing_tone.setSoundPath("resources/audio/outgoing-tone.wav");

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

    /*Load end call tone*/
    end_call_tone.setSoundPath("resources/audio/end_call_tone.wav");

    /*Load busy_audio*/
    busy_audio.setSoundPath("resources/audio/busy-tone.wav");

    /*Create callended texture*/
    call_ended.loadFromText(window, medium_font, "Call Ended", {255, 0, 0, 255});

    /*Initialize the dial number string*/
    dial_pad_number = " ";

    /*Set the status of audio call recording*/
    call_connected_audio_recording_status = AudioRecordingStatus::NONE;
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

        SDL_Rect dial_number_render_rect = {
            (window.getWidth() - dial_number.getWidth()) / 2,
            60,
            dial_number.getWidth(),
            dial_number.getHeight()};

        dial_number.loadFromText(window, big_font, dial_pad_number, {0, 0, 0, 0});

        dial_number.render(window, 0, 0, nullptr, &dial_number_render_rect);
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

        if ((SDL_GetTicks() - call_connected_audio_recording.getRecordingStartedTime()) / 1000 > 10 && call_connected_audio_recording_status == RECORDING)
        {
            call_connected_audio_recording.resetRecordingStartedTime();
            call_connected_audio_recording_status = RECORDED;
        }

        if ((SDL_GetTicks() - call_connected_audio_recording.getPlayingStartedTime()) / 1000 > 10 && call_connected_audio_recording_status == PLAYING)
        {
            call_connected_audio_recording.resetPlayingStartedTime();
            call_connected_audio_recording_status = PLAYED;
        }

        std::string message;
        SDL_Color color;

        if (call_connected_audio_recording_status == AudioRecordingStatus::NONE)
        {
            message = " ";
            color = {0, 0, 0, 0};
        }
        else if (call_connected_audio_recording_status == AudioRecordingStatus::RECORDING)
        {
            message = "Recording";
            color = {255, 0, 0, 255};
        }

        else if (call_connected_audio_recording_status == AudioRecordingStatus::RECORDED)
        {
            message = "Recorded";
            color = {255, 0, 0, 255};
        }

        else if (call_connected_audio_recording_status == AudioRecordingStatus::PLAYING)
        {
            message = "Playing";
            color = {0, 255, 0, 255};
        }

        else if (call_connected_audio_recording_status == AudioRecordingStatus::PLAYED)
        {
            message = "Played";
            color = {0, 255, 0, 255};
        }

        else if (call_connected_audio_recording_status == AudioRecordingStatus::SENDING)
        {
            message = "Sending";
            color = {0, 255, 0, 255};

            this->setCallConnectedRecordingStatus(NONE);
        }

        else if (call_connected_audio_recording_status == AudioRecordingStatus::NONE)
        {
            message = " ";
            color = {0, 255, 0, 255};
        }

        call_connected_status.loadFromText(
            window,
            this->medium_font,
            message, color);

        SDL_Rect call_connected_status_rect = {
            (window.getWidth() - call_connected_status.getWidth()) / 2,
            0,
            call_connected_status.getWidth(),
            call_connected_status.getHeight()};

        call_connected_status.render(window, 0, 0, nullptr, &call_connected_status_rect);
    }
    else if (current_screen == CALL_REJECTED)
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
    else if (current_screen == CALL_ENDED)
    {
        /*Render the outgoing call screen*/
        outgoing_call.render(window, 0, 0, nullptr, nullptr);

        /*Render the name of person*/
        calling_person.loadFromText(window, big_font, calling_person_name, {0, 0, 0, 0});

        SDL_Rect render_calling_person_rect = {
            (window.getWidth() - calling_person.getWidth()) / 2,
            40,
            calling_person.getWidth(),
            calling_person.getHeight()};

        calling_person.render(window, 0, 0, nullptr, &render_calling_person_rect);

        /*Render call ended button*/
        SDL_Rect call_ended_texture_display_rect = {
            (window.getWidth() - call_ended.getWidth()) / 2,
            100,
            call_ended.getWidth(),
            call_ended.getHeight()};

        call_ended.render(window, 0, 0, nullptr, &call_ended_texture_display_rect);

        /*Reset the name of the calling person*/
        this->setCallingPersonName(" ");
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

void Phone::appendDialNumber(std::string num_string)
{
    if (dial_pad_number.size() <= 10)
    {
        dial_pad_number += num_string;
    }
}

void Phone::resetDialNumber()
{
    dial_pad_number = " ";
}

void Phone::removeOneDialNumber()
{
    if (dial_pad_number != " ")
    {
        dial_pad_number.pop_back();
    }
}

void Phone::playEndCallTone()
{
    end_call_tone.play();
}

void Phone::playBusyTone()
{
    busy_audio.play();
}

void Phone::stopBusyTone()
{
    busy_audio.stop();
}

void Phone::startRecordingAudioMessage()
{
    /*This will start recording audio for 5 second*/
    call_connected_audio_recording.startRecordingAudio();

    /*Set the recording status*/
    call_connected_audio_recording_status = AudioRecordingStatus::RECORDING;
}

void Phone::startPlayingAudioMessage()
{
    call_connected_audio_recording.startPlayingAudio();

    call_connected_audio_recording_status = AudioRecordingStatus::PLAYING;
}

void Phone::setCallConnectedRecordingStatus(AudioRecordingStatus status)
{
    call_connected_audio_recording_status = status;
}

AudioRecordingStatus Phone::getCallConnectedRecordingStatus()
{
    return this->call_connected_audio_recording_status;
}
