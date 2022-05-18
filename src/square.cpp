// Autor: Jordão Rodrigues Dantas
// Mátricula: 403686
// ///// CHESS BOARD //////
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <stdio.h>
#include <math.h>
#include "../headers/square.h"
#include "../headers/consts.h"
#include <vector> 
#include <iostream>

using namespace std;

void createSquares( vector<Square*> *sqrs){
    int size = sqrs->size();
    if(size>=64){ 
        cerr << "quantidade de objetos máxima 64"<< endl;
        return;
    };
    Square *s = new Square;
    s->r_color = (float)(rand()%64)/(float)64;
    s->g_color = (float)(rand()%64)/(float)64;
    s->b_color = (float)(rand()%64)/(float)64;

    s->r_color = s->r_color||s->r_color == 1?s->r_color : 0.2 ;
    s->g_color = s->g_color||s->g_color == 1?s->g_color : 0.4 ;
    s->b_color = s->b_color||s->b_color == 1?s->b_color : 0.6 ;
    s->w_square = BOARD_SIZE;
    s->h_square = BOARD_SIZE;
    
    for(Square *s : *sqrs){ 
        if(s->x_square == size%8 && s->y_square == size/8){
           cerr << "mova o objeto do ponteiro de criação" << endl;
           return;    
        }
    }
    s->x_square = size%8;
    s->y_square = size/8;
    
    sqrs->push_back(s);
}
void deleteSquares( vector<Square*> *sqrs){
    if(sqrs->size()<=0){ 
        cerr << "quantidade de objetos mínima"<< endl;
        return;
    };
    sqrs->pop_back();
}

void controlSquares( GLFWwindow * window, int key, int scancode, int action, int mods, vector<Square*> *sqrs)
{   
    switch(action){ 
        case GLFW_PRESS:
        case GLFW_REPEAT: 
            if(key == GLFW_KEY_C)createSquares(sqrs);
            if(key == GLFW_KEY_BACKSPACE)deleteSquares(sqrs);
            
            for(Square *s : *sqrs){    
                int x_before = s->x_square;
                int y_before = s->y_square;
                
                        if(s->is_select) {        
                            if(key == GLFW_KEY_LEFT)glTranslatef((float)s->x_square-- ,(float)s->y_square  ,0);
                            if(key == GLFW_KEY_RIGHT)glTranslatef((float)s->x_square++,(float)s->y_square  ,0);
                            if(key == GLFW_KEY_DOWN)glTranslatef((float)s->x_square   ,(float)s->y_square--,0);
                            if(key == GLFW_KEY_UP)glTranslatef((float)s->x_square     ,(float)s->y_square++,0);
                        }
                // Restrições //
                // limite do tabuleiro
                s->x_square = s->x_square%8;
                s->y_square = s->y_square%8;
                s->x_square = s->x_square < 0?7:s->x_square;
                s->y_square = s->y_square < 0?7:s->y_square;
                
                // colisão   
                for(Square *q : *sqrs){
                    if(s->x_square == q->x_square 
                    && s->y_square == q->y_square
                    && s != q
                    ){
                        s->x_square = x_before;
                        s->y_square = y_before;
                    }
                }    
            }
        break;                                 
        default: break;        
    }  
       
}


void drawSquare(vector<Square*> *sqrs){
    int size = sqrs->size();
    for(Square *s : *sqrs){
        float x = s->x_square*(s->w_square);
        float y = s->y_square*(s->h_square);
        // desenha os quadrados   
        glBegin(GL_QUADS);
            glColor3f(s->r_color, s->g_color, s->b_color);             
            glVertex2f(x           , y); 
            glVertex2f(x+s->w_square, y);  
            glVertex2f(x+s->w_square, y+s->h_square);
            glVertex2f(x           , y+s->h_square);
        glEnd();    
        // Linha que mostra o quadrado selecionado
        if(s->is_select == true) {
            glBegin(GL_LINE_LOOP);
                glColor3f(0, 0, 0);             
                glVertex2f(x           , y); 
                glVertex2f(x+s->w_square, y);  
                glVertex2f(x+s->w_square, y+s->h_square);
                glVertex2f(x           , y+s->h_square);
            glEnd();   
        }
    }
    // linha que mostra onde vai ser criado o próximo quadrado
    glBegin(GL_LINE_LOOP);
        float x = size%8*(2.5);
        float y = size/8*(2.5);  
        glColor3f(1.0, 0.6, 0.2);             
        glVertex2f(x    , y); 
        glVertex2f(x+2.5, y);  
        glVertex2f(x+2.5, y+2.5);
        glVertex2f(x    , y+2.5);
    glEnd();         
}

