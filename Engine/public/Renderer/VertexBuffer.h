#pragma once
#include "RenderObject.h"

class VertexBuffer
{
public:
	VertexBuffer();
	unsigned int GetVBO();
	void Bind();

	void AddData(std::vector<float> data, int stride);
	void AddAttributes();
protected:
	unsigned int VBO;
	int stride;
	int numData;
	std::vector<float> content;

	void BufferData();
};