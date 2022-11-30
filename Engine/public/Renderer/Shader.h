#pragma once
#include <string>

class Shader
{
public:
    Shader();
    ~Shader();
    void CompileVertex(std::string path);
    void CompileFragment(std::string path);
    void CompileProgram();
    void Use();
private:
    unsigned int vertex;
    unsigned int fragment;
    unsigned int program;
};

