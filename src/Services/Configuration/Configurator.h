#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "../../Global.h"
#include "../IService.h"
#include "Configuration.h"


class Configurator : public IService
{
public:
	static enum class Action
	{
		INIT,
		SCREEN_RESOLUTION_CHANGE,
		MAIN_SOUND_VOLUME_CHANGE,
		EFFECT_SOUND_VOLUME_CHANGE,
		QUIT
	};

	Configurator(const Action action)
	{
		this->action = action;
		Configurator::serve();
	}

	Configurator(Action action, const ScreenSize* screenSize) : Configurator(action)
	{
		this->screenSize = new ScreenSize(screenSize->SCREEN_WIDTH, screenSize->SCREEN_HEIGHT);
	}

	Configurator(Action action, int volume) : Configurator(action)
	{
		this->volume = volume;
	}

	static void storeWindow(SDL_Window* window)
	{
		Configuration::window = window;
	}

	static void storeScreenSurface(SDL_Surface* screenSurface)
	{
		Configuration::screenSurface = screenSurface;
	}

	void serve() override;
	
	~Configurator() override
	{
		delete screenSize;
	}

private:
	Action action;
	ScreenSize* screenSize = nullptr;
	int volume = -1;
	void init();
	void SDLInit();
	void SDLImageInit();
	void SDLSoundInit();
	void windowInit();
	void quit();
	void configureScreenResolution();
	void configureMainSoundVolume();
	void configureEffectSoundVolume();
};
