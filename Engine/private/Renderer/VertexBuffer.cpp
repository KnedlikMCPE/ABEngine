#include "Renderer/VertexBuffer.h"

#include <iostream>
#include <glad/glad.h>

VertexBuffer::VertexBuffer()
{
	glGenBuffers(1, &VBO);

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

void VertexBuffer::AddAttributes(std::vector<float> data, int stride, std::vector<int> sizes)
{
	Bind();
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), data.data(), GL_STATIC_DRAW);
	
	int numData = sizes.size();
	int sizeData = 0;
	
	for (int i = 0; i <= numData; i++)
	{
		glVertexAttribPointer(i, sizes.data()[i], GL_FLOAT, GL_FALSE, stride * sizeof(float),
		(void*)(i * sizeData));
		glEnableVertexAttribArray(i);
		sizeData += sizes.data()[i];
	}
}
