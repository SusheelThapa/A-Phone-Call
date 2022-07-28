#pragma once

#define WINDOW_HEADER_FILE 1

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <string>

enum PhoneScreen
{
	DIALPAD,
	INCOMING_CALL,
	OUTGOING_CALL,
};

class Window
{

private:
	std::string title;

	static const int width = 414;

	static const int height = 736;

	bool closed = false;

	SDL_Window *window = nullptr;

public:
	SDL_Renderer *renderer = nullptr;
	PhoneScreen screen;

private:
	bool init();

public:
	Window();
	Window(std::string);

	~Window();

	void handleEvent(SDL_Event &);

	void clear(SDL_Color color);

	void present();

	bool isWindowClosed();

	static const int getWidth();

	static const int getHeight();

public:
};
