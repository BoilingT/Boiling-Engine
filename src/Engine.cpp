#include "Engine.h"
#include "Console.h"

Engine::Engine() : window()
{
    window.init();
}

Engine::~Engine()
{
}

int Engine::start()
{
    Console::log("Starting Engine...");
    window.open();

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        Console::error("Failed to initialize GLAD");
        return -1;
    }

    glViewport(0, 0, window_width, window_height);

    init();

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

World_Object obj(0, 0, 0);

int Engine::init()
{
    Console::log("Initializing Engine...");
    Console::log("Engine Initialized");
    return 0;
}

void Engine::clear(float r, float g, float b)
{
    glClearColor(r, g, b, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Engine::render()
{
    return;
}

void Engine::update()
{
    return;
}

int Engine::poll()
{
    if (glfwGetKey(window.get(), GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window.get(), true);
    return 0;
}
