cmake_minimum_required(VERSION 3.30)
enable_testing()
project(boiling_engine VERSION 1.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

set(sources ${sources}
    src/main.cpp
    src/glad.c
    src/Engine.cpp
    src/Console.cpp
    src/Window.cpp
    src/Transform.cpp
    src/Game.cpp
)

add_executable(${PROJECT_NAME} ${sources})

target_link_directories(${PROJECT_NAME} PUBLIC lib/glfw)
target_link_libraries(${PROJECT_NAME} glfw3)

target_include_directories(${PROJECT_NAME} PUBLIC
"${PROJECT_SOURCE_DIR}/include/glad"
"${PROJECT_SOURCE_DIR}/include/GLFW"
"${PROJECT_SOURCE_DIR}/include/glm"
"${PROJECT_SOURCE_DIR}/include/KHR"
"${PROJECT_SOURCE_DIR}/include/STB"
"${PROJECT_SOURCE_DIR}/include"
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)