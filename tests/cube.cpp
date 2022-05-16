#include<stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#define KEY_ESC 27 /* GLUT doesn't supply this */

int fullscreen = 0;
int mouseDown = 0;

float xrot = 100.0f;
float yrot = -100.0f;

float xdiff = 100.0f;
float ydiff = 100.0f;

float tra_x = 0.0f;
float tra_y = 0.0f;
float tra_z = 0.0f;


float grow_shrink = 70.0f;
float resize_f = 1.0f;

void drawBox()
{
	glBegin(GL_QUADS);
	
	

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, -2.0f, 2.0f);
	glVertex3f( 2.0f, -2.0f, 2.0f);
	glVertex3f( 2.0f, 2.0f, 2.0f);
	glVertex3f(-2.0f, 2.0f, 2.0f);
	
	glEnd();
}

int init(void)
{
	glClearColor(0.93f, 0.93f, 0.93f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearDepth(1.0f);

	return 1;
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(
	0.0f, 0.9f, 1.0f,
	0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f);

	drawBox();

	glFlush();
	glutSwapBuffers();
}

void resize(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);

    glFrustum(-1,1,-1,1,resize_f, resize_f * 100);
	// gluPerspective(grow_shrink, resize_f * w / h, resize_f, 100 * resize_f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);

	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutCreateWindow("13 - Solid Shapes");

	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	
	if (!init())
		return 1;

	glutMainLoop();

	return 0;
}
