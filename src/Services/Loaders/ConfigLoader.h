#pragma once
#include "../IService.h"

class ConfigLoader : IService
{
public:
	static enum class Action
	{
		SAVE,
		LOAD
	};

	ConfigLoader(Action action)
	{
		
	}
	void serve() override;

private:

};
