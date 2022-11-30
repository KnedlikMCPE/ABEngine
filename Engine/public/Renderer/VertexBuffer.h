#pragma once
#include "RenderObject.h"

class VertexBuffer
{
public:
	VertexBuffer();
	unsigned int GetVBO();
	void Bind();

	void AddData(std::vector<float> data);
	void AddAttributes();
protected:
	unsigned int VBO;
	int stride;
	int numData;
	std::vector<float> content;

	void BufferData();
};