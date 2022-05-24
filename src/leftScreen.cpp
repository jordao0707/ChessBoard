// Autor: Jordão Rodrigues Dantas
// Mátricula: 403686
// ///// CHESS BOARD //////  
#include "../headers/consts.h"
#include <math.h>
void leftScreenResize(GLFWwindow *window)
{    
    int w, h;
    glfwGetFramebufferSize(window,&w,&h);
    w = (w/2) - BORDER;   
    glViewport(0,0, w,h);
    glLoadIdentity(); 
    float aspect = (float)w / (float)h;
    // o tabuleiro sempre fica no canto inferior da tela
    float initx = 10*(w >=h?aspect:1);
    float inity = 10/(w < h?aspect:1);
    
    
    glOrtho(-initx, initx, -inity, inity, 1, -1);
    // pões todos os objetos na origem do sistema     
    glTranslatef(-initx,-inity,0.0);
    
}
// por algum motivo eu não sei pq esta dando errado a projeção
// quando aplico as funções glModelView e glMatrixMode. Fui obrigado a tirar para fazer
// esse codigo funcionar