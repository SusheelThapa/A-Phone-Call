#include "line.hpp"

void Line::setPoint(int point_value, SDL_Point point)
{
    switch (point_value)
    {
    case 1:
        this->point_one = point;
        break;
    case 2:
        this->point_two = point;
        break;

    default:
        break;
    }
}

void Line::setPoints(int x1, int y1, int x2, int y2)
{
    this->setPoint(1, {x1, y1});
    this->setPoint(2, {x2, y2});
}

void Line::render(Window &window)
{

    SDL_SetRenderDrawColor(window.renderer, this->getColor().r, this->getColor().g, this->getColor().b, this->getColor().a);

    /*Draw line from point_one to point_two*/
    SDL_RenderDrawLine(window.renderer, this->point_one.x, this->point_one.y, this->point_two.x, this->point_two.y);
}
