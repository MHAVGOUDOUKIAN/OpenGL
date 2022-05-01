#ifndef OPENGL_CAMERA_HPP
#define OPENGL_CAMERA_HPP

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

const float YAW         = -90.0f;
const float PITCH       =  0.0f;
const float SPEED       =  5.0f;
const float SENSITIVITY =  0.1f;
const float ZOOM        =  45.0f;
const glm::vec3 POSITION = glm::vec3(0.0f, 0.0f, 3.0f);
const glm::vec3 FRONT = glm::vec3(0.0f, 0.0f, -1.0f);
const glm::vec3 UP = glm::vec3(0.0f, 1.0f, 0.0f);

class OpenGL_Camera {
        public:
            OpenGL_Camera();
            ~OpenGL_Camera();
        
            glm::mat4 lookAt(void);

        public:
            float m_yaw;
            float m_pitch;
            float m_speed;
            float m_sensitivity;
            float m_zoom;

            glm::vec3 m_position;
            glm::vec3 m_front;
            glm::vec3 m_up;
};

#endif