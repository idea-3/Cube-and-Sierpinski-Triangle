#include <windows.h>
#include <GL/glut.h>
#include <cstdlib>

using namespace std;

#define MAX_RGB 255.0

struct Point {
  GLfloat x, y, z;
  Point(GLfloat x = 0, GLfloat y = 0, GLfloat z = 0): x(x), y(y), z(z) {};
};

// Global Variables
double rotateX = -45;
double rotateY = 45;

void display() {
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  // Reset transformations
  glLoadIdentity();
   
  // Rotate
  glRotatef(rotateX, 1.0, 0.0, 0.0);
  glRotatef(rotateY, 0.0, 1.0, 0.0);

  // FRONT
  glBegin(GL_POLYGON);
  glColor3f( 1.0,  107/MAX_RGB, 107/MAX_RGB);
  glVertex3f(  0.5, -0.5, -0.5 );
  glVertex3f(  0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  // BACK
  glBegin(GL_POLYGON);
  glColor3f( 200/MAX_RGB, 1.0, 0.0 );
  glVertex3f(  0.5, -0.5, 0.5 );
  glVertex3f(  0.5,  0.5, 0.5 );
  glVertex3f( -0.5,  0.5, 0.5 );
  glVertex3f( -0.5, -0.5, 0.5 );
  glEnd();
   
  // RIGHT
  glBegin(GL_POLYGON);
  glColor3f( 78/MAX_RGB, 205/MAX_RGB, 196/MAX_RGB );
  glVertex3f( 0.5, -0.5, -0.5 );
  glVertex3f( 0.5,  0.5, -0.5 );
  glVertex3f( 0.5,  0.5,  0.5 );
  glVertex3f( 0.5, -0.5,  0.5 );
  glEnd();
   
  // LEFT
  glBegin(GL_POLYGON);
  glColor3f( 167/MAX_RGB,  2/MAX_RGB, 103/MAX_RGB);
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
   
  // TOP
  glBegin(GL_POLYGON);
  glColor3f( 1.0,  202/MAX_RGB, 27/MAX_RGB );
  glVertex3f(  0.5,  0.5,  0.5 );
  glVertex3f(  0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glEnd();
   
  // BOTTOM
  glBegin(GL_POLYGON);
  glColor3f( 186/MAX_RGB, 1/MAX_RGB, 1.0 );
  glVertex3f(  0.5, -0.5, -0.5 );
  glVertex3f(  0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  glFlush();
  glutSwapBuffers();
}

void specialKeys(int key, int x, int y) {
  if (key == GLUT_KEY_RIGHT) {
    rotateY += 5;
  } else if (key == GLUT_KEY_LEFT) {
    rotateY -= 5;
  } else if (key == GLUT_KEY_UP) {
    rotateX += 5;
  } else if (key == GLUT_KEY_DOWN) {
    rotateX -= 5;
  }

  // Request display update
  glutPostRedisplay();
}

void init() {
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glColor3f(0.0, 0.0, 0.0);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 600.0, 0.0, 500.0, 0.0, 1.0);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(600, 500);
  glutInitWindowPosition(100, 0);
  glutCreateWindow("Cube");
  glEnable(GL_DEPTH_TEST);
  glutDisplayFunc(display);
  glutSpecialFunc(specialKeys);
  glutMainLoop();
  return 0;
}