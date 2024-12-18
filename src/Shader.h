#pragma once
#include <glad/glad.h>

#include <string>

#define INFO_LOG_BUFFER_SIZE 512

class Shader
{
  public:
    unsigned int ID;

    Shader(const std::string vertex_shader_src, const std::string fragment_shader_src);

    std::string  readFile(std::string source);
    int          compileShader(unsigned int shader, const char *shader_code);
    unsigned int createShaderProgram(unsigned int vertex_shader, unsigned int fragment_shader);

    void setActive();

    void setBool(const std::string &name, bool value) const;
    void setFloat(const std::string &name, float value) const;
    void setInt(const std::string &name, int value) const;
};