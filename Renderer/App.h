#ifndef RENDER_APP_H
#define RENDER_APP_H

#include "RenderObject.h"

struct GLFWwindow;

namespace ABRenderer {
	enum AppErrorType {
		OK,
		GLFW_WINDOW_FAIL,
		GLAD_INIT_FAIL
	};

	class App {
	public:
		App(int width, int height, char* title);
		~App();
		void render();
		bool shouldClose();
		void registerObject(RenderObject* object);
		void deRegisterObject(int index);
		void deRegisterObject(RenderObject* object);

		AppErrorType error = AppErrorType::OK;
	private:
		GLFWwindow* window;
		RenderObject** renderObjects;
		int renderObjectsSize;
	};
}

#endif