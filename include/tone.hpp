#pragma once

#ifndef TONE_HEADER_FILE
#define TONE_HEADER_FILE 1
#endif

#include <SDL2/SDL_mixer.h>

#include <iostream>

class Tone
{
private:
    Mix_Chunk *tone_audio;
    std::string audio_path;

public:
    Tone();

    Tone(std::string);

    void setAudioPath(std::string);

    std::string getAudioPath();

    void play();
};