#include "Input.h"
#include "Renderer/Window.h"
#include "GLFW/glfw3.h"
#include "Renderer/Renderer.h"

bool Input::IsPressed(int key, Renderer* renderer)
{
	return (glfwGetKey(renderer->GetWindow(), key));
}
