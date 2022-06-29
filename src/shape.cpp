/*
Author : Susheel Thapa
Filename : shape.cpp

Description: Body of shape.cpp
*/

#include "shape.hpp"

void Shape::setColor(int r, int g, int b, int a)
{
    this->color.r = r;
    this->color.g = g;
    this->color.b = b;
    this->color.a = a;
}

SDL_Color Shape::getColor()
{
    return this->color;
}

void Shape::render(Window &) {}