#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <vector> 
#include "../headers/consts.h"
#include "../headers/square.h"
 using namespace std;

void cube(float x, float y){
    glTranslatef(3.0,3.0,0.0);
    // back - blue
    glBegin(GL_POLYGON);
        glColor3f(   0.0,  0.0,  1.0 );
        glVertex3f(  0.5,  0.5,  0.5 );
        glVertex3f(  0.5,  0.5, -0.5 );
        glVertex3f( -0.5,  0.5, -0.5 );
        glVertex3f( -0.5,  0.5,  0.5 );
    glEnd();
    // right - Purple side
    glBegin(GL_POLYGON);
        glColor3f(  1.0,  0.0,  1.0 );
        glVertex3f( 0.5, -0.5, -0.5 );
        glVertex3f( 0.5,  0.5, -0.5 );
        glVertex3f( 0.5,  0.5,  0.5 );
        glVertex3f( 0.5, -0.5,  0.5 );
    glEnd();
    // top - red
    glBegin(GL_POLYGON);
        glColor3f( 1.0, 0.0, 0.0 );     
        glVertex3f(  0.5, -0.5, -0.5 );      
        glVertex3f(  0.5,  0.5, -0.5 ); 
        glVertex3f( -0.5,  0.5, -0.5 );
        glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();
    // botton - yellow
    glBegin(GL_POLYGON);
        glColor3f(   1.0,  1.0, 0.0 );
        glVertex3f(  0.5, -0.5, 0.5 );
        glVertex3f(  0.5,  0.5, 0.5 );
        glVertex3f( -0.5,  0.5, 0.5 );
        glVertex3f( -0.5, -0.5, 0.5 );
    glEnd();
    // left - green
    glBegin(GL_POLYGON);
        glColor3f(   0.0,  1.0,  0.0 );
        glVertex3f( -0.5, -0.5,  0.5 );
        glVertex3f( -0.5,  0.5,  0.5 );
        glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();
    // front - ciano
    glBegin(GL_POLYGON);
        glColor3f(   0.0,  1.0,  1.0 );
        glVertex3f(  0.5, -0.5, -0.5 );
        glVertex3f(  0.5, -0.5,  0.5 );
        glVertex3f( -0.5, -0.5,  0.5 );
        glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();         
}


void drawCubes( vector<Square*> *sqrs){
cube(0,0);
}