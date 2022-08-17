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