#pragma once
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <string>

#include "../IService.h"

class Parser : public IService
{
public:
	static enum class Action
	{
		READ,
		WRITE
	};

	Parser(const Action action, const std::string path, std::map<std::string, std::string>& mapConfig) : Parser(action, path)
	{
		this->mapConfig = mapConfig;
	}

	Parser(const Action action, const std::string path, const std::list<std::string>& parameters) : Parser(action, path)
	{
		this->parameters = parameters;
	}

	void serve() override;

	~Parser() override = default;

private:
	Parser(const Action action, const std::string path)
	{
		this->action = action;
		this->path = path;
		Parser::serve();
	}

	Action action;
	std::string path;
	std::list<std::string> parameters;
	std::map<std::string, std::string> mapConfig;

	void write();
	std::map<std::string, std::string> read();
	std::string	readParameter(const std::string& line);
	std::string readValue(const std::string& line);
};
