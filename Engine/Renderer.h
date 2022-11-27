#pragma once
#include "VertexBuffer.h"
#include "Macros.h"

class Window;
struct GLFWwindow;

enum class RendererErrors
{
	Okay,
	Terminate,
	WindowNullptr,
};

class Renderer
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
	VertexBuffer VBO;
};

