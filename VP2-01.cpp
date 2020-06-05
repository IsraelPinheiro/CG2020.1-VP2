// OpenGL.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <GLFW/glut.h>
#include <Windows.h>
#include <math.h>
#include <time.h>

using namespace std;

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 140, 0, 110);
}

void Draw(void){
	glColor3ub(237, 28, 36);
	glBegin(GL_POLYGON);
		glVertex2i(10, 70);
		glVertex2i(40, 100);
		glVertex2i(70, 70);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(70, 70);
		glVertex2i(100, 100);
		glVertex2i(130, 70);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(10, 70);
		glVertex2i(70, 10);
		glVertex2i(130, 70);
	glEnd();
	glColor3ub(0, 162, 232);
	glBegin(GL_POLYGON);
		glVertex2i(45, 100);
		glVertex2i(70, 75);
		glVertex2i(95, 100);
	glEnd();
	glColor3ub(0, 0, 0);
	glLineWidth(7);
	glBegin(GL_LINE_LOOP);
		glVertex2i(45, 100);
		glVertex2i(70, 75);
		glVertex2i(95, 100);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2i(10, 70);
		glVertex2i(40,100);
		glVertex2i(70,70);
		glVertex2i(100, 100);
		glVertex2i(130, 70);
		glVertex2i(70,10);
	glEnd();
	glFlush();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(420, 330);
	glutCreateWindow("Shape Of My Heart");
	init();
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}