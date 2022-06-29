#include "rectangle.hpp"

Rectangle::Rectangle(){};

Rectangle::Rectangle(SDL_Point starting_point, int width, int height)
{
    this->starting_point = starting_point;
    this->width = width;
    this->height = height;
}

void Rectangle::render(Window &window)
{
    SDL_SetRenderDrawColor(window.renderer, this->getColor().r, this->getColor().g, this->getColor().b, this->getColor().a);

    SDL_Rect rec = {this->starting_point.x, this->starting_point.y, this->width, this->height};
    SDL_RenderDrawRect(window.renderer, &rec);
}
