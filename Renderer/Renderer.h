#pragma once
#include "Macros.h"

class Window;

enum class RENDERER_EXPORT RendererErrors
{
	Okay,
	Terminate,
	WindowNullptr,
};

class RENDERER_EXPORT Renderer
{
public:
	bool shouldClose;

	Renderer(int width, int height, const char* title);
	~Renderer();
	RendererErrors Render();
private:
	Window* window;
};

