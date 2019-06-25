#include "pyramid.h"

Pyramid::Pyramid() : Objeto (4) {}

Pyramid::Pyramid( Vetor3D nt, Vetor3D na, Vetor3D ns ): Objeto (4){
    t = nt;
    a = na;
    s = ns;
    origem = false;
}

void Pyramid::desenha(){
    glPushMatrix();

        Objeto::desenha();
        glPushMatrix();
            GUI::setColor(0.81,0.71, 0.23);
            Vetor3D v1, v2, v3, normal;
            glBegin(GL_POLYGON);
                    glNormal3f(5,6.25,5);
                    //glVertex3f(2.5,0,0);
                    //glVertex3f(0,2,0);
                    //glVertex3f(0,0,2.5);

                    glVertex3f(2.5,0,0);
                    glVertex3f(0,2,0);
                    glVertex3f(0,0,2.5);
            glEnd();
            glBegin(GL_POLYGON);
                    glNormal3f(-5,5,4);
                    glVertex3f(0,0,2.5);
                    glVertex3f(0,2,0);
                    glVertex3f(-2.5,0,0);
            glEnd();
            glBegin(GL_POLYGON);
                    glNormal3f(5,6.25,-5);
                    glVertex3f(0,0,-2.5);
                    glVertex3f(0,2,0);
                    glVertex3f(2.5,0,0);
            glEnd();
            glBegin(GL_POLYGON);
                    glNormal3f(-5,6.25,-5);
                    glVertex3f(-2.5,0,0);
                    glVertex3f(0,2,0);
                    glVertex3f(0,0,-2.5);
            glEnd();
            glBegin(GL_POLYGON);
                    glNormal3f(0,-1,0);
                    glVertex3f(0,0,2.5);
                    glVertex3f(-2.5,0,0);
                    glVertex3f(0,0,-2.5);
                    glVertex3f(2.5,0,0);
                    glVertex3f(0,0,2.5);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            if( selecionado ){
                GUI::setColor(1,0,0,0.5);
                GUI::drawBox(-2.5,0,2.5,2.5,2,-2.5);
            }
        glPopMatrix();
    glPopMatrix();

}
