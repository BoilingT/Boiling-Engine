#include "Window.h"

Window::Window()
{
    title = "Window";
}

Window::Window(std::string _title)
{
    title = _title;
}

int Window::init()
{
    // Init
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    return 0;
}

int Window::open()
{
    // Open window
    window = glfwCreateWindow(700, 700, title.c_str(), NULL, NULL);
    if (!window)
    {
        Console::error("Failed to create window");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    return 0;
}

GLFWwindow *Window::get()
{
    return this->window;
}

int Window::setTitle(std::string _title)
{
    glfwSetWindowTitle(window, _title.c_str());
    return 0;
}
