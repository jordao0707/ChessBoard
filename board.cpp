#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include "./headers/square.h"
#include "./headers/mouse.h"
#include <vector>  //inclui a classe vector, que implementa um vetor de tamanho variável 

using namespace std;
//Variáveis globais
float w_board = 0;
float h_board = 0;
float initx_board = 0;
float inity_board = 0;

vector <Square*> squares;

// "implementação" da função moveSquare
void moveSquareHere( GLFWwindow * window, int key, int scancode, int action, int mods){
   moveSquare(window,key,scancode,action,mods,&squares);

}
void mouseActionHere(GLFWwindow* window, int button, int action, int mods){
    mouseAction(window, button, action, mods, &squares);
}
// inicializa a posição e tamanho do tabuleiro e outros objetos 
void initScreenPositions(int width, int height){
    float aspect = (float)width / (float)height;
    
    // o tabuleiro sempre fica no canto inferior da tela
    int coord_x = -10;
    int coord_y = -10;
    initx_board = coord_x*(width>=height?aspect:1);
    inity_board = coord_y/(width<height?aspect:1);
    // um quarto do tamanho total do tabuleiro. Em modulo
    w_board = sqrt(coord_x * coord_x)/4;
    h_board = sqrt(coord_y * coord_y)/4;
    reposition(initx_board, inity_board,&squares);
  

}
void screenResize(int w, int h){
    w = w/2;
    glViewport(0,0, w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); 
    initScreenPositions(w,h);
    glOrtho(initx_board,-initx_board,inity_board,-inity_board,1,-1);
    
}
void initOpenGL(){
    glClearColor(0.3, 0.3, 0.3, 0.0);
}

void drawBoard(){
    for(int i=0; i< 8 ; i++){
        for(int j=0; j<8;j++ ){
            glBegin(GL_QUADS);
                float x = initx_board + w_board*i;
                float y = inity_board + h_board*j;
                
                glColor3f((i+j)%2,(i+j)%2,(i+j)%2);
                glVertex2f(x          , y);
                glVertex2f(x + w_board, y);
                glVertex2f(x + w_board, y + h_board);
                glVertex2f(x          , y + h_board);       
            glEnd();
        }
    }
}
void draw(){
    glClear(GL_COLOR_BUFFER_BIT); 
        drawBoard();
        drawSquare(&squares);   
    glFlush();  

}
int main(int argc, char** argv){
   
    glfwInit();
    // const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    GLFWwindow *window = glfwCreateWindow(400, 400, "Lista 1 CG",NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback (window, moveSquareHere);
    glfwSetMouseButtonCallback(window, mouseActionHere);
    
    // "contrutor" do Square com valores iniciais
    initSquare(1.0,5.0,0.0,initx_board,inity_board, &squares);
    initSquare(0.4,1.0,0.0,initx_board,inity_board, &squares);
    initSquare(0.0,1.0,1.0,initx_board,inity_board -1, &squares);
    
    squares.at(0)->is_select = 1;
    
    initOpenGL();
    while (!glfwWindowShouldClose(window)){
        int width, height;
        glfwGetFramebufferSize(window,&width,&height);
        screenResize(width,height);
        draw();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    delete &squares;
    glfwTerminate();
    return 0;
}
