#include "Renderer.h"
#include "Window.h"

Renderer::Renderer(int width, int height, const char* title)
{
	window = new Window(width, height, title);
}

Renderer::~Renderer()
{
	delete window;
}

RendererErrors Renderer::Render()
{
	if (window == nullptr)
	{
		return RendererErrors::WindowNullptr;
	}

	if (shouldClose && !glfwWindowShouldClose(window->GetWindow()))
	{
		glfwSetWindowShouldClose(window->GetWindow(), true);
	}

	if (glfwWindowShouldClose(window->GetWindow()))
	{
		shouldClose = true;
		return RendererErrors::Terminate;
	}

	glfwSwapBuffers(window->GetWindow());
	glfwPollEvents();

	return RendererErrors::Okay;
}