#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <stdio.h>
#include <math.h>
#include "./headers/square.h"
#include <vector> 
#include <iostream>
using namespace std;
double mouse_x = 0;
double mouse_y = 0; 

void mousePosition(GLFWwindow* window, double xpos, double ypos){
    int width, height;
    glfwGetFramebufferSize(window,&width,&height);  
    float aspect = (float)width / (float)height;
    double x = 10*(width>=height?aspect:1);
    double y = 10/(width<height?aspect:1);
    mouse_x = (xpos/width) * x;
    mouse_y = (ypos/height) * y;
}

void mouseAction(GLFWwindow* window, int button, int action, int mods, vector<Square*> *sqrs)
{  int width, height;
    glfwGetFramebufferSize(window,&width,&height);  
  
    glfwSetCursorPosCallback(window, mousePosition);
 
    if(button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS){ 
        Square *selected = nullptr;
        for(Square *s : *sqrs){
            if(s->is_select){
                selected = s;
            }
            if(mouse_x>s->x_square || mouse_x <= (s->x_square +1.5)){
                s->is_select = true;
                if(selected != nullptr){
                    selected->is_select = false;
                }
            }
        }
    }// asdasdas
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){ 
        // Square *focused;
    }    
}

