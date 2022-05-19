#include "Parser.h"

void Parser::serve()
{
	switch (action)
	{
	case Action::READ:
		read();
		break;
	case Action::WRITE:
		write();
		break;
	}
}

void Parser::write()
{
	std::list<std::string> lines;
	std::fstream file;

	file.open(path);
	if (!file.is_open())
	{
		throw std::exception("Open is failure");
	}

	while (!file.eof())
	{
		std::string line;
		getline(file, line);
		lines.push_back(line);
	}

	file.close();

	for (auto it : mapConfig)
	{
		for (auto& line : lines)
		{
			if (it.first._Equal(readParameter(line)))
			{
				line = '[' + it.first + "] = '" + it.second + '\'';
				break;
			}
		}
	}

	file.open(path);
	if (!file.is_open())
	{
		throw std::exception("Open is failure");
	}

	auto linesIterator = lines.begin();
	for (auto& line : lines)
	{
		file << line;
		if (++linesIterator != lines.end())
		{
			file << std::endl;
		}
	}

	file.close();
}

std::map<std::string, std::string> Parser::read()
{
	std::string line;
	std::ifstream readFile(path);

	if (!readFile.is_open())
	{
		throw std::exception("Open is failure");
	}

	for (auto& param : parameters)
	{
		while (!readFile.eof())
		{
			getline(readFile, line);
			if (param._Equal(readParameter(line)))
			{
				mapConfig.emplace(param, readValue(line));
				readFile.seekg(0);
				break;
			}
		}
	}

	readFile.close();

	return mapConfig;
}

std::string	Parser::readParameter(const std::string& line)
{
	const int firstIndex = line.find('[') + 1;
	const int lastIndex = line.find(']') - 1;

	return line.substr(firstIndex, lastIndex);
}

std::string Parser::readValue(const std::string& line)
{
	const int firstIndex = line.find('\'') + 1;
	const int lastIndex = line.find('\'', firstIndex) - firstIndex;

	return line.substr(firstIndex, lastIndex);
}