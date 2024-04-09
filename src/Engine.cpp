#include "Engine.h"

Engine::Engine() : window()
{
	Console::log("Initializing Engine...");

	window.init();

	Console::log("Engine Initialized");
}

Engine::~Engine()
{
}

int Engine::start()
{
	Console::log("Starting Engine...");
	window.open();

	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
	{
		Console::error("Failed to initialize GLAD");
		return -1;
	}

	glViewport(0, 0, 700, 700);


	while (!glfwWindowShouldClose(window.get()))
	{
		poll();
		render();
		update();

		glfwPollEvents();
		glfwSwapBuffers(window.get());
	}

	Console::log("Engine Stopped");

	return 0;
}

int Engine::render()
{
	glClearColor(0.1f, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	return 0;
}

int Engine::update()
{
	return 0;
}

int Engine::poll()
{
	if (glfwGetKey(window.get(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window.get(), true);
	return 0;
}

