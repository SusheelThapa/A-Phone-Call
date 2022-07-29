#pragma once

#ifndef TONE_HEADER_FILE
#define TONE_HEADER_FILE 1
#endif

#include <SDL2/SDL_mixer.h>

#include <iostream>

class Audio
{
private:
    Mix_Music *audio;
    std::string audio_path;

public:
    Audio();

    Audio(std::string);

    void setAudioPath(std::string);

    std::string getAudioPath();

    void play();

    void stop();
};