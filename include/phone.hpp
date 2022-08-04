#pragma once

#include <SDL2/SDL_ttf.h>
#include <string>

#include "window.hpp"
#include "texture.hpp"
#include "audio_recording.hpp"
#include "phonescreen.hpp"
#include "phonesound.hpp"
#include "phonefont.hpp"

class Phone : public Screen, public PhoneSound, public PhoneFont
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

    Texture calling_person;
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

    void setCallingPersonName(std::string name);

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

    void startRecordingAudioMessage();

    void startPlayingAudioMessage();

    void setCallConnectedRecordingStatus(AudioRecordingStatus status);

    AudioRecordingStatus getCallConnectedRecordingStatus();

    ~Phone() {}
};
