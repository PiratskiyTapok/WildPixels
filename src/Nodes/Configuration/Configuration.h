#pragma once
#include <SDL.h>
#include "../../Global.h"

class Configuration
{
	friend class Configurator;

public:
	static ScreenSize* getScreenSize()
	{
		return screenSize;
	}
	static int getMainSoundVolume()
	{
		return mainVolume;
	}
	static int getEffectSoundVolume()
	{
		return effectVolume;
	}
	static SDL_Window* getWindow()
	{
		return window;
	}
	static SDL_Surface* getScreenSurface()
	{
		return screenSurface;
	}
	static void freeWindow()
	{
		SDL_DestroyWindow(window);
		window = nullptr;
		screenSize = nullptr;
	}

	static void freeStorage()
	{
		delete screenSize;
		freeWindow();
		window = nullptr;
		screenSize = nullptr;
	}
private:
	static ScreenSize* screenSize;
	static int mainVolume;
	static int effectVolume;
	static SDL_Window* window;
	static SDL_Surface* screenSurface;
};
