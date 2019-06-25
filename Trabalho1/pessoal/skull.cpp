#include "skull.h"

Skull::Skull() : Objeto (5) {}

Skull::Skull( Vetor3D nt, Vetor3D na, Vetor3D ns ): Objeto (5) {
    t = nt;
    a = na;
    s = ns;
    origem = false;
}

void Skull::desenha()
{
    glPushMatrix();
        Objeto::desenha();
            glPushMatrix();
                glScalef(0.3,0.3,0.3);
                glTranslatef(0,0,-1);
                Vetor3D v1, v2, v3, normal;

                //Frente do cranio
                GUI::setColor(1,1,1);
                glBegin(GL_POLYGON);
                        glNormal3f(-2,1.5,2);
                        glVertex3f(-0.5,0,2);
                        glVertex3f(0,2,1);
                        glVertex3f(-1,2,0);
                glEnd();
                glBegin(GL_POLYGON);
                        glNormal3f(2,1.5,2);
                        glVertex3f(0.5,0,2);
                        glVertex3f(1,2,0);
                        glVertex3f(0,2,1);
                glEnd();
                glBegin(GL_POLYGON);
                        glNormal3f(0,1,2);
                        glVertex3f(0.5,0,2);
                        glVertex3f(0,2,1);
                        glVertex3f(-0.5,0,2);
                glEnd();
                glBegin(GL_POLYGON);
                        glNormal3f(0,2,0);
                        glVertex3f(0,2,1);
                        glVertex3f(1,2,0);
                        glVertex3f(-1,2,0);
                glEnd();

                //Parte de trás do cranio

                glBegin(GL_POLYGON);
                        glNormal3f(1.6,-1.9,-1.5);
                        glVertex3f(0,1,0.2);
                        glVertex3f(1,2,0);
                        glVertex3f(0.5,0,2);
                glEnd();
                glBegin(GL_POLYGON);
                        glNormal3f(-1.6,-1.9,-1.5);
                        glVertex3f(-0.5,0,2);
                        glVertex3f(-1,2,0);
                        glVertex3f(0,1,0.2);
                glEnd();
                glBegin(GL_POLYGON);
                       glNormal3f(0,-0.4,-2);
                       glVertex3f(0,1,0.2);
                       glVertex3f(-1,2,0);
                       glVertex3f(1,2,0);
                glEnd();
                glBegin(GL_POLYGON);
                        glNormal3f(0,-1.8,-1);
                        glVertex3f(-0.5,0,2);
                        glVertex3f(0,1,0.2);
                        glVertex3f(0.5,0,2);
                glEnd();

                //Chifre direito
                GUI::setColor(1,1,0.7);
                GUI::drawBox(2,2,0,1,1.5,0.2);

                glBegin(GL_POLYGON);
                        glNormal3f(0,0.1,0.5);
                        glVertex3f(2,2,0.2);
                        glVertex3f(1.75,3,0);
                        glVertex3f(1.5,2,0.2);
                glEnd();
                glBegin(GL_POLYGON);
                        glNormal3f(0,0,-0.5);
                        glVertex3f(1.5,2,0);
                        glVertex3f(1.75,3,0);
                        glVertex3f(2,2,0);
                glEnd();
                glBegin(GL_POLYGON);
                        glNormal3f(0.2,0.05,0);
                        glVertex3f(2,2,0.2);
                        glVertex3f(2,2,0);
                        glVertex3f(1.75,3,0);
                glEnd();
                glBegin(GL_POLYGON);
                        glNormal3f(-0.2,0.05,0);
                        glVertex3f(1.5,2,0);
                        glVertex3f(1.5,2,0.2);
                        glVertex3f(1.75,3,0);
                glEnd();

                //Chifre esquerdo

                glPushMatrix();
                    GUI::glReflectPlaneYZf();
                    GUI::drawBox(1,1.5,0.2,2,2,0);
                    glBegin(GL_POLYGON);
                            glNormal3f(0,0.1,0.5);
                            glVertex3f(1.5,2,0.2);
                            glVertex3f(1.75,3,0);
                            glVertex3f(2,2,0.2);
                    glEnd();
                    glBegin(GL_POLYGON);
                            glNormal3f(0,0,-0.5);
                            glVertex3f(2,2,0);
                            glVertex3f(1.75,3,0);
                            glVertex3f(1.5,2,0);
                    glEnd();
                    glBegin(GL_POLYGON);
                            glNormal3f(0.2,0.05,0);
                            glVertex3f(1.75,3,0);
                            glVertex3f(2,2,0);
                            glVertex3f(2,2,0.2);
                    glEnd();
                    glBegin(GL_POLYGON);
                            glNormal3f(-0.2,0.05,0);
                            glVertex3f(1.75,3,0);
                            glVertex3f(1.5,2,0.2);
                            glVertex3f(1.5,2,0);
                    glEnd();
                glPopMatrix();

                //olho direito
                glPushMatrix();
                    glTranslatef(0.5,1.5,0.8);
                    GUI::setColor(0,0,0);
                    GUI::drawSphere(0,0,0,0.2);
                glPopMatrix();

                //olho esquerdo
                glPushMatrix();
                    glTranslatef(-0.5,1.5,0.8);
                    GUI::setColor(0,0,0);
                    GUI::drawSphere(0,0,0,0.2);
                glPopMatrix();

        glPopMatrix();
        glPushMatrix();
            if( selecionado ){
                GUI::setColor(1,0,0,0.5);
                GUI::drawBox(-0.7,0,0.5,0.7,1,-0.5);
            }
         glPopMatrix();
    glPopMatrix();
}
