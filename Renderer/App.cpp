#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "App.h"
#include <cstring>

using namespace ABRenderer;

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
  glViewport(0, 0, width, height);
}

App::App(int width, int height, char* title) {
    renderObjects = new RenderObject*[0];

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        window = glfwCreateWindow(width, height, title, NULL, NULL);
        if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
            error = AppErrorType::GLFW_WINDOW_FAIL;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        error = AppErrorType::GLAD_INIT_FAIL;
        return;
    }

    glViewport(0, 0, width, height);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

void App::registerObject(RenderObject* object) {
    renderObjectsSize++;

    RenderObject** tempArray = new RenderObject*[renderObjectsSize];
    memcpy(tempArray, renderObjects, (renderObjectsSize - 1) * sizeof(int*));

    delete[] renderObjects;
    renderObjects = tempArray;

    renderObjects[renderObjectsSize - 1] = object;
}

bool App::shouldClose() {
    return glfwWindowShouldClose(window);
}

void App::render() {
    printf("Rendering!");
    if (error != OK) {
        std::cout << "ERROR: " << error << std::endl;
        return;
    }

    printf("Clearing!");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i < renderObjectsSize; i++) {
        if (renderObjects[i] == nullptr) {
            continue;
        }
        printf("Rendering an object!");
        renderObjects[i]->render();
    }

    printf("Swapping buffers!");
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void App::deRegisterObject(int index) {
    delete renderObjects[index];

    renderObjectsSize--;

    RenderObject** tempArray = new RenderObject*[renderObjectsSize];
    memcpy(tempArray, renderObjects, index * sizeof(int*));
    memcpy(tempArray + index, renderObjects + index + 1, renderObjectsSize - index - 1);

    delete[] renderObjects;
    renderObjects = tempArray;
}

void App::deRegisterObject(RenderObject* object) {
    for (int i = 0; i < renderObjectsSize; i++) {
        if (renderObjects[i] == object) {
            deRegisterObject(i);
        }
    }
}

App::~App() {
    delete[] renderObjects;

    glfwTerminate();
}