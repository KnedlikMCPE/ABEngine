#pragma once
#include <string>

class Shader
{
public:
    Shader();
    void CompileVertex(std::string path);
    void CompileFragment(std::string path);
private:
    unsigned int vertex;
    unsigned int fragment;
    
};

