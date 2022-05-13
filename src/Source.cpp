#include "Startup.h"


int main(int argc, char* args[])
{
	//SDL Initialization
	Startup::init();

	//Fill the surface white
	SDL_FillRect(Startup::getScreenSurface(), NULL, SDL_MapRGB(Startup::getScreenSurface()->format, 0xFF, 0xFF, 0xFF));

	//Update the surface
	SDL_UpdateWindowSurface(Startup::getWindow());

	//Wait two seconds
	SDL_Delay(2000);

	return 0;
}