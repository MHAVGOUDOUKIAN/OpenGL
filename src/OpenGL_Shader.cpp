#include "OpenGL_Shader.hpp"

OpenGL_Shader::OpenGL_Shader(const char* vertexPath, const char* fragmentPath, const char* GeoPath) {
    unsigned int vertex=glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragment=glCreateShader(GL_FRAGMENT_SHADER);
    
    loadShader(vertex, vertexPath);
    glCompileShader(vertex);
    checkCompileErrors(vertex, "VERTEX");

    loadShader(fragment, fragmentPath);
    glCompileShader(fragment);
    checkCompileErrors(fragment, "FRAGMENT");

    m_ID_Shader = glCreateProgram();
    glAttachShader(m_ID_Shader, vertex);
    glAttachShader(m_ID_Shader, fragment);
    glLinkProgram(m_ID_Shader);
    checkCompileErrors(m_ID_Shader, "PROGRAM");
    
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

OpenGL_Shader::~OpenGL_Shader() { glDeleteProgram(m_ID_Shader); }

void OpenGL_Shader::checkCompileErrors(unsigned int shader, const char* type) {
    GLint success;
    GLchar infoLog[1024];
    if(type != "PROGRAM") {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if(!success) {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    } else {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if(!success) {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
}

void OpenGL_Shader::use() { glUseProgram(m_ID_Shader); }

void OpenGL_Shader::loadShader(unsigned int shader, const std::string& shader_filename) {
    std::ifstream file(shader_filename);

    std::string content("");
    std::string temp_line("");
    while(std::getline(file, temp_line)) {
        content += temp_line;
        content += "\n";
    }
    
    const char* shaderCode = content.c_str();

    glShaderSource(shader, 1, &shaderCode, NULL);
}

unsigned int OpenGL_Shader::getID() { return m_ID_Shader; }