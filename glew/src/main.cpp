
#include "Renderer.h"
#include "VertexBufferLayout.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main( void )
{
    GLFWwindow* window;
    /* Initialize the library */
    if( !glfwInit() )
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Hello World", NULL, NULL);
    if(!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);

    if( glewInit() != GLEW_OK )
        std::cout << "error" << std::endl;
    
    std::cout << glGetString(GL_VERSION) << std::endl;

    Shader ourShader("/home/abu/graphics/glew/res/shaders/vertexShader.shader","/home/abu/graphics/glew/res/shaders/fragmentShader.shader");
    ourShader.use();

    float positions[] = {
        -0.5f, -0.5f,
         0.5f, -0.5f,
         0.5f,  0.5f,
        -0.5f,  0.5f
    };

    unsigned int indices[] = {
        0,1,2,
        2,3,0
    };

    GLuint vao = 0;
    glCreateVertexArrays(1,&vao);
    glBindVertexArray(vao);

    VertexArray va;

    VertexBuffer vb(positions,4*2*sizeof(float));
    IndexBuffer ib(indices,6);

    VertexBufferLayout layout;
    layout.Push<float>(2);

    va.AddBuffer(vb,layout);
    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,2, GL_FLOAT, GL_FALSE, sizeof(float )*2,0);

    glBindVertexArray(0);
    vb.Unbind();
    ib.Unbind();
    int u_location = glGetUniformLocation(ourShader.ID,"u_Color");
    /* Loop until the user closes the window */
    float x = 0.0;
    float inc = 0.01;
    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f,0.3f,0.3f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Render here */
        float timeValue = glfwGetTime();
        float g = (sin(timeValue) / 2.0f) + 0.5f;
        glUniform4f(u_location,0.0f,g,0.0f,1.0f); 
        va.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,nullptr); GCE

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
        
    }

    ourShader.deleteProgram();
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) 
{
    glViewport(0,0,width,height);
}