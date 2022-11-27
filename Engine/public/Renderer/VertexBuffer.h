#pragma once
#include "RenderObject.h"

class VertexBuffer
{
public:
	VertexBuffer(RenderObject data);
	VertexBuffer() {}
	unsigned int GetVBO();
	void Bind();

	RenderObject GetData();
	void SetData(RenderObject value);
protected:
	unsigned int VBO;
	RenderObject data;
};

