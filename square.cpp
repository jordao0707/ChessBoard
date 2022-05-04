#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <stdio.h>
#include <math.h>
#include "./headers/square.h"
#include <vector> 
#include <iostream>

using namespace std;

void initSquare(float r, float g, float b,float init_x,float init_y, vector<Square*> *sqrs){
    Square *s = new Square;
    s->r_color = r ;
    s->g_color = g;
    s->b_color = b;
    s->w_square = 2.5;
    s->h_square = 2.5;
    s->initx_square = init_x;
    s->inity_square = init_y;
    sqrs->push_back(s);
}

void reposition(float init_x,float init_y,vector<Square*> *sqrs){
    if(sqrs->empty() == true)return;
    
    for(Square *s : *sqrs){
        s->initx_square = init_x;
        s->inity_square = init_y;
    }
}

void moveSquare( GLFWwindow * window, int key, int scancode, int action, int mods, vector<Square*> *sqrs)
{   
    // if(sqrs->empty())return;

    for(Square *s : *sqrs){
        
         if(s->is_select) {        
            switch(action){ 
                case GLFW_PRESS:
                case GLFW_REPEAT: 
                    if(key == GLFW_KEY_LEFT) s->x_square --;
                    if(key == GLFW_KEY_RIGHT) s->x_square ++;
                    if(key == GLFW_KEY_DOWN) s->y_square --;
                    if(key == GLFW_KEY_UP) s->y_square ++;
                break;                                 
                default: break;        
            }        
        }
        // define o limite do tabuleiro
        s->x_square = s->x_square>=0?s->x_square%8:7-(s->x_square%8); // TODO corrigir formula
        s->y_square = s->y_square>=0?s->y_square%8:7-(s->y_square%8);

    }
}
void drawSquare(vector<Square*> *sqrs){
    // printf("é selecionado %d\n",s->is_select);
    for(Square *s : *sqrs){
        float x = s->initx_square + s->x_square*(s->w_square);
        float y = s->inity_square + s->y_square*(s->h_square);                  
        glBegin(GL_QUADS);
            glColor3f(s->r_color, s->g_color, s->b_color);             
            glVertex2f(x           , y); 
            glVertex2f(x+s->w_square, y);  
            glVertex2f(x+s->w_square, y+s->h_square);
            glVertex2f(x           , y+s->h_square);
        glEnd();    
        if(s->is_select) {
            glBegin(GL_LINE_LOOP);
                glColor3f(0, 0, 0);             
                glVertex2f(x           , y); 
                glVertex2f(x+s->w_square, y);  
                glVertex2f(x+s->w_square, y+s->h_square);
                glVertex2f(x           , y+s->h_square);
            glEnd();   
        } 
    }
    
}

