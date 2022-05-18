#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <stdio.h>
#include <math.h>
#include "../headers/square.h"
#include <vector> 
#include <iostream>
using namespace std;
double mouse_x = 0;
double mouse_y = 0; 

void repositionMouse(GLFWwindow* window){
    int width, height;
    // obtem o tamanho da "tela"
    glfwGetFramebufferSize(window,&width,&height);  
    width = width/2;
    float aspect = (float)width / (float)height;
    // tranformo as coords. de pixel para casas no tabuleiro. Lembrando que são 8 casas 
    float w_resize = 8*(width>=height?aspect:1); 
    float h_resize = 8/(width<height?aspect:1);
    
    // obtem as coords. do mouse nessa tela
    glfwGetCursorPos(window, &mouse_x, &mouse_y);
    // a seguinte divisão resultara em uma porcentagem em relação ao tamnha total da tela
    mouse_x = floor((mouse_x/width)*w_resize);
    mouse_y = floor((1-(mouse_y/height))*h_resize);// "-1" pois y esta no eixo negativo   
}
void mouseAction(GLFWwindow* window, int button, int action, int mods, vector<Square*> *sqrs)
{   
    repositionMouse(window);
    if(button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS){ 
         for(Square *s : *sqrs)s->is_select = false;
         for(Square *s : *sqrs)          
            if((mouse_x == s->x_square )&&(mouse_y == s->y_square))
                s->is_select = true;
    }
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){ 
        for(Square *s : *sqrs)s->is_focus = false;
        for(Square *s : *sqrs)          
            if((mouse_x == s->x_square )&&(mouse_y == s->y_square))
                s->is_focus = true;
    }    
}

