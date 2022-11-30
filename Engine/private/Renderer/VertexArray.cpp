#include "Renderer/VertexArray.h"
#include "glad/glad.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &VAO);
}

unsigned int VertexArray::GetVAO()
{
    return VAO;
}

void VertexArray::Bind()
{
    glBindVertexArray(VAO);
}
