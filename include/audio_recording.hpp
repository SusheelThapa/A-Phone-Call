#pragma once

#include <SDL2/SDL.h>

enum AudioRecordingStatus
{
    NONE,
    RECORDING,
    RECORDED,
    PLAYING,
    PLAYED,
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