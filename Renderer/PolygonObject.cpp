#include "PolygonObject.h"
#include "iostream"
#include <glad/glad.h>

using namespace ABRenderer;

PolygonObject::PolygonObject() {
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &VAO);
}

void PolygonObject::addData(float* verticesArray) {
	vertices = verticesArray;

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, verticesSize * sizeof(float), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
	glEnableVertexAttribArray(0);
}

void PolygonObject::render() {
	glUseProgram(shader.program);

	glBindVertexArray(VAO);

	glDrawArrays(GL_TRIANGLES, 0, 3);
}