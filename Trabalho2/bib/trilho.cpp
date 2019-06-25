#include "trilho.h"

Trilho::Trilho()
{}

void Trilho::desenha(){

    glPushMatrix();
        GUI::setColor(1,1,1);
        Desenha::drawGrid( 1, 0, 2, 1 );
        glScalef(1,2,0.5);
        GUI::setColor(1,0.459,0.094);
        GUI::drawBox(-2,0,-2,2,1,2);
        GUI::setColor(0,0,0,1);
        glBegin(GL_LINE_STRIP);
          glVertex3f(-2,0,0.02);
          glVertex3f(-2,1,0.02);
        glEnd();
        glBegin(GL_LINE_STRIP);
          glVertex3f(2,0,0.02);
          glVertex3f(2,1,0.02);
        glEnd();
        glBegin(GL_LINE_STRIP);
          glVertex3f(-2,0,2.02);
          glVertex3f(-2,1,2.02);
        glEnd();
        glBegin(GL_LINE_STRIP);
          glVertex3f(2,0,2.02);
          glVertex3f(2,1,2.02);
        glEnd();
        glBegin(GL_LINE_STRIP);
          glVertex3f(-1,0,2.02);
          glVertex3f(-1,1,2.02);
        glEnd();
        glBegin(GL_LINE_STRIP);
          glVertex3f(1,0,2.02);
          glVertex3f(1,1,2.02);
        glEnd();
        glBegin(GL_LINE_STRIP);
          glVertex3f(-2,0,-2.02);
          glVertex3f(-2,1,-2.02);
        glEnd();
        glBegin(GL_LINE_STRIP);
          glVertex3f(2,0,-2.02);
          glVertex3f(2,1,-2.02);
        glEnd();
        glBegin(GL_LINE_STRIP);
          glVertex3f(-1,0,-2.02);
          glVertex3f(-1,1,-2.02);
        glEnd();
        glBegin(GL_LINE_STRIP);
          glVertex3f(1,0,-2.02);
          glVertex3f(1,1,-2.02);
        glEnd();
        glTranslatef(0,1.01,0);
        glRotatef(45,0,1,0);
        GUI::setColor(0,0,0,1);
        GUI::drawQuad(1,1,1);
     glPopMatrix();

}
