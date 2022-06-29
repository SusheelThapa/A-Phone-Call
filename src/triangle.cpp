#include "triangle.hpp"

void Triangle::setPoint(int point_value, SDL_Point point)
{
    switch (point_value)
    {
    case 1:
        this->point_one = point;
        break;
    case 2:
        this->point_two = point;
        break;
    case 3:
        this->point_three = point;
        break;

    default:
        break;
    }
}

void Triangle::setPoints(int x1, int y1, int x2, int y2, int x3, int y3)
{
    this->setPoint(1, {x1, y1});
    this->setPoint(2, {x2, y2});
    this->setPoint(3, {x3, y3});
}

void Triangle::render(Window &window)
{
    SDL_SetRenderDrawColor(window.renderer, this->getColor().r, this->getColor().g, this->getColor().b, this->getColor().a);

    /*Draw line from point_one to point_two*/
    SDL_RenderDrawLine(window.renderer, this->point_one.x, this->point_one.y, this->point_two.x, this->point_two.y);

    /* Draw line from point_two to point_three*/
    SDL_RenderDrawLine(window.renderer, this->point_three.x, this->point_three.y, this->point_two.x, this->point_two.y);

    /*Draw line to point_three to point_one*/
    SDL_RenderDrawLine(window.renderer, this->point_one.x, this->point_one.y, this->point_three.x, this->point_three.y);

    /*Drawing solid triangle(If possible i will try on it*/
}