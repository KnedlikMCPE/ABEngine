#pragma once
#include <string>
#include "Vector3.h"

class Shader
{
public:
    Shader();
    ~Shader();
    void CompileVertex(std::string path);
    void CompileFragment(std::string path);
    void CompileProgram();

    void UseUniform(std::string name, bool value);
    void UseUniform(std::string name, float value);
    void UseUniform(std::string name, int value);
    void UseUniform(std::string name, Vector3 value);

    void Use();

private:
    unsigned int vertex;
    unsigned int fragment;
    unsigned int program;
};
