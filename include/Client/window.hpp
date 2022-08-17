/*

C++ Object Oriented Programming Final Project
Dept. of Electronics and Computer Engineering

Author : Susheel Thapa Saurav Kumar Mahato
Class : BCT CD 090 BCT CD 079
Semester : Third Semester

Filename : window.cpp
Categories : C++ Header File
Description : It is used to render the window of the project.
*/

#pragma once

/*SDL2 Header file*/
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

/*Standard C++ Header file*/
#include <iostream>
#include <string>

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
};
