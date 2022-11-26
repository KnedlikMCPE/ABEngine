#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"

enum class WindowErrorCode : uint8_t
{
	Okay,
	GlfwWindowFail,
	GladInitFail,
};

class Window
{
public:
	WindowErrorCode code;

	Window(int width, int height, const char* title);
	~Window();
	GLFWwindow* GetWindow();
private:
	GLFWwindow* window;
};