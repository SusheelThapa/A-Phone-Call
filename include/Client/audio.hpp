/*

C++ Object Oriented Programming Final Project
Dept. of Electronics and Computer Engineering

Author : Susheel Thapa Saurav Kumar Mahato
Class : BCT CD 090 BCT CD 079
Semester : Third Semester

Filename : audio.cpp
Categories : C++ Header File
Description : It is used to store the audio file that we will used in phone call app.
*/

#pragma once

#include <SDL2/SDL_mixer.h>

#include <iostream>

#include <Client/sound.hpp>

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