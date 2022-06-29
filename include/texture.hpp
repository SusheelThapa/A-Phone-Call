/*

Author : Susheel Thapa

Filename : texture.hpp

A custom made class which helps you with image loading over window
surface or a part of the window, loading text over the window,etc

*/

#pragma once

#define TEXTURE_HEADER_FILE 1

#ifndef WINDOW_HEADER_FILE
#include "window.hpp"
#endif

class Texture
{

private:
	// private variables

	SDL_Texture *texture = nullptr;

	int width;

	int height;

public:
	// public variables

private:
	// private functions

	void free();

public:
	// public functions

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
