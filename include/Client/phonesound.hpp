
/*

C++ Object Oriented Programming Final Project
Dept. of Electronics and Computer Engineering

Author : Susheel Thapa Saurav Kumar Mahato
Class : BCT CD 090 BCT CD 079
Semester : Third Semester

Filename : phonesound.cpp
Categories : C++ Header File
Description : Class formed by single inheritance from sound.hpp which is used to handle the audioi.e short duration audio like dial pad tone.
*/

#pragma once

/*Custom made tone*/
#include <Client/audio.hpp>
#include <Client/tone.hpp>

class PhoneSound
{
    Tone dialpad_tone[10];

    Audio ringtone;

    Audio outgoing_tone;

    Tone end_call_tone;

    Audio busy_audio;

    Audio number_unmatched;

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

    void playNumberUnmatchedTone();

    void stopNumberUnmatchedTone();
};