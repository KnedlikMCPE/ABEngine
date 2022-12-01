#pragma once
#include <string>

class Texture
{
public:
    Texture(std::string path);
    Texture() {}
    void Bind();
private:
    int width;
    int height;
    int nrChannels;
    unsigned char *data;
    unsigned int texture;
};
