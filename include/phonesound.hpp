#pragma once

#include "audio.hpp"
#include "tone.hpp"

class PhoneSound
{
    Tone dialpad_tone[10];

    Audio ringtone;

    Audio outgoing_tone;

    Tone end_call_tone;

    Audio busy_audio;

public:
    PhoneSound();

    void playDialpadTone(int dialpad_number);

    void playRingtone();

    void stopRingtone();

    void playOutgoingTone();

    void stopOutgoingTone();

    void playEndCallTone();

    void playBusyTone();

    void stopBusyTone();
};