#include "OpenGL_Texture.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

OpenGL_Texture::OpenGL_Texture(const std::string& texture_path) {
    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_2D, m_textureID); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    int width, height, nrChannels;
    unsigned char *data = stbi_load(texture_path.c_str(), &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data); 
}

OpenGL_Texture::~OpenGL_Texture() {}

GLuint OpenGL_Texture::getID() const { return m_textureID; }
