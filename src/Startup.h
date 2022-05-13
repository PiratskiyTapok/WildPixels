#pragma once

#include "Global.h"

class Startup
{
public:
	static void init();
	static void free();

	static SDL_Window* getWindow()
	{
		return window;
	}

	static SDL_Surface* getScreenSurface()
	{
		return screenSurface;
	}

private:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;
	static SDL_Window* window;
	static SDL_Surface* screenSurface;
};