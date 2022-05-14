#include "Startup.h"
#include <iostream>

SDL_Window* Startup::window = nullptr;
SDL_Surface* Startup::screenSurface = nullptr;

void Startup::init()
{
	SDLInit();
	windowInit();
}

void Startup::SDLInit()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		const std::string error = "SDL could not initialize! SDL_Error: " + std::string(SDL_GetError());
		throw std::exception(error.c_str());
	}
}

void Startup::SDLImageInit()
{
}

void Startup::SDLSoundInit()
{
}

void Startup::windowInit()
{
	//Create window
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!window)
	{
		const std::string error = "Window could not be created! SDL_Error: " + std::string(SDL_GetError());
		throw std::exception(error.c_str());
	}
	else
	{
		//Get window surface
		screenSurface = SDL_GetWindowSurface(window);
	}
}

void Startup::free()
{
	//Destroy window
	if (window)
	{
		SDL_DestroyWindow(window);
		window = nullptr;
	}

	//Quit SDL subsystems
	SDL_Quit();
}
