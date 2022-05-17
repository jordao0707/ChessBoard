#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include "./headers/square.h"
#include "./headers/mouse.h"
#include "./headers/board.h"
#include "./headers/consts.h"
#include "./headers/leftScreen.h"
#include "./headers/rightScreen.h"
#include <vector>  

float initx = 0;
float inity = 0;
vector <Square*> squares;

// "implementação" da função controlSquares
void controlSquaresHere( GLFWwindow * window, int key, int scancode, int action, int mods){
   controlSquares(window,key,scancode,action,mods,&squares);
}
// "implementação" da função mouseAction 
void mouseActionHere(GLFWwindow* window, int button, int action, int mods){
    mouseAction(window, button, action, mods, &squares);
}

int main(int argc, char** argv)
{   
    glfwInit();
    GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Chess Board",NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback (window, controlSquaresHere);
    glfwSetMouseButtonCallback(window, mouseActionHere);    
    // "contrutor" do Square com valores iniciais
    glClearColor(1.0, 0.3, 0.3, 0.3); 
     while (!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        leftScreenResize(window);
             
        drawBoard();
        drawSquare(&squares);
       
        rightScreenResize(window, 0 , 0);
        drawBoard();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    squares.clear();
    delete(&squares);
    glfwTerminate();
    return 0;
}