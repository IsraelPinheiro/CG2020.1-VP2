// OpenGL.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <GLFW/glut.h>
#include <Windows.h>
#include <math.h>
#include <time.h>

using namespace std;

int startX = -1000;

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 1000, 0, 1000);
}

void DrawPlane(int x){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
		glVertex2f(startX + 100.0, 300.0);
		glVertex2f(startX + 1000.0, 300.0);
		glVertex2f(startX + 800.0, 500.0);
		glVertex2f(startX + 300.0, 500.0);
		glVertex2f(startX + 100.0, 700.0);
	glEnd();
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
		glVertex2f(startX + 400.0, 400.0);
		glVertex2f(startX + 200.0, 100.0);
		glVertex2f(startX + 400.0, 100.0);
		glVertex2f(startX + 600.0, 400.0);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(startX + 450.0, 500.0);
		glVertex2f(startX + 650.0, 500.0);
		glVertex2f(startX + 850.0, 700.0);
		glVertex2f(startX + 650.0, 700.0);
	glEnd();
	glFlush();
	if (startX < 1500) {
		startX += 10;
		glutTimerFunc(1000.0 / 60.0, DrawPlane, 0);
	}
	else {
		startX = -1000;
		glutTimerFunc(1000.0 / 60.0, DrawPlane, 0);
	}
}

void animation(void){
	DrawPlane(0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Learn To Fly");
	init();
	glutDisplayFunc(animation);
	glutMainLoop();
	return 0;
}