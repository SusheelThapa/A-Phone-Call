#pragma once

#ifndef SHAPE_INCLUDED
#include "shape.hpp"
#endif

class Triangle : public Shape
{
private:
    SDL_Point point_one;
    SDL_Point point_two;
    SDL_Point point_three;

private:
    void setPoint(int point_value, SDL_Point point);

public:
    void setPoints(int x1, int y1, int x2, int y2, int x3, int y3);

    void render(Window &window);
};
