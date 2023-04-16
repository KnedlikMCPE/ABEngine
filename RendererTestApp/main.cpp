#include "../Renderer/App.h"
#include "../Renderer/PolygonObject.h"
#include <iostream>

char* vertex = "#version 330 core\n"
       				 "layout (location = 0) in vec3 aPos;\n"
       				 "void main()\n"
       				 "{\n"
       				 "	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
       				 "}\0";

char* fragment = "#version 330 core\n"
								 "out vec4 FragColor;\n"
								 "void main()\n"
								 "{\n"
								 "	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
								 "}\0";

int main() {
	printf("Starting app!");
	ABRenderer::App* app = new ABRenderer::App(800, 600, "ABRenderer Test Application");
	ABRenderer::PolygonObject* triangle = new ABRenderer::PolygonObject();

	ABRenderer::Shader shaderProg = ABRenderer::Shader(vertex, fragment);

	triangle->shader = shaderProg;

	float* vertices = new float[9] {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

	triangle->addData(vertices);
	app->registerObject((ABRenderer::RenderObject*) triangle);

	while (!app->shouldClose()) {
		app->render();
	}
	delete app;
}