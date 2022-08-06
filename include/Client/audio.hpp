#pragma once

#include <SDL2/SDL_mixer.h>

#include <iostream>

#include "Client/sound.hpp"

class Audio : public AbstractSound
{
private:
    Mix_Music *audio;

private:
    void loadAudio();

public:
    Audio(){};
    Audio(std::string sound_path);

    ~Audio();

    void setSoundPath(std::string sound_path);

    void play();

    void stop();
};