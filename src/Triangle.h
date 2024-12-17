#pragma once
#include <glad/glad.h>

class Render_Object
{
    virtual void render()
    {
        return;
    }
};

class Triangle : public Render_Object
{
  private:
    float vertices[0];
    // Buffers
    unsigned int VBO, VAO, EBO;

    Triangle()
    {
        // Send vertex data to GPU
        glGenBuffers(1, &VBO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        // Save configuration in a Vertex array object
        glGenBuffers(1, &VAO);

        glBindVertexArray(VAO);

        // Element buffer object (Optimization)
        glGenBuffers(1, &EBO);

        glBindBuffer(GL_ARRAY_BUFFER, EBO);
    }

  public:
    void render()
    {
        return;
    }
};