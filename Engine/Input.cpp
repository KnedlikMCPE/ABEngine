#include "Input.h"

#include "Window.h"
#include "GLFW/glfw3.h"

bool Input::IsPressed(int key, Renderer* renderer)
{
	return (glfwGetKey(renderer->GetWindow(), key));
}
