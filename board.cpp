#include <GL/gl.h>
// #include <stdio.h>

void drawBoard(float w, float h, float initx, float inity){
    glTranslatef(0.0,0.0,0.0);
    for(int i=0; i< 8 ; i++){
        for(int j=0; j<8;j++ ){
            glBegin(GL_QUADS);
                float x = initx + w*i;
                float y = inity + h*j;
                
                glColor3f((i+j)%2,(i+j)%2,(i+j)%2);
                glVertex2f(x          , y);
                glVertex2f(x + w      , y);
                glVertex2f(x + w      , y + h);
                glVertex2f(x          , y + h);       
            glEnd();
        }
    }
}
