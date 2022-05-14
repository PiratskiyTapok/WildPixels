#include "Global.h"
#include "Configurator.h"


int main(int argc, char* args[])
{
	Configurator::configure();

	//Wait two seconds
	SDL_Delay(2000);

	Configurator::configure();

	SDL_Delay(2000);

	return 0;
}