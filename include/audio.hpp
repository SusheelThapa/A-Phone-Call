#pragma once

#include <SDL2/SDL_mixer.h>

#include <iostream>

#include "sound.hpp"

class Audio : public AbstractSound
{
private:
    Mix_Music *audio;

private:
    void loadAudio();

public:
    Audio(){};
    Audio(std::string sound_path);

    void setSoundPath(std::string sound_path);

    void play();

    void stop();
};