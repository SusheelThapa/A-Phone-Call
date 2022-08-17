/*

C++ Object Oriented Programming Final Project
Dept. of Electronics and Computer Engineering

Author : Susheel Thapa Saurav Kumar Mahato
Class : BCT CD 090 BCT CD 079
Semester : Third Semester

Filename : tone.cpp
Categories : C++ Header File
Description : Header file to store and play the tone
*/

#pragma once

/*Custom Header file*/
#include <Client/sound.hpp>

/*SDL2 Header file*/
#include <SDL2/SDL_mixer.h>

/*Standard C++ Header file*/
#include <iostream>

/*Creating class via Single Inheritance*/
class Tone : public AbstractSound
{
private:
    Mix_Chunk *tone_audio;

private:
    void loadTone();

public:
    Tone(){};

    Tone(std::string);

    ~Tone();

    void setSoundPath(std::string sound_path);

    void play();

    void stop();
};