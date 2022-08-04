#pragma once

#include <SDL2/SDL_ttf.h>
#include <string>

#include "window.hpp"
#include "texture.hpp"
#include "tone.hpp"
#include "audio.hpp"
#include "audio_recording.hpp"

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

    void resetTime();
};

class Phone
{
private:
    enum Status
    {
        SWITCH_OFF,
        SWITCH_ON
    };

private:
    std::string name;

    std::string calling_person_name;

    PhoneScreen current_screen;

    Texture dialpad_screen;
    Texture outgoing_call;
    Texture *incoming_call;

    int incoming_call_texture_to_load;

    Texture calling_person;
    Texture call_time;

    Texture dial_number;
    std::string dial_pad_number;

    TTF_Font *big_font;

    TTF_Font *medium_font;

    int start_time; // Dummy argument to keep track how call connected time

    Time call_connected_time;

    Tone dialpad_tone[10];

    Audio ringtone;
    Audio outgoing_tone;

    int outgoing_call_time;

    int incoming_call_time;

    Status phone_status;

    Texture *switch_on;

    int switch_on_texture_to_display;

    Tone end_call_tone;

    Audio busy_audio;

    Texture call_ended;

    AudioRecording call_connected_audio_recording;

    AudioRecordingStatus call_connected_audio_recording_status;

public:
    Phone(Window &window, std::string name);

    void setScreen(PhoneScreen screen);

    void setCallingPersonName(std::string name);

    PhoneScreen getScreen();

    void render(Window &window);

    void startCallTime();

    void endCallTime();

    void startIncomingCallTime();

    void endIncomingCallTime();

    void checkIncomingCallTime();

    void startOutgoingCallTime();

    void endOutgoingCallTime();

    void checkOutgoingCallTime();

    void playDialpadTone(int dialpad_number);

    void playRingtone();

    void stopRingtone();

    void playOutgoingTone();

    void stopOutgoingTone();

    void startCallConnectedTime();

    void updateCallConnectedTime();

    void resetCallConnectedTime();

    void appendDialNumber(std::string number);

    void resetDialNumber();

    void removeOneDialNumber();

    void playEndCallTone();

    void playBusyTone();

    void stopBusyTone();

    void startRecording();

    void setCallConnectedRecordingStatus(AudioRecordingStatus status);
    
    AudioRecordingStatus getCallConnectedRecordingStatus();

    ~Phone() {}
};
