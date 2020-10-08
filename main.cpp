// Stephen Mackey
//1661994
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
using namespace std;

bool leftDown = false, rightDown = false;
int lastPos[2];
float cameraPos[4] = {0, 1, 2, 1}; // TODO: Your code here! setup a proper camera position. It should be 4 dimentions homogeneous coordinate, first three elements represent position and 4th element should be 1.
int windowWidth = 640, windowHeight = 480;
double yRot = 0;
int curProblem = 1; // TODO: change this number to try different examples.

float specular[] = { 1.0, 1.0, 1.0, 1.0 };
float shininess[] = { 50.0 };

void problem1() {
	// TODO: Your code here!
	double pi = 3.14;
	int angle = 0;
	for (int i = 0; i < 10; ++i)
	{
		glPushMatrix();
		glTranslatef(cos((angle*pi)/180), sin((angle*pi)/180), 0);
		glRotatef(angle, 0, 0, 1);
		glutSolidTeapot(0.2);
		glPopMatrix();
		angle += 36;
	}
}

void problem2() {
	// TODO: Your code here!
	glPushMatrix();
	glTranslatef(0, 1, 0);
	glutSolidTeapot(0.2);
	glPopMatrix();
	double y = 0.5;
	double x = -0.4;
	for (int i = 2; i <= 6; i++)
	{
		double spacing = x;
		for (int j = 0; j < i; j++)
		{
			glPushMatrix();
			glTranslatef(spacing, y, 0);
			glutSolidTeapot(0.2);
			glPopMatrix();
			spacing += 0.8;
		}
		x = x - 0.4;
		y = y - 0.4;
	}
}

void problem3() {
	// TODO: Your code here! Your own creativity. 
	double x = -0.2;
	double y = 0.5;
	for (int i = 0; i <= 6; i++)
	{
		double spacing = x;
		for (int j = 0; j <= 4; j++)
		{
			glPushMatrix();
			glTranslatef(spacing, y, 0);
			glutSolidCube(0.1);
			glPopMatrix();
			spacing = spacing + 0.1;
		}
		y -= 0.1;
	}
	x = -0.25;
	y = 0.1;
	for (int i = 0; i < 3; i++)
	{
		glPushMatrix();
		glTranslatef(x, y, 0);
		glRotatef(135, 0, 0, 1);
		glutSolidCube(0.1);
		glPopMatrix();
		x -= 0.08;
		y += 0.07;
	}
	glPushMatrix();
	glTranslatef(-0.45, 0.31, 0);
	glutSolidCube(0.1);
	glPopMatrix();
	x = -0.2;
	y = 0.5;
	for (int i = 0; i < 4; i++)
	{
		double spacing = y;
		for (int j = 0; j < 7; j++)
		{
			glPushMatrix();
			glTranslatef(x, spacing, 0);
			glutSolidCube(0.075);
			glPopMatrix();
			spacing += 0.08;
		}
		x += 0.135;
	}
}

void display() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(1, 0, 0); // x axis
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 1, 0); // y axis
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 1); // z axis
	glEnd(/*GL_LINES*/);

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// TODO: Your code here! Use glViewport() and gluPerspective() to setup projection matrix.
	gluPerspective(45.0, 1.0, 1.0, 100.0);
	glViewport(0, 0, windowWidth, windowHeight);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// TODO: Your code here! Use gluLookAt() to setup model-view matrix.
	gluLookAt(0.0, 1.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glLightfv(GL_LIGHT0, GL_POSITION, cameraPos);

	glRotatef(yRot, 0, 1, 0);

	if (curProblem == 1) problem1();
	if (curProblem == 2) problem2();
	if (curProblem == 3) problem3();

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) leftDown = (state == GLUT_DOWN);
	else if (button == GLUT_RIGHT_BUTTON) rightDown = (state == GLUT_DOWN);

	lastPos[0] = x;
	lastPos[1] = y;
}

void mouseMoved(int x, int y) {
	if (leftDown) yRot += (x - lastPos[0]) * .1;
	if (rightDown) {
		for (int i = 0; i < 3; i++)
			cameraPos[i] *= pow(1.1, (y - lastPos[1]) * .1);
	}


	lastPos[0] = x;
	lastPos[1] = y;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	// TODO: Your code here! use key to switch between different scene, and set q, Q and Escape key as quit.
	switch (key)
	{
	case 'a':
		if (curProblem == 1) 
		{
			curProblem = 2;
		}
		else if (curProblem == 2)
		{
			curProblem = 3;
		}
		else
		{
			curProblem = 1;
		}
		break;
	case 'q':
		exit(0);
	case 'Q':
		exit(0);
	case 'ESC':
		exit(0);
	}

	glutPostRedisplay();
}

void reshape(int width, int height) {
	windowWidth = width;
	windowHeight = height;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("HW2");

	glutDisplayFunc(display);
	glutMotionFunc(mouseMoved);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}