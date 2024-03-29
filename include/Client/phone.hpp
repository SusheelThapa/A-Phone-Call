/*

C++ Object Oriented Programming Final Project
Dept. of Electronics and Computer Engineering

Author : Susheel Thapa Saurav Kumar Mahato
Class : BCT CD 090 BCT CD 079
Semester : Third Semester

Filename : phone.cpp
Categories : C++ Header File
Description : It represent the core part of the phone app we are creating.
*/

#pragma once

#include <SDL2/SDL_ttf.h>
#include <string>

#include <Client/window.hpp>
#include <Client/texture.hpp>
#include <Client/audio_recording.hpp>
#include <Client/phonescreen.hpp>
#include <Client/phonesound.hpp>
#include <Client/phonefont.hpp>
#include <Client/phonefile.hpp>

class Phone : public Screen, public PhoneSound, public PhoneFont, public PhoneFile
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

    std::string calling_person_number;

    Texture calling_person;

    Texture calling_person_number_texture;

    Texture call_connected_status;

    Texture dial_number;
    std::string dial_pad_number;

    int start_time; // Dummy argument to keep track how call connected time

    int outgoing_call_time;

    int incoming_call_time;

    Status phone_status;

    Texture *switch_on;

    int switch_on_texture_to_display;

    Texture call_ended;

    AudioRecording call_connected_audio_recording;

    AudioRecordingStatus call_connected_audio_recording_status;

public:
    Phone(Window &window, std::string name);

    ~Phone();

    void setCallingPersonName(std::string name);

    void setCallingPersonNumber(std::string number);

    void render(Window &window);

    void startCallTime();

    void endCallTime();

    void startIncomingCallTime();

    void endIncomingCallTime();

    void checkIncomingCallTime();

    void startOutgoingCallTime();

    void endOutgoingCallTime();

    void checkOutgoingCallTime();

    void appendDialNumber(std::string number);

    void resetDialNumber();

    void removeOneDialNumber();

    std::string getDialNumber();

    void startRecordingAudioMessage();

    void startPlayingAudioMessage();

    void setCallConnectedRecordingStatus(AudioRecordingStatus status);

    AudioRecordingStatus getCallConnectedRecordingStatus();
};
