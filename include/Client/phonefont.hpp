/*

C++ Object Oriented Programming Final Project
Dept. of Electronics and Computer Engineering

Author : Susheel Thapa Saurav Kumar Mahato
Class : BCT CD 090 BCT CD 079
Semester : Third Semester

Filename : phonefont.cpp
Categories : C++ Header File
Description : It represent the font that will be using for the project
*/

#pragma once

#include <SDL2/SDL_ttf.h>

class PhoneFont
{
    TTF_Font *big_font;

    TTF_Font *medium_font;

public:
    PhoneFont();
    ~PhoneFont();

    TTF_Font *getBigFont();
    TTF_Font *getMediumFont();
};