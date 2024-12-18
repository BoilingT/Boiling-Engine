#include "Shader.h"
#include <cstddef>
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const std::string vertex_shader_src, const std::string fragment_shader_src)
{
    unsigned int vertex_shader, fragment_shader;

    // Read contents of given files
    std::string vertex_shader_string = readFile(vertex_shader_src);
    if (vertex_shader_string.empty())
    {
        std::cout << "ERROR::VERTEX_SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        return;
    }

    std::string fragment_shader_string = readFile(fragment_shader_src);
    if (fragment_shader_string.empty())
    {
        std::cout << "ERROR::FRAGMENT_SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        return;
    }

    // Create shaders
    vertex_shader   = glCreateShader(GL_VERTEX_SHADER);
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

    // Compile shaders
    int  success;
    char infoLog[INFO_LOG_BUFFER_SIZE];

    success = compileShader(vertex_shader, vertex_shader_string.c_str());

    if (!success)
    {
        glGetProgramInfoLog(vertex_shader, sizeof(infoLog), NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX_COMPILATION_FAILURE\n" << infoLog << std::endl;
    }

    success = compileShader(fragment_shader, fragment_shader_string.c_str());

    if (!success)
    {
        glGetProgramInfoLog(fragment_shader, sizeof(infoLog), NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX_COMPILATION_FAILURE\n" << infoLog << std::endl;
    }

    ID = createShaderProgram(vertex_shader, fragment_shader);
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}

std::string Shader::readFile(std::string source)
{
    std::ifstream file;
    // Ensure ifstream objects can throw exceptions:
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        file.open(source);
        std::stringstream file_stream;
        file_stream << file.rdbuf();
        return file_stream.str();
    }
    catch (std::ifstream::failure error)
    {
        std::cout << error.what() << std::endl;
        return std::string();
    }
}

int Shader::compileShader(unsigned int shader, const char *shader_code)
{
    int  success;
    char infoLog[INFO_LOG_BUFFER_SIZE];

    glShaderSource(shader, 1, &shader_code, NULL);
    glCompileShader(shader);

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        return 0;
    }

    return 1;
}

unsigned int Shader::createShaderProgram(unsigned int vertex_shader, unsigned int fragment_shader)
{
    unsigned int program = glCreateProgram();
    int          success;
    char         infoLog[INFO_LOG_BUFFER_SIZE];

    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        return 0;
    }

    return program;
}

void Shader::setActive()
{
    glUseProgram(ID);
    return;
}

void Shader::setBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
    return;
}
void Shader::setFloat(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
    return;
}
void Shader::setInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);

    return;
}