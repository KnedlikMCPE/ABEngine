#include "Renderer/Renderer.h"
#include "Renderer/VertexBuffer.h"
#include "Renderer/RenderObject.h"
#include "Renderer/Shader.h"
#include "Renderer/Window.h"
#include "Renderer/VertexArray.h"

Shader shader;

Renderer::Renderer(int width, int height, const char* title)
{
	window = new Window(width, height, title);

	VAO = new VertexArray();
	VAO->Bind();
	
	VBO = new VertexBuffer();
	VBO->AddAttributes({-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f}, 3);
	
	shader = Shader();
	shader.CompileVertex("shaders/Vertex.vert");
	shader.CompileFragment("shaders/Fragment.frag");
	shader.CompileProgram();
}



Renderer::~Renderer()
{
	delete window;
	delete VBO;
	delete VAO;
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

	shader.Use();
	VAO->Bind();
	Draw();

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



void Renderer::Draw()
{
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
