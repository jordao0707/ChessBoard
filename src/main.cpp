//  Autor: Jordão Rodrigues Dantas
//  Mátricula: 403686
// /// CHESS BOARD //////
 
#include "../headers/consts.h"
#include "../headers/board.h"
#include "../headers/object.h"
#include "../headers/mouse.h"
#include "../headers/square.h"
#include "../headers/leftScreen.h"
#include "../headers/rightScreen.h"


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
   Cubo c;
       
    // configuração e inicializaçã da janela
    glfwInit();
    GLFWwindow *window;
    window = glfwCreateWindow(WINDOW_WIDTH,WINDOW_HEIGHT,PROJ_NAME,NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback (window, controlSquaresHere); // controle tecldado
    glfwSetMouseButtonCallback(window, mouseActionHere); // controle mouse
    // cor de fundo da janela
    glClearColor(CLEAR_R,CLEAR_G,CLEAR_B,CLEAR_A); 
    
    while (!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // // desenho da janela esquedar
        leftScreenResize(window);   
        drawBoard();
        drawSquare(&squares);
        // desenho da janela direito
        
        rightScreenResize(window,&squares);
        //  c.desenha();
        drawBoard();
        drawSquare(&squares);
        
        // drawCubes(&squares);
        //controle de evento e troca de buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    // finalização 
    squares.clear();
    delete(&squares);
    glfwTerminate();
    return 0;
}