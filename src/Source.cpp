#include "Global.h"
#include "Services/Configuration/Configurator.h"


int main(int argc, char* args[])
{
	const auto conf = new Configurator(Configurator::Action::INIT);
	SDL_Delay(2000);

	delete conf;
	
	const auto conf2 = new Configurator(Configurator::Action::SCREEN_RESOLUTION_CHANGE, new ScreenSize(320, 240));
	SDL_Delay(2000);

	delete conf2;

	return 0;
}