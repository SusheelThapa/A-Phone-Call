/*

C++ Object Oriented Programming Final Project
Dept. of Electronics and Computer Engineering

Author : Susheel Thapa Saurav Kumar Mahato
Class : BCT CD 090 BCT CD 079
Semester : Third Semester

Filename : audio_recording.cpp
Categories : C++ Header File
Description : It is used to recording audio and play the audio.
*/

#pragma once

#include <SDL2/SDL.h>

enum AudioRecordingStatus
{
    NONE,
    RECORDING,
    PLAYING,
    SENDING
};

class AudioRecording
{
    Uint32 recording_started_time;
    Uint32 playing_started_time;

public:
    void startRecordingAudio();

    void resetRecordingStartedTime();

    Uint32 getRecordingStartedTime();

    void startPlayingAudio();

    void resetPlayingStartedTime();

    Uint32 getPlayingStartedTime();
};