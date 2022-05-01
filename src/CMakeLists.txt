cmake_minimum_required(VERSION 3.0)

#Set a normal variable to a given value
set(PROJECT_NAME OpenGL)
project(${PROJECT_NAME})

# Very important, otherwise your executable will be considered as a shared library by your OS and no as an executable
set (CMAKE_CXX_FLAGS "-no-pie")

# Select the sources files to use in the current directory
set( SOURCES
    glad.c
    main.cpp 
    OpenGL_App.cpp
    OpenGL_Camera.cpp
    OpenGL_Shader.cpp
    OpenGL_Texture.cpp
)

# //   headers file //
set( HEADERS
    OpenGL_App.hpp
    OpenGL_Camera.hpp
    OpenGL_Shader.hpp
    OpenGL_Texture.hpp
    stb_image.h
    glad.h
)

# GLFW is the only lib I use in this project (OpenGL is included in GLFW)
# so I can give the path to the GLFW include and lib directory with the following lines:  
# 
#       set(GLFW_INCLUDE_DIR /usr/include/GLFW)
#       set(GLFW_LIB_DIR /usr/lib/x86_64-linux-gnu)
#       include_directories(${GLFW_INCLUDE_DIR})
#       link_directories(${PROJECT_NAME} ${GLFW_INCLUDE_DIR})
#
# In my case i don't need to enable those lines.


add_executable(${PROJECT_NAME} # Name of the executable
    ${SOURCES}
    ${HEADERS})
    

# target_link_libraries() indicates the .lib or .a files you want to use
# For example, to compile in the repository "src" you can use the following command
# > g++ main.cpp glad.c OpenGL_App.cpp OpenGL_Shader.cpp OpenGL_Texture.cpp OpenGL_Camera.cpp -o exe -lglfw
# here I must use the lib glfw (in fact, i use -lglfw option) so I put it in this function 
target_link_libraries(${PROJECT_NAME}
    glfw
    dl
)