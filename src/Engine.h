#pragma once
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <vector>

#include "Window.h"

#include "World_object.h"
#include "Triangle.h"

class Engine
{
  private:
    Window window;

    int window_height = 700;
    int window_width  = 700;

    std::vector<World_Object> world_objects;

  public:
    Engine();

    ~Engine();

    int start();

    void clear(float r, float g, float b);

    virtual void update();

    virtual void render();

  private:
    int init();
    int poll();

    // TODO: Pipline: Vertex Data -> *Vertex Shader -> Geometry Shader -> Shape Assembly ...
    // -> Rasterization -> *Fragment Shader

    void add_world_object(World_Object *object);
    void remove_world_object(World_Object *object);
};