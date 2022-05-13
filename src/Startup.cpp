#include "Startup.h"
#include <iostream>

int Startup::SCREEN_WIDTH = 640;
int Startup::SCREEN_HEIGHT = 480;
SDL_Window* Startup::window = nullptr;
SDL_Surface* Startup::screenSurface = nullptr;

void Startup::init()
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) //How to work exceptions?
	{
		std::string error = "SDL could not initialize! SDL_Error: " + std::string(SDL_GetError());
		throw error;
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (!window)
		{
			std::string error = "Window could not be created! SDL_Error: " + std::string(SDL_GetError());
			throw error;
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);
		}
	}
}
void Startup::free()
{
	//Destroy window
	SDL_DestroyWindow(window);
	window = nullptr;

	//Quit SDL subsystems
	SDL_Quit();
}
