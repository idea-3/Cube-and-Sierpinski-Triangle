#include "Draw.h"

void drawHandleSolid(HDC hDC) {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Segitiga warna merah
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex3f(-0.8, 0, 0);
    glVertex3f(-0.6, 0.4, 0);
    glVertex3f(-0.4, 0, 0);
    glEnd();
    glPopMatrix();

    // Segitiga warna hijau
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glColor3f(0, 1, 0);
    glVertex3f(-0.3, 0, 0);
    glVertex3f(-0.1, 0.4, 0);
    glVertex3f(0.1, 0, 0);
    glEnd();
    glPopMatrix();

    // Segitiga warna biru
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 1);
    glVertex3f(0.2, 0, 0);
    glVertex3f(0.4, 0.4, 0);
    glVertex3f(0.6, 0, 0);
    glEnd();
    glPopMatrix();

    SwapBuffers(hDC);
}

void drawHandleGradient(HDC hDC) {
    // Segitiga warna gradient merah, hijau, biru
    glPushMatrix();
    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex3f(-0.5, -0.8, 0);
    glColor3f(0, 1, 0);
    glVertex3f(0, -0.1, 0);
    glColor3f(0, 0, 1);
    glVertex3f(0.5, -0.8, 0);
    glEnd();
    glPopMatrix();
     
    // Segitiga warna gradient merah
    glPushMatrix();
    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex3f(-0.8, 0.4, 0);
    glColor3f(0.2, 0, 0);
    glVertex3f(-0.6, 0.8, 0);
    glColor3f(0.2, 0, 0);
    glVertex3f(-0.4, 0.4, 0);
    glEnd();
    glPopMatrix();

    // Segitiga warna gradient hijau
    glPushMatrix();
    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);
    glColor3f(0, 1, 0);
    glVertex3f(-0.3, 0.4, 0);
    glColor3f(0, 0.2, 0);
    glVertex3f(-0.1, 0.8, 0);
    glColor3f(0, 0.2, 0);
    glVertex3f(0.1, 0.4, 0);
    glEnd();
    glPopMatrix();

    // Segitiga warna gradient biru
    glPushMatrix();
    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 1);
    glVertex3f(0.2, 0.4, 0);
    glColor3f(0, 0, 0.2);
    glVertex3f(0.4, 0.8, 0);
    glColor3f(0, 0, 0.2);
    glVertex3f(0.6, 0.4, 0);
    glEnd();
    glPopMatrix();

    SwapBuffers(hDC);
}