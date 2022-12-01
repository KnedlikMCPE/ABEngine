#include "Renderer/Texture.h"
#include "glad/glad.h"
#define STB_IMAGE_IMPLEMENTATION
#include <iostream>

#include "stb_image.h"

Texture::Texture(std::string path)
{
    stbi_set_flip_vertically_on_load(true);
    num = 0;
    
    glGenTextures(1, &texture);

    data = stbi_load(path.c_str(),  &width, &height, &nrChannels, 0);

    if (!data)
    {
        std::cout << "FAILED TO LOAD TEXTURE: " << path << std::endl;
        return;
    }

    GLenum format = GL_RGBA;
    if (nrChannels == 1) format = GL_RED;
    if (nrChannels == 2) format = GL_RG;
    if (nrChannels == 3) format = GL_RGB;
    if (nrChannels == 4) format = GL_RGBA;

    Bind();
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
}

void Texture::Bind()
{
    glActiveTexture(GL_TEXTURE0 + num);
    glBindTexture(GL_TEXTURE_2D, texture);
}
