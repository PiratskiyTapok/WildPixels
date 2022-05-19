#pragma once
#include <SDL.h>
#include "../../GlobalStructures.h"

class Configuration
{
public:
	Configuration()
	{
		screenSize = nullptr;
		window = nullptr;
		screenSurface = nullptr;
		mainVolume = -1;
		effectVolume = -1;
	}
	Configuration(const Configuration &obj)
	{
		this->screenSize = new ScreenSize(obj.screenSize->SCREEN_WIDTH, obj.screenSize->SCREEN_HEIGHT);
		window = 
	}
	~Configuration()
	{
		delete screenSize;
		SDL_DestroyWindow(window);

		window = nullptr;
		screenSize = nullptr;
	}

private:
	ScreenSize* screenSize;
	SDL_Window* window;
	SDL_Surface* screenSurface;
	int mainVolume;
	int effectVolume;
};
