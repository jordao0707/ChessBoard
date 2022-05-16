#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <GL/gl.h>

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
    glViewport(w/2,0, w/2,h);
    glLoadIdentity();

    glMatrixMode(GL_PROJECTION);                              //Habilita matriz de projeção
    glLoadIdentity();                                       //OpenGL classico = carrega a matriz identidade
    glFrustum(-1,1,-1,1,3,200);                             //OpenGL classico = matriz de projeção em perspectiva
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();         
    gluLookAt(
        eyex, eyey, eyez,
        lx, ly, lz,
        0.0,0.0,-1.0
    );
}


