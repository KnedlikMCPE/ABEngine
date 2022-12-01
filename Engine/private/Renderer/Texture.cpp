#include "Renderer/Texture.h"
#include "glad/glad.h"
#define STB_IMAGE_IMPLEMENTATION
#include <iostream>

#include "stb_image.h"

Texture::Texture(std::string path)
{
    glGenTextures(1, &texture);

    data = stbi_load(path.c_str(),  &width, &height, &nrChannels, 0);

    if (!data)
    {
        std::cout << "FAILED TO LOAD TEXTURE: " << path << std::endl;
        return;
    }

    std::cout << data;

    Bind();
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
}

void Texture::Bind()
{
    glBindTexture(GL_TEXTURE_2D, texture);
}
