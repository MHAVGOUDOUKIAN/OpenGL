#ifndef OPENGL_SHADER_HPP
#define OPENGL_SHADER_HPP

#include "glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>

class OpenGL_Shader {
    public:
        OpenGL_Shader() = delete;
        OpenGL_Shader(const OpenGL_Shader&) = delete;
        OpenGL_Shader(const char* vertexPath, const char* fragmentPath = "" , const char* GeoPath = "");
        ~OpenGL_Shader();
    
    public:
        void use();
        unsigned int getID();

    private:
        void loadShader(unsigned int shader, const std::string& shader_filename);
        void checkCompileErrors(unsigned int shader_id, const char* shader_location);
        unsigned int m_ID_Shader;
        
};

#endif