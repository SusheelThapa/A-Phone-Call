#include "audio_recording.hpp"

#include <iostream>
#include <fstream>

void AudioRecording::startRecordingAudio()
{
    this->recording_started_time = SDL_GetTicks();

    system("arecord resources/audio/test.wav -c 2 -f S16_LE -r 96000 -d 5 &");
}

void AudioRecording::resetRecordingStartedTime()
{
    this->recording_started_time = 0;
}

Uint32 AudioRecording::getRecordingStartedTime()
{
    return this->recording_started_time;
}

void AudioRecording::startPlayingAudio()
{
    this->playing_started_time = SDL_GetTicks();

    system("aplay resources/audio/test.wav &");
}

void AudioRecording::resetPlayingStartedTime()
{
    this->playing_started_time = 0;
}

Uint32 AudioRecording::getPlayingStartedTime()
{
    return this->playing_started_time;
}