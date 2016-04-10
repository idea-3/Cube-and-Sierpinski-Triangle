#include <windows.h>
#include <GL/glut.h>
#include <cstdlib>
#include <stdlib.h>

#include <iostream>

using namespace std;

typedef GLfloat point2[2];

point2 v[]={{-2.0, -2.0}, {2.0, -2.0}, {0.0, 2.0}};
int n;
float reds[5], greens[5], blues[5];

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
		glColor3f(reds[(n-m) % 5], greens[(n-m) % 5], blues[(n-m) % 5]);
		triangle(v0, v1, v2);
	}
	else {
		glColor3f(1, 0, 1);
		triangle(a,b,c);
	}
}

void randomizeColor() {
	reds[0] = 0;
	greens[0] = 0;
	blues[0] = 1;
	reds[1] = 1;
	greens[1] = 0;
	blues[1] = 0;
	reds[2] = 0;
	greens[2] = 1;
	blues[2] = 0;
	reds[3] = 1;
	greens[3] = 1;
	blues[3] = 1;
	reds[4] = 1;
	greens[4] = 1;
	blues[4] = 0;
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
	glutCreateWindow("2D Gasket");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}

