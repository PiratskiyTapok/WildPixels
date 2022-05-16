#include "Configurator.h"

void Configurator::serve()
{
	switch (action)
	{
	case Action::INIT:
		init();
		break;
	case Action::SCREEN_RESOLUTION_CHANGE:
		configureScreenResolution();
		break;
	case Action::MAIN_SOUND_VOLUME_CHANGE:
		configureMainSoundVolume();
		break;
	case Action::EFFECT_SOUND_VOLUME_CHANGE:
		configureEffectSoundVolume();
		break;
	case Action::QUIT:
		quit();
		break;
	}
}

void Configurator::init()
{
	SDLInit();
	SDLImageInit();
	SDLSoundInit();
	windowInit();
}

void Configurator::SDLInit()
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		const std::string error = "SDL could not initialize! SDL_Error: " + std::string(SDL_GetError());
		throw std::exception(error.c_str());
	}
}

void Configurator::SDLImageInit()
{
	//Initialize PNG loading
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		const std::string error = "SDL_image could not initialize! SDL_image Error: " + std::string(IMG_GetError());
		throw std::exception(error.c_str());
	}
}

void Configurator::SDLSoundInit()
{
	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		const std::string error = "SDL_mixer could not initialize! SDL_mixer Error: " + std::string(Mix_GetError());
		throw std::exception(error.c_str());
	}
}

void Configurator::windowInit()
{
	//Create window
	SDL_Window* window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, Configuration::getScreenSize()->SCREEN_WIDTH,
		Configuration::getScreenSize()->SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!window)
	{
		const std::string error = "Window could not be created! SDL_Error: " + std::string(SDL_GetError());
		throw std::exception(error.c_str());
	}

	//Set window
	storeWindow(window);
	//Get window surface
	storeScreenSurface(SDL_GetWindowSurface(window));
}

void Configurator::quit()
{
	Configuration::freeStorage();

	//Quit SDL subsystems
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

void Configurator::configureScreenResolution()
{
	if (!screenSize)
	{
		throw std::exception("Action is not valid");
	}

	Configuration::screenSize->SCREEN_WIDTH = screenSize->SCREEN_WIDTH;
	Configuration::screenSize->SCREEN_HEIGHT = screenSize->SCREEN_HEIGHT;
	Configuration::freeWindow();
	windowInit();
}

void Configurator::configureMainSoundVolume()
{
	if (volume == -1)
	{
		throw std::exception("Action is not valid");
	}
}

void Configurator::configureEffectSoundVolume()
{
	if (volume == -1)
	{
		throw std::exception("Action is not valid");
	}
}
