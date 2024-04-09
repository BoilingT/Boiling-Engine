#pragma once
#include <GLFW/glfw3.h>
#include <string>
#include "Console.h"

class Window
{
private:
	GLFWwindow* window = nullptr;
	std::string title;

public:
	Window();

	Window(std::string _title);

	~Window()
	{
		glfwTerminate();
	}

	int init();
	int open();
	int setTitle(std::string);
	GLFWwindow* get();
};

