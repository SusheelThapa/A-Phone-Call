/*

C++ Object Oriented Programming Final Project
Dept. of Electronics and Computer Engineering

Author : Susheel Thapa Saurav Kumar Mahato
Class : BCT CD 090 BCT CD 079
Semester : Third Semester

Filename : window.cpp
Categories : C++ Header File
Description : Abstract sound class
*/

#pragma once

#include <string>

class AbstractSound
{
    std::string sound_path;

public:
    AbstractSound(){};

    void setSoundPath(std::string sound_path);

    std::string getSoundPath();

    virtual void play() = 0;
    virtual void stop() = 0;
};