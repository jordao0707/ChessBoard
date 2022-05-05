#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <math.h>
#include "./headers/square.h"
#include "./headers/mouse.h"
#include "./headers/board.h"
#include <vector>  

//Variáveis globais
float initx = 0;
float inity = 0;
vector <Square*> squares;

// "implementação" da função moveSquare
void controlSquaresHere( GLFWwindow * window, int key, int scancode, int action, int mods){
   controlSquares(window,key,scancode,action,mods,&squares);
}
void mouseActionHere(GLFWwindow* window, int button, int action, int mods){
    mouseAction(window, button, action, mods, &squares);
}
// define a origem dos objetos 
void initScreenPositions(int width, int height){
    float aspect = (float)width / (float)height;
    // o tabuleiro sempre fica no canto inferior da tela
    initx = -10*(width>=height?aspect:1);
    inity = -10/(width<height?aspect:1);
}

void screenResize(GLFWwindow *window)
{    
    int w, h;
    glfwGetFramebufferSize(window,&w,&h);
    w = w/2;
    glViewport(0,0, w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); 
    initScreenPositions(w,h);
    glOrtho(initx,-initx,inity,-inity,1,-1);   
}

void draw(){
    glClear(GL_COLOR_BUFFER_BIT);  
    drawBoard(2.5,2.5,initx,inity);
    drawSquare(initx,inity,&squares);
    glFlush();  
}
int main(int argc, char** argv)
{   
    glfwInit();
    GLFWwindow *window = glfwCreateWindow(400, 400, "Lista 1 CG",NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback (window, controlSquaresHere);
    glfwSetMouseButtonCallback(window, mouseActionHere);    
    // "contrutor" do Square com valores iniciais
    glClearColor(0.3, 0.3, 0.3, 0.3);   
    while (!glfwWindowShouldClose(window)){
        screenResize(window);
        draw();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    squares.clear();
    delete(&squares);
    glfwTerminate();
    return 0;
}
