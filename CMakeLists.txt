cmake_minimum_required(VERSION 3.5)

project(glProj)

include_directories(inc)

add_executable(${PROJECT_NAME} src/main.cpp src/Engine.cpp src/Console.cpp src/Window.cpp src/glad.c src/Engine.h src/Console.h src/Window.h)

add_library(glad "lib/glad/glad.c")

target_link_libraries(${PROJECT_NAME} glfw3 glad)
target_link_directories(${PROJECT_NAME} PUBLIC lib/glfw)