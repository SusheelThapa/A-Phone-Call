/*
Author : Susheel Thapa
Filename : shape.hpp

Description: An abstract class to make other shapes like square, rectangle, triangle, pentagon, etc.
*/

#pragma once

#ifdef __linux__
#include <SDL2/SDL.h>

#elif _WIN32
#include <SDL2/SDL.h>

#endif

#define SHAPE_INCLUDED 1

#include "window.hpp"

class Shape
{
private:
    SDL_Color color;

public:
    void setColor(int r, int g, int b, int a);

    SDL_Color getColor();

    virtual void render(Window &);
};
