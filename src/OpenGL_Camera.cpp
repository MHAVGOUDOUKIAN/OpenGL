#include "OpenGL_Camera.hpp"

OpenGL_Camera::OpenGL_Camera() : m_yaw(YAW), m_pitch(PITCH), m_speed(SPEED),
m_sensitivity(SENSITIVITY), m_zoom(ZOOM), m_position(POSITION), m_front(FRONT),
m_up(UP) {}

glm::mat4 OpenGL_Camera::lookAt() { return glm::lookAt(m_position, m_position+m_front, m_up); }