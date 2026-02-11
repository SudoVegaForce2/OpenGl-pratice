#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <GL/glew.h>

void buffer_size(GLFWwindow *window, int width, int height);

int main(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    GLFWwindow *window = glfwCreateWindow(800, 600, "Triangle", NULL, NULL);
    if (window == NULL){
        printf("FAILED TO MAKE A WINDOW\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    
    glewExperimental = GL_TRUE; 
    GLenum err = glewInit();
    if (err != GLEW_OK){
        printf("failed to init glew: %s\n", glewGetErrorString(err));
        glfwTerminate();
        return -1;
    }
    
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, buffer_size);

    
    while(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
        

        glBegin(GL_TRIANGLES);
            glColor3f(2.0f, 2.0f, 2.0f);
            glVertex2f(0.0f, 1.0f);
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex2f(-1.0f, -1.0f);
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex2f(1.0f, -1.0f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void buffer_size(GLFWwindow *window, int width, int height) {
    (void)window;
    glViewport(0, 0, width, height);
}