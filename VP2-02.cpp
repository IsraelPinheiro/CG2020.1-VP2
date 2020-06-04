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
	gluOrtho2D(0, 3000, 0, 3000);
}

void DrawPoint(void){
	int pointSize = (rand() % 30) + 1;
	int posX = rand() % 3000;
	int posY = rand() % 3000;
	glColor3f((float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX);
	glPointSize(pointSize);
	glBegin(GL_POINTS);
	glVertex2i(posX, posY);
	glEnd();
}

void DrawPoints(void) {
	srand(time(NULL));
	for (int i = 0; i < 1000; i++) {
		DrawPoint();
	}
	glFinish();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(750, 750);
	glutCreateWindow("It's Over 9000!");
	init();
	glutDisplayFunc(DrawPoints);
	glutMainLoop();
	return 0;
}