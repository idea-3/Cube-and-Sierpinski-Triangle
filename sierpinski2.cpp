#include <windows.h>
#include <GL/glut.h>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

typedef GLfloat point2[2];

point2 v[]={{-2.0, -2.0}, {2.0, -2.0}, {0.0, 2.0}};
int n;

void myinit() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor (1.0, 1.0, 1.0,1.0);
}

void triangle(point2 a, point2 b, point2 c) {
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
	}
	else {
		int v1 = rand() % 9 + 1;
		float red = (float) v1 / 10;
		int v2 = rand() % 9 + 1;
		float green = (float) v2 / 10;
		int v3 = rand() % 9 + 1;
		float blue = (float) v3 / 10;
		glColor3f(red, green, blue);
		triangle(a,b,c);
	}
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	divide_triangle(v[0], v[1], v[2], n);
	glFlush();
}

int main(int argc, char **argv) {
	n = atoi(argv[1]);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(600, 500);
	glutCreateWindow("Sierpinski Triangle with Triangles");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}
