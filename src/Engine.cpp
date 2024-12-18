#include "Engine.h"
#include "Console.h"
#include "Shader.h"
#include "Entity.h"
#include <vector>

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

    Shader shader(VERTEX_SHADER_SOURCE, FRAGMENT_SHADER_SOURCE);

    init();
    Scene Scene;

    EntityID triangle = Scene.newEntity();

    Scene.Assign<Triangle>(triangle);

    while (!glfwWindowShouldClose(window.get()))
    {
        poll();
        // clear(0.3f, 0.0f, 0.0f);

        // render();
        shader.setActive();
        Scene.getComponent<Triangle>(triangle)->render();
        // update();

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
    for (unsigned int object_index = 0; object_index < render_objects.size(); object_index++)
    {
        // Get object vertices
        float *vertices = render_objects[object_index]->vertices.data();

        // Draw vertices
        render_objects[object_index]->render();
    }
    return;
}

void Engine::update()
{

    return;
}

void Engine::add_render_object(IRender_Object *object)
{
    render_objects.push_back(object);
    return;
}

int Engine::poll()
{
    if (glfwGetKey(window.get(), GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window.get(), true);
    return 0;
}
