#include <glut.h>
#include <cmath>
#include <math.h>
#include <stdio.h>
#define _USE_MATH_DEFINES

void DrawCosine() {
	double pi = 3.1415926535897;
    glLineWidth(2.5); 
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	float x;
	float y;
	float lastX = -1.1;
	float lastY = -1.0;
	for ( x = lastX; x < 1; x = x + 0.01)
	{
		y = cos(x*5);
		glVertex3f(lastX, lastY, 0.0);
		glVertex3f(x, y, 0.0);
		lastX = x;
		lastY = y;
	}
	glEnd();
}
void DrawSine() {
	double pi = 3.1415926535897;
    glLineWidth(2.5); 
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	float x;
	float y;
	float lastX = -1.1;
	float lastY = -1.0;
	for ( x = lastX; x < 1; x = x + 0.01)
	{
		y = sin(x*5);
		glVertex3f(lastX, lastY, 0.0);
		glVertex3f(x, y, 0.0);
		lastX = x;
		lastY = y;
	}
	glEnd();
}
void DrawTangent() {
	double pi = 3.1415926535897;
    glLineWidth(2.5); 
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	float x;
	float y;
	float lastX = -1.1;
	float lastY = -1.0;
	for ( x = lastX; x < 1; x = x + 0.01)
	{
		y = tan(x*5);
		if(lastY - y < 2){
		glVertex3f(lastX, lastY, 0.0);
		glVertex3f(x, y, 0.0);
		}
		
		lastX = x;
		lastY = y;
	}
	glEnd();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLineWidth(1); 
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(-1, 0, 0.0);
	glVertex3f(1, 0, 0.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(0, -1, 0.0);
	glVertex3f(0, 1, 0.0);
	glEnd();
	DrawCosine();
	DrawSine();
	DrawTangent();
    glutSwapBuffers();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
}

void idle(void)
{
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 500);
	(void)glutCreateWindow("Trig Functions - Calin Gribble");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    glutMainLoop();

    return 0;
}
