cmake_minimum_required(VERSION 3.5)
project(RendererTestApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# RendererTestApp executable
add_executable(RendererTestApp
    main.cpp
)

# Link GLFW, OpenGL, and Renderer dynamic library
target_link_libraries(RendererTestApp PRIVATE
    glfw
    OpenGL::GL
    Renderer
)
