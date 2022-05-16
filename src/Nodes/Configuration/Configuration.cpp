#include "Configuration.h"

//change start config
ScreenSize* Configuration::screenSize = new ScreenSize(640, 480);
int Configuration::mainVolume = 100;
int Configuration::effectVolume = 100;
SDL_Window* Configuration::window = nullptr;
SDL_Surface* Configuration::screenSurface = nullptr;