#pragma once

class VertexArray
{
public:
    VertexArray();
    unsigned int GetVAO();

    void Bind();
private:
    unsigned int VAO;
};
