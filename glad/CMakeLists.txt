cmake_minimum_required(VERSION 3.18.4)
project(my_opengl_project VERSION 0.1.0)
find_package(OpenGL)
add_executable(my_opengl_project src/main.cpp src/glad.c src/stb_image.cpp)
target_link_libraries(my_opengl_project 
    glfw
    GL
    GLEW
    dl
    freetype
)