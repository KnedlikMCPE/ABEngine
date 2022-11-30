#pragma once
#include "Macros.h"

class Window;
class VertexBuffer;
class VertexArray;
struct GLFWwindow;

enum class RendererErrors
{
	Okay,
	Terminate,
	WindowNullptr,
};

class AB_EXPORT Renderer
{
public:
	bool shouldClose;

	Renderer(int width, int height, const char* title);
	~Renderer();
	RendererErrors Render();
	GLFWwindow* GetWindow();
	void Close();
private:
	Window* window;
	VertexBuffer* VBO;
	VertexArray* VAO;

	void Draw();
};

