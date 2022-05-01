#ifndef OPENGL_TEXTURE_HPP
#define OPENGL_TEXTURE_HPP

#include "glad.h"
#include <iostream>

class OpenGL_Texture {
    public:
        OpenGL_Texture() = delete;
        OpenGL_Texture(const OpenGL_Texture&) = delete;
        OpenGL_Texture(const std::string& texture_path);
        ~OpenGL_Texture();
        GLuint getID() const;

    private:
        GLuint m_textureID;
};

#endif