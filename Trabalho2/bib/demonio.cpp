#include "demonio.h"

Demonio::Demonio()
{}

void Demonio::desenha(){

    glPushMatrix();
                glTranslatef(0,2,0);
                GUI::setColor(1,0,0);
                glPushMatrix();
                //tronco
                    GUI::drawBox(0.2,2,0,-0.2,0.2,0.1);
                    GUI::drawBox(1,0.2,0,-1,0,0.2);
                    double i = 0;
                    while( i < 1 ){
                        GUI::drawBox(0.4,2-i,-0.1,0.2,1.9-i,0);
                        i = i + 0.2;
                    }
                    GUI::drawBox(0.8,0.9,-0.1, 0.2,0.8,0);
                    GUI::drawBox(0.9,2,-0.1, 0.8,0.8,0);
                    GUI::glReflectPlaneYZf();
                        GUI::drawBox(-0.2,0.2,0.1, 0.2,2,0);
                        GUI::drawBox(-1,0,0.2,1,0.2,0);
                        i = 0;
                        while( i < 1 ){
                            GUI::drawBox(0.2,1.9-i,0, 0.4,2-i,-0.1);
                            i = i + 0.2;
                        }
                        GUI::drawBox(0.2,0.8,0, 0.8,0.9,-0.1);
                        GUI::drawBox(0.8,0.8,0, 0.9,2,-0.1);
                glPopMatrix();

                glPushMatrix();
                //braços
                    GUI::setColor(0,0,0);
                    GUI::drawSphere(1.2,1.9,0,0.2);
                    GUI::setColor(1,0,0);
                    GUI::drawBox(1.4,2.1,0.3, 1,1.7,2);
                    GUI::glReflectPlaneYZf();
                            GUI::setColor(0,0,0);
                            GUI::drawSphere(1.2,1.9,0,0.2);
                            GUI::setColor(1,0,0);
                            GUI::drawBox(1,1.7,2, 1.4,2.1,0.3);
                glPopMatrix();

                glPushMatrix();
                //cabeça
                    if( (giro == 1) and (angulocabeca <= 70) ){
                        angulocabeca += 5;
                    }
                    else{
                        giro = -1;
                    }
                    if( (giro == -1) and (angulocabeca >= -70) ){
                        angulocabeca -= 5;
                    }
                    else{
                        giro = 1;
                    }
                    glRotatef(angulocabeca,0,1,0);
                    GUI::drawBox(0.7,3.3,-0.3, -0.7,2.1,0.3);

                    //Chifre direito
                    glPushMatrix();
                    glTranslatef(-0.5,1.3,0);
                    GUI::setColor(0,0,0);
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
                      glPopMatrix();

                                    //Chifre esquerdo

                      glPushMatrix();
                      glTranslatef(0.5,1.3,0);
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
                        GUI::setColor(1,1,1);
                        glTranslatef(0.4,3,0.2);
                        GUI::drawSphere(0,0,0,0.2);
                    glPopMatrix();
                    //olho esquerdo
                    glPushMatrix();
                        GUI::setColor(1,1,1);
                        glTranslatef(-0.4,3,0.2);
                        GUI::drawSphere(0,0,0,0.2);
                    glPopMatrix();
                glPopMatrix();

                glPushMatrix();
                //pernas
                    GUI::setColor(0,0,0);
                    GUI::drawSphere(0.9,-0.2,0.1,0.2);
                    GUI::setColor(1,0,0);
                    GUI::drawBox(1.1,-0.4,-0.1, 0.7,-2,0.3);
                    GUI::glReflectPlaneYZf();
                        GUI::setColor(0,0,0);
                        GUI::drawSphere(0.9,-0.2,0.1,0.2);
                        GUI::setColor(1,0,0);
                        GUI::drawBox(0.7,-2,0.3, 1.1,-0.4,-0.1);
                glPopMatrix();
            glPopMatrix();

}
