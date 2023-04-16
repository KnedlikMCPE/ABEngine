cmake_minimum_required(VERSION 3.5)
project(RendererProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Build GLFW library
add_subdirectory(glfw)

# Find OpenGL library
find_package(OpenGL REQUIRED)
if(NOT OPENGL_FOUND)
    message(FATAL_ERROR "OpenGL library not found")
endif()

# Renderer dynamic library
add_subdirectory(Renderer)

# RendererTestApp
add_subdirectory(RendererTestApp)
