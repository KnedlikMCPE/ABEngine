#include "Renderer/Shader.h"

#include <iostream>
#include <glad/glad.h>
#include "Utils.h"

Shader::Shader()
{
    
}

Shader::~Shader()
{
    if (vertex != NULL)
    {
        glDeleteShader(vertex);
    }

    if (fragment != NULL)
    {
        glDeleteShader(fragment);
    }

    if (program != NULL)
    {
        glDeleteProgram(program);
    }
}


void Shader::CompileVertex(std::string path)
{
    std::string codeStr = ABEngine::Utils::ReadFile(path);
    const char* code = codeStr.c_str();
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
    std::string codeStr = ABEngine::Utils::ReadFile(path);
    const char* code = codeStr.c_str();
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

void Shader::CompileProgram()
{
    if (vertex == NULL || fragment == NULL)
    {
        std::cout << "VERTEX OR FRAGMENT IS NULL" << std::endl;
        return;
    }

    program = glCreateProgram();
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);
}

void Shader::Use()
{
    glUseProgram(program);
}
