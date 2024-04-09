#include "Console.h"

void Console::log(std::string content)
{
	std::cout << content << std::endl;
}

void Console::warning(std::string content)
{
	std::cout << "WARNING: " << content << std::endl;
}

void Console::error(std::string content)
{
	std::cout << "ERROR: " << content << std::endl;
}
