#include "Renderer/ElementBuffer.h"
#include "glad/glad.h"

ElementBuffer::ElementBuffer(std::vector<unsigned int> indices)
{
    glGenBuffers(1, &EBO);
    amount = indices.size();
    Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), indices.data(),  GL_STATIC_DRAW);
}

void ElementBuffer::Bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
}

void ElementBuffer::Draw()
{
    Bind();
    glDrawElements(GL_TRIANGLES, amount, GL_UNSIGNED_INT, 0);
}
