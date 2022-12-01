#pragma once
#include <vector>

class ElementBuffer
{
public:
    ElementBuffer(std::vector<unsigned int> indices);
    void Bind();
    void Draw();
private:
    unsigned int EBO;
    int amount;
};
