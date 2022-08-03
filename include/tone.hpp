#pragma once

#include "sound.hpp"

#include <SDL2/SDL_mixer.h>

#include <iostream>

class Tone : public AbstractSound
{
private:
    Mix_Chunk *tone_audio;

private:
    void loadTone();

public:
    Tone(){};

    Tone(std::string);

    void setSoundPath(std::string sound_path);

    void play();

    /*Since it is pure virtual function*/
    void stop();
};