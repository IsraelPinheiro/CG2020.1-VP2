// OpenGL.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <GLFW/glut.h>
#include <Windows.h>
#include <math.h>
#include <time.h>

using namespace std;

int qtdEstrelas;

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 3000, 0, 3000);
}

void DrawStar(void) {
	float theta;
	float pi = 3.142;
	float sides = 5;
	int innerRadius = (rand() % 150) + 50;
	int pointSize = (rand() % 100) + 50;
	int outerRadius = innerRadius + pointSize;
	int posX = rand() % 3000;
	int posY = rand() % 3000;
	glColor3f((float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX);

	glBegin(GL_POLYGON);
	for (int i = 0; i < sides + 1; i++) {
		theta = i * pi / (sides / 2);
		glVertex2f(innerRadius * cos(theta) + posX, innerRadius * sin(theta) + posY);
		theta = (i * pi / (sides / 2)) + (pi / sides);
		glVertex2f(outerRadius * cos(theta) + posX, outerRadius * sin(theta) + posY);
		theta = (i + 1) * pi / (sides / 2);
		glVertex2f(innerRadius * cos(theta) + posX, innerRadius * sin(theta) + posY);
	};
	glEnd();
}

void DrawStars(void) {
	srand(time(NULL));
	for (int i = 0; i < qtdEstrelas; i++) {
		DrawStar();
	}
	glFinish();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(750, 750);
	glutCreateWindow("Lucy In The Sky With Diamonds");
	init();

	cout << "Quantas estrelas devem ser geradas ?: ";
	cin >> qtdEstrelas;

	glutDisplayFunc(DrawStars);
	glutMainLoop();
	return 0;
}