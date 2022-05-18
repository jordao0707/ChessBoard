// Autor: Jordão Rodrigues Dantas
// Mátricula: 403686
// ///// CHESS BOARD //////
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <vector>
#include "../headers/consts.h"
#include "../headers/square.h"
float eyey = -2; 
float eyex = -2;
float eyez = -2;
float lx = 0;
float ly = 0; 
float lz = -1;

using namespace std;

void rightScreenResize(GLFWwindow *window, vector<Square*> *sqrs)
{   
    for (Square *s : *sqrs){
        if(s->is_focus){
            lx = s->x_square;
            ly = s->y_square;
        }
    } 
    int w, h;
    glfwGetFramebufferSize(window,&w,&h);
    w = (w/2) ;
    glViewport(w + BORDER,0, w - BORDER,h);
    glLoadIdentity();
    glFrustum(-2,2,-1,1,3,200);                             //OpenGL classico = matriz de projeção em perspectiva
    gluLookAt(
        eyex, eyey, eyez,
        lx, ly, lz,
        0.0,0.0,-1.0
    );
}


