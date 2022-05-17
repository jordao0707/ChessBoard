#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include "./headers/consts.h"

float eyey = -2; 
float eyex = -2;
float eyez = -2;
float ly = 0; 
float lx = 0;
float lz = -1;

void rightScreenResize(GLFWwindow *window, float lx, float ly)
{    
    int w, h;
    glfwGetFramebufferSize(window,&w,&h);
    w = (w/2) ;
    glViewport(w + BORDER,0, w - BORDER,h);
    glLoadIdentity();
    glFrustum(-1,1,-1,1,3,200);                             //OpenGL classico = matriz de projeção em perspectiva
    gluLookAt(
        eyex, eyey, eyez,
        lx, ly, lz,
        0.0,0.0,-1.0
    );
}


