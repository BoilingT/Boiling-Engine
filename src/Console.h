#pragma once
#include <iostream>
#include <string>

class Console
{
public:
	static void log(std::string);
	static void warning(std::string);
	static void error(std::string);
};

