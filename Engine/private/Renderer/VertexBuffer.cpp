#include "Renderer/VertexBuffer.h"

#include <iostream>
#include <glad/glad.h>

VertexBuffer::VertexBuffer()
{
	glGenBuffers(1, &VBO);
	numData = 0;
	stride = 0;

	Bind();
}

unsigned VertexBuffer::GetVBO()
{
	return VBO;
}

void VertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

void VertexBuffer::AddData(std::vector<float> data, int strideIn)
{
	content = data;
	stride = strideIn;
	numData = stride / 3;
}

void VertexBuffer::AddAttributes()
{
	BufferData();
	for (int i = 0; i < numData; i++)
	{
		glVertexAttribPointer(i, 3, GL_FLOAT, GL_FALSE, stride * sizeof(float),
		(void*)(i * 3));
		glEnableVertexAttribArray(i);
	}
}

void VertexBuffer::BufferData()
{
	Bind();
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * content.size(), content.data(), GL_STATIC_DRAW);
}
