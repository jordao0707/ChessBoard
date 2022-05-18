// Autor: Jordão Rodrigues Dantas
// Mátricula: 403686
// ///// CHESS BOARD //////
#include <GL/gl.h>
// #include <stdio.h>
#include "../headers/consts.h"
void drawBoard(){
    float w = BOARD_SIZE;
    float h = BOARD_SIZE;
    for(int i=0; i< 8 ; i++){
        for(int j=0; j<8;j++ ){
            glBegin(GL_QUADS);
                float x = w*i;
                float y = h*j;
                
                glColor3f((i+j)%2,(i+j)%2,(i+j)%2);
                glVertex2f(x          , y);
                glVertex2f(x + w      , y);
                glVertex2f(x + w      , y + h);
                glVertex2f(x          , y + h);       
            glEnd();
        }
    }
}
