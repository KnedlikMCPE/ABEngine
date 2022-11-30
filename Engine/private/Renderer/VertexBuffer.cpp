#include "Renderer/VertexBuffer.h"
#include <glad/glad.h>

VertexBuffer::VertexBuffer()
{
	glGenBuffers(1, &VBO);
	dataLength = 0;
	numData = 0;

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

void VertexBuffer::AddAttributes(std::vector<float> content, int stride)
{
	Bind();

	glBufferData(GL_ARRAY_BUFFER, sizeof(content), content.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(numData, 3, GL_FLOAT, GL_FALSE, stride * sizeof(float),
    (void*)dataLength);
    glEnableVertexAttribArray(0);

	dataLength += sizeof(content.data());
	numData++;
}
