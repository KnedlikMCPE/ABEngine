#include "Renderer/Renderer.h"
#include "Renderer/VertexBuffer.h"
#include "Renderer/RenderObject.h"
#include "Renderer/Shader.h"
#include "Renderer/Window.h"
#include "Renderer/VertexArray.h"
#include "Renderer/Texture.h"
#include "Renderer/ElementBuffer.h"

Shader shader;
Texture face;
Texture container;

Renderer::Renderer(int width, int height, const char* title)
{
	window = new Window(width, height, title);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	VAO = new VertexArray();
	VAO->Bind();
	
	VBO = new VertexBuffer();
	VBO->AddAttributes({0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f}, 5, {3, 2});

	EBO = new ElementBuffer( {0, 1, 3, 1, 2, 3});
	
	shader = Shader();
	shader.CompileVertex("shaders/Vertex.vert");
	shader.CompileFragment("shaders/Fragment.frag");
	shader.CompileProgram();
	shader.Use();

	face = Texture("textures/awesomeface.png");
	face.num = 1;
	container = Texture("textures/container.jpg");

	shader.UseUniform("tex1", container.num);
	shader.UseUniform("tex2", face.num);
}



Renderer::~Renderer()
{
	delete window;
	delete VBO;
	delete VAO;
	delete EBO;
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
	container.Bind();
	face.Bind();
	VAO->Bind();
	EBO->Draw();

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
