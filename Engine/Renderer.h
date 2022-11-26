#pragma once
#include "Macros.h"

class Window;
struct GLFWwindow;

enum class AB_EXPORT RendererErrors
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
};

