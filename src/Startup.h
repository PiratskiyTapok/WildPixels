#pragma once
#include "Global.h"

class Startup
{
	friend class Configurator;

public:
private:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;
	static SDL_Window* window;
	static SDL_Surface* screenSurface;

	static void init();
	static void SDLInit();
	static void SDLImageInit();
	static void SDLSoundInit();
	static void windowInit();
	static void free();
};