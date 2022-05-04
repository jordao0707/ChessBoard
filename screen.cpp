#include <GLFW/glfw3.h>
#include <GL/gl.h>
// #include <stdio.h>
#include <math.h>
#include "./headers/square.h"
#include "./headers/mouse.h"
#include "./headers/board.h"

#include <vector>  
;
//Variáveis globais
float initx = 0;
float inity = 0;

vector <Square*> squares;

// "implementação" da função moveSquare
void moveSquareHere( GLFWwindow * window, int key, int scancode, int action, int mods){
   moveSquare(window,key,scancode,action,mods,&squares);
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
    // um quarto do tamanho total do tabuleiro. Em modulo
     reposition(initx, inity,&squares);
  

}
void screenResize(GLFWwindow *window){
    int w, h;
    glfwGetFramebufferSize(window,&w,&h);
    w = w/2;
    glViewport(0,0, w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); 
    initScreenPositions(w,h);
    glOrtho(initx,-initx,inity,-inity,1,-1);
    glClearColor(0.3, 0.3, 0.3, 0.0);   
    
}

int main(int argc, char** argv)
{   
    glfwInit();
    GLFWwindow *window = glfwCreateWindow(400, 400, "Lista 1 CG",NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback (window, moveSquareHere);
    glfwSetMouseButtonCallback(window, mouseActionHere);    
    // "contrutor" do Square com valores iniciais
    initSquare(1.0,5.0,0.0, &squares);
    initSquare(0.4,1.0,0.0, &squares);
    initSquare(0.0,1.0,1.0, &squares);
        
    while (!glfwWindowShouldClose(window)){
        screenResize(window);
        drawBoard(2.5,2.5,initx,inity);
        drawSquare(&squares);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    squares.clear();
    delete(&squares);
    glfwTerminate();
    return 0;
}
