cmake_minimum_required(VERSION 3.5)
project(Renderer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Renderer static library
add_library(Renderer STATIC
    App.cpp glad.cpp PolygonObject.cpp RenderObject.cpp Shader.cpp
)

include_directories(include)

target_link_libraries(Renderer PRIVATE
    glfw
    OpenGL::GL
)