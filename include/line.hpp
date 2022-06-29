#pragma once

#ifndef SHAPE_INCLUDED
#include "shape.hpp"
#endif

class Line : public Shape
{
    SDL_Point point_one, point_two;

    void setPoint(int point_value, SDL_Point point);

public:
    void setPoints(int x1, int y1, int x2, int y2);

    void render(Window &window);
};