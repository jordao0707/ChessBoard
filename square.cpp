#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <stdio.h>
#include <math.h>
#include "./headers/square.h"
#include <vector> 
#include <iostream>

using namespace std;

void initSquare(float r, float g, float b, vector<Square*> *sqrs){
    Square *s = new Square;
    s->r_color = r ;
    s->g_color = g;
    s->b_color = b;
    s->w_square = 2.5;
    s->h_square = 2.5;
    int size = sqrs->size();
    if(size>=64){ 
        cerr << "quantidade de objeto máxima 64"<< endl;
        exit(1);
    };
    s->x_square = size%8;
    s->y_square = size/8;
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
    for(Square *s : *sqrs){    
        int x_before = s->x_square;
        int y_before = s->y_square;
           
        switch(action){ 
            case GLFW_PRESS:
            case GLFW_REPEAT: 
                if(s->is_select) {        
            
                    if(key == GLFW_KEY_LEFT) s->x_square--;
                    if(key == GLFW_KEY_RIGHT) s->x_square ++;
                    if(key == GLFW_KEY_DOWN) s->y_square --;
                    if(key == GLFW_KEY_UP) s->y_square ++;
                }
            break;                                 
            default: break;        
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
    
}

