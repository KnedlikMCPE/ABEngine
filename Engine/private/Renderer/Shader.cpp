#include "Renderer/Shader.h"

#include <iostream>
#include <glad/glad.h>
#include "Utils.h"

Shader::Shader()
{
    
}

void Shader::CompileVertex(std::string path)
{
    const char* code = ABEngine::Utils::ReadFile(path).c_str();
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &code, NULL);
    glCompileShader(vertex);
    
    int success;
    char infoLog[512];
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cout << "ERROR: VERTEX COMPILATION FAILED" << std::endl << infoLog << std::endl;
    }
}

void Shader::CompileFragment(std::string path)
{
    const char* code = ABEngine::Utils::ReadFile(path).c_str();
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &code, NULL);
    glCompileShader(fragment);
    
    int success;
    char infoLog[512];
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        std::cout << "ERROR: FRAGMENT COMPILATION FAILED" << std::endl << infoLog << std::endl;
    }
}
