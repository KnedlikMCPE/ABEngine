#pragma once
#include "RenderObject.h"

class VertexBuffer
{
public:
	VertexBuffer();
	unsigned int GetVBO();
	void Bind();
	
	void AddAttributes(std::vector<float> data, int stride, std::vector<int> sizes);
protected:
	unsigned int VBO;
};