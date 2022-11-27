#include "Renderer/VertexBuffer.h"
#include <glad/glad.h>

VertexBuffer::VertexBuffer(RenderObject dataIn)
{
	glGenBuffers(1, &VBO);

	Bind();
	SetData(dataIn);
}

unsigned VertexBuffer::GetVBO()
{
	return VBO;
}

void VertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

RenderObject VertexBuffer::GetData()
{
	return data;
}

void VertexBuffer::SetData(RenderObject value)
{
	data = value;
	Bind();
	glBufferData(GL_ARRAY_BUFFER, sizeof(data.vertices.data()), data.vertices.data(), GL_STATIC_DRAW);
}
