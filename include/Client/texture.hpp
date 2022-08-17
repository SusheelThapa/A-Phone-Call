/*

C++ Object Oriented Programming Final Project
Dept. of Electronics and Computer Engineering

Author : Susheel Thapa Saurav Kumar Mahato
Class : BCT CD 090 BCT CD 079
Semester : Third Semester

Filename : texture.cpp
Categories : C++ Header File
Description : It is used to handle all the images that will be used in the project.
*/

#pragma once

/*Custom Header file*/
#include <Client/window.hpp>

class Texture
{

private:
	SDL_Texture *texture = nullptr;

	int width;

	int height;

private:
	void free();

public:
	Texture();

#if defined SDL_IMAGE_MAJOR_VERSION

	Texture(Window &, std::string);

#endif

#if defined(SDL_TTF_MAJOR_VERSION)

	Texture(Window &, std::string, TTF_Font *, SDL_Color);

#endif

	~Texture();

#if defined SDL_IMAGE_MAJOR_VERSION

	bool loadFromFile(Window &window, std::string);

#endif

#if defined(SDL_TTF_MAJOR_VERSION)

	bool loadFromText(Window &window, TTF_Font *font, std::string text, SDL_Color color);

#endif

	int getWidth();

	int getHeight();

	void render(Window &window, int x, int y, SDL_Rect *render_rect = NULL, SDL_Rect *render_quad = nullptr, double angle = 0.0, SDL_Point *center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
};
