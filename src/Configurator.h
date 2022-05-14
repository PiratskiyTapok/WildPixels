#pragma once
class Configurator
{
	friend class MainMenu;

public:
	static void configure();

private:
	static void reboot();
};

