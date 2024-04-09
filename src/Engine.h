#pragma once
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "Console.h"
#include "Window.h"

class Engine
{
private:
	Window window;

public:
	Engine();

	~Engine();

	int start();

private:
	int update();
	int poll();
	int render();
};

