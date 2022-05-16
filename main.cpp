#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include "./headers/square.h"
#include "./headers/mouse.h"
#include "./headers/board.h"
// #include "./headers/leftScreen.h"
// #include "./headers/rightScreen.h"

#include <vector>  


float initx, inity;
vector <Square*> squares;

// "implementação" da função controlSquares
void controlSquaresHere( GLFWwindow * window, int key, int scancode, int action, int mods){
   controlSquares(window,key,scancode,action,mods,&squares);
}
// "implementação" da função mouseAction 
void mouseActionHere(GLFWwindow* window, int button, int action, int mods){
    mouseAction(window, button, action, mods, &squares);
}
float eyey = -2; 
float eyex = -2;
float eyez = -2;
float ly = 0; 
float lx = 0;
float lz = -1;
void draw(GLFWwindow* window){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    int w, h;
    glfwGetFramebufferSize(window,&w,&h);
    w = w/2;   
    // ortho screen(1)
    glViewport(0,0, w-1,h);
    glLoadIdentity();
    float aspect = (float)w / (float)h;
    initx = -10*(w>=h?aspect:1);
    inity =  -10/(w<h?aspect:1);
    glOrtho(initx,-initx,inity,-inity,1,-1);      
    drawBoard(2.5,2.5, initx, inity);
    drawSquare(initx, inity,&squares);
    glViewport(w+1.1,0, w-1.1,h);
    glLoadIdentity();

    glFrustum(-1,1,-1,1,3,200);                             //OpenGL classico = matriz de projeção em perspectiva
    gluLookAt(
        eyex, eyey, eyez,
        lx, ly, lz,
        0.0,0.0,-1.0
    );
    
    drawBoard(2.5,2.5, initx, inity);
}
int main(int argc, char** argv)
{   
    glfwInit();
    GLFWwindow *window = glfwCreateWindow(400, 400, "Chess Board",NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback (window, controlSquaresHere);
    glfwSetMouseButtonCallback(window, mouseActionHere);    
    // "contrutor" do Square com valores iniciais
    glClearColor(1.0, 0.3, 0.3, 0.3); 
     while (!glfwWindowShouldClose(window)){
         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        draw(window);
        // leftScreenResize(window, &initx , &inity);
        // drawBoard(2.5,2.5, initx, inity);
        // rightScreenResize(window, 0, 0);
        // drawBoard(2.5,2.5, initx, inity);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    squares.clear();
    delete(&squares);
    glfwTerminate();
    return 0;
}