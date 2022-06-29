#pragma once

#ifndef SHAPE_INCLUDED
#include "shape.hpp"
#endif

class Rectangle : public Shape
{
private:
    SDL_Point starting_point;
    int width, height;

public:
    Rectangle();
    Rectangle(SDL_Point starting_point, int width, int height);

    void render(Window &window);
};
