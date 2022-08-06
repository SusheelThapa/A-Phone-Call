#include "Client/phonefont.hpp"

PhoneFont::PhoneFont()
{
    /*Loading the TTF Font*/
    big_font = TTF_OpenFont("resources/fonts/freesans.ttf", 56);
    medium_font = TTF_OpenFont("resources/fonts/freesans.ttf", 32);
}

PhoneFont::~PhoneFont()
{
    TTF_CloseFont(big_font);
    TTF_CloseFont(medium_font);
}

TTF_Font *PhoneFont::getBigFont()
{
    return big_font;
};

TTF_Font *PhoneFont::getMediumFont()
{
    return medium_font;
};
