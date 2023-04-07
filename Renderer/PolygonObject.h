#ifndef POLYGON_OBJECT_H
#define POLYGON_OBJECT_H

#include "RenderObject.h"
#include "Shader.h"

namespace ABRenderer {
	class PolygonObject : RenderObject {
	public:
		PolygonObject();
		void addData(float* verticesArray);
		void render();
		Shader shader;
	private:
		unsigned int VAO;
		unsigned int VBO;
		float* vertices;
		int verticesSize;
	};
}

#endif