cmake_minimum_required(VERSION 3.18.4)
project(my_opengl_project VERSION 0.1.0)
find_package(OpenGL)
add_executable(my_opengl_project 
    src/main.cpp
    src/glad.c
    src/VertexBuffer.cpp
    src/IndexBuffer.cpp
    src/VertexArray.cpp
    src/Error.cpp
    src/VertexBufferLayout.h
)

target_include_directories(my_opengl_project PUBLIC
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
                           $<INSTALL_INTERFACE:include>)
target_link_libraries(my_opengl_project 
    glfw
    GLESv2
    OpenGL::GL
    GLEW
    ${CMAKE_DL_LIBS}
)