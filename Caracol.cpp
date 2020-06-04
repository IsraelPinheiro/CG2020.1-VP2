// OpenGL.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.

#include <iostream>
#include <stdio.h>
#include <string.h>
#include<GLFW/glut.h>
#include<Windows.h>

using namespace std;

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 1280, 0, 680);
}

void DrawLine(int iX, int iY, int fX, int fY) {
	int dX = fX - iX, dY = fY - iY, steps;
	float xIncrement, yIncrement, x = iX, y = iY;

	if (fabs(dX) > fabs(dY)) {
		steps = fabs(dX);
	}
	else {
		steps = fabs(dY);
	}

	xIncrement = float(dX) / steps;
	yIncrement = float(dY) / steps;

	glBegin(GL_POINTS);
	glColor3f(1, 0, 0);
	glVertex2i(round(x), round(y));
	glEnd();

	for (int i = 0; i < steps; i++) {
		x += xIncrement;
		y += yIncrement;
		glBegin(GL_POINTS);
		glColor3f(1, 0, 0);
		glVertex2i(round(x), round(y));
		glEnd();
	}
}

void DrawShell(void) {
	float theta;
	float pi = 3.142;
	int lines = 150;
	int baseRadius = 300;
	int radius = baseRadius;
	int centerX = 640;
	int centerY = 340;

	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < lines; i++) {
		theta = i * pi / (lines / 2);
		DrawLine(centerX, centerY, (radius * cos(theta)) + centerX, (radius * sin(theta)) + centerY);
		radius = radius - (baseRadius / lines);
	};
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1280, 680);
	glutCreateWindow("Ghost In The Shell");
	init();
	glutDisplayFunc(DrawShell);
	glutMainLoop();
	return 0;
}