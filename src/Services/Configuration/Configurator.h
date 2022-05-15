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
		EFFECT_SOUND_VOLUME_CHANGE
	};

	Configurator(const Action action)
	{
		this->action = action;
		Configurator::serve();
	}

	Configurator(Action action, ScreenSize* screenSize)
	{
		if (action != Action::SCREEN_RESOLUTION_CHANGE)
		{
			throw std::exception("Action is not valid");
		}

		this->screenSize = new ScreenSize(screenSize->SCREEN_WIDTH, screenSize->SCREEN_HEIGHT);
		this->action = action;
		Configurator::serve();
	}

	Configurator(Action action, int volume)
	{
		if (action == Action::MAIN_SOUND_VOLUME_CHANGE)
		{
			mainVolume = volume;
		}
		else if (action == Action::EFFECT_SOUND_VOLUME_CHANGE)
		{
			effectVolume = volume;
		}
		else
		{
			throw std::exception("Action is not valid");
		}

		this->action = action;
		Configurator::serve();
	}

	static void setWindow(SDL_Window* window)
	{
		Configuration::window = window;
	}

	static void setScreenSurface(SDL_Surface* screenSurface)
	{
		Configuration::screenSurface = screenSurface;
	}

	void serve() override;
	
	~Configurator() override
	{
		delete screenSize;
		SDLFree();
	}

private:
	Action action;
	ScreenSize* screenSize = nullptr;
	int mainVolume;
	int effectVolume;
	static void init();
	static void SDLInit();
	static void SDLImageInit();
	static void SDLSoundInit();
	static void windowInit();
	static void SDLFree();
	static void configureScreenResolution(const ScreenSize* screenSize);
	static void configureMainSoundVolume(int volume);
	static void configureEffectSoundVolume(int volume);
};
