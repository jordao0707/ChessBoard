// Autor: Jordão Rodrigues Dantas
// Mátricula: 403686
// ///// CHESS BOARD //////
#ifndef _SQUARE_
#define _SQUARE_
#include <GLFW/glfw3.h>
#include <vector>

using namespace std;
typedef struct {
    int x_square = 0; 
    int y_square = 0; 
    float w_square = 0;    
    float h_square = 0;
    float initx_square = 0; 
    float inity_square = 0; 
    float r_color , g_color, b_color;
    unsigned int is_select = 0;
    unsigned int is_focus = 0;
}Square;

void controlSquares( GLFWwindow * window, int key, int scancode, int action, int mods, vector<Square*> *sqrs);
void drawSquare(vector<Square*> *sqrs);
#endif