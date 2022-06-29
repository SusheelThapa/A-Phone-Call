#pragma once

#define WINDOW_HEADER_FILE 1

#ifdef _WIN32
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
// #include <SDL_ttf.h>

#elif __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#endif

#include <iostream>
#include <string>

class Window
{

private:
	std::string title;

	static const int width = 400;

	static const int height = 400;

	bool closed = false;

	SDL_Window *window = nullptr;

	SDL_Event e;

public:
	SDL_Renderer *renderer = nullptr;

private:
	bool init();

public:
	Window();
	Window(std::string);

	~Window();

	void handleEvent();

	void clear(SDL_Color color);

	void present();

	bool isWindowClosed();

	static const int getWidth();

	static const int getHeight();
};
