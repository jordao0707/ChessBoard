#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <vector>  


void leftScreenResize(GLFWwindow *window, float *initx, float *inity)
{    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    int w, h;
    glfwGetFramebufferSize(window,&w,&h);
    w = w/2;   
    // ortho screen(1)
    glViewport(0,0, w,h);
    glLoadIdentity();
    float aspect = (float)w / (float)h;
    // o tabuleiro sempre fica no canto inferior da tela
    *initx = -10*(w>=h?aspect:1);
    *inity =  -10/(w<h?aspect:1);
    glOrtho(*initx,-(*initx),*inity,-(*inity),1,-1);      
}