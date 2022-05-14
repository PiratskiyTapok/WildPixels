#include "Configurator.h"
#include "Startup.h"

int Startup::SCREEN_WIDTH = 640;
int Startup::SCREEN_HEIGHT = 480;

void Configurator::configure()
{
	reboot();
}

void Configurator::reboot()//For example when configure window size
{
	Startup::free();
	Startup::init();
}
