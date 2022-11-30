#pragma once
#include "RenderObject.h"

class VertexBuffer
{
public:
	VertexBuffer();
	unsigned int GetVBO();
	void Bind();

	void AddAttributes(std::vector<float> content, int stride);
protected:
	unsigned int VBO;
	int dataLength;
	int numData;
};