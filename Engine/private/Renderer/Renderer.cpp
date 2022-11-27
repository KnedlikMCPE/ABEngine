#include "Renderer/Renderer.h"
#include "Renderer/VertexBuffer.h"
#include "Renderer/RenderObject.h"
#include "Renderer/Window.h"

Renderer::Renderer(int width, int height, const char* title)
{
	window = new Window(width, height, title);
	VBO = new VertexBuffer(RenderObject({-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f}));
}



Renderer::~Renderer()
{
	delete window;
	delete VBO;
}



RendererErrors Renderer::Render()
{
	if (window == nullptr)
	{
		return RendererErrors::WindowNullptr;
	}

	glfwSwapBuffers(window->GetWindow());
	glfwPollEvents();

	if (shouldClose && !glfwWindowShouldClose(window->GetWindow()))
	{
		glfwSetWindowShouldClose(window->GetWindow(), true);
	}

	if (glfwWindowShouldClose(window->GetWindow()))
	{
		shouldClose = true;
		return RendererErrors::Terminate;
	}

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	return RendererErrors::Okay;
}



GLFWwindow* Renderer::GetWindow()
{
	return window->GetWindow();
}



void Renderer::Close()
{
	shouldClose = true;
}

