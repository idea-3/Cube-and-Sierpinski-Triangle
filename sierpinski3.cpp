#include <windows.h>
#include <GL/glut.h>
#include <cstdlib>
#include <stdlib.h>

#include <iostream>

using namespace std;

typedef GLfloat point2[2];

point2 v[]={{-2.0, -2.0}, {2.0, -2.0}, {0.0, 2.0}};
int n;
float *reds, *greens, *blues;

void myinit() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor (1.0, 1.0, 1.0,1.0);
}

void triangle( point2 a, point2 b, point2 c) {
	glBegin(GL_TRIANGLES);
	glVertex2fv(a);
	glVertex2fv(b);
	glVertex2fv(c);
	glEnd();
}

void divide_triangle(point2 a, point2 b, point2 c, int m) {
	point2 v0, v1, v2;
	int j;
	if(m>0) {
		for(j=0; j<2; j++) v0[j]=(a[j]+b[j])/2;
		for(j=0; j<2; j++) v1[j]=(a[j]+c[j])/2;
		for(j=0; j<2; j++) v2[j]=(b[j]+c[j])/2;
		divide_triangle(a, v0, v1, m-1);
		divide_triangle(c, v1, v2, m-1);
		divide_triangle(b, v2, v0, m-1);
		glColor3f(reds[m], greens[m], blues[m]);
		triangle(v0, v1, v2);
	}
	else {
		glColor3f(reds[m], greens[m], blues[m]);
		triangle(a,b,c);
	}
}

void randomizeColor() {
	reds = new float[n + 1];
	greens = new float[n + 1];
	blues = new float[n + 1];
	for (int i = 0; i <= n; i++) {
		reds[i] = (float) (rand() % 9 + 1) / 10;
		greens[i] = (float) (rand() % 9 + 1) / 10;
		blues[i] = (float) (rand() % 9 + 1) / 10;
	}
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	randomizeColor();
	divide_triangle(v[0], v[1], v[2], n);
	glFlush();
}

int main(int argc, char **argv) {
	// best n = 5
	n = atoi(argv[1]);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(600, 500);
	glutCreateWindow("Sierpinski Triangle with Triangles");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}

