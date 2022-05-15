#pragma once

struct ScreenSize
{
	ScreenSize(int SCREEN_WIDTH, int SCREEN_HEIGHT)
	{
		this->SCREEN_WIDTH = SCREEN_WIDTH;
		this->SCREEN_HEIGHT = SCREEN_HEIGHT;
	}

	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
};