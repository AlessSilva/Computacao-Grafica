#include "palmtree.h"

Palmtree::Palmtree() : Objeto (3)
{
    model = new Model3DS("../3ds/palmtree.3DS");
}

Palmtree::Palmtree( Vetor3D nt, Vetor3D na, Vetor3D ns ): Objeto (3)
{
    t = nt;
    a = na;
    s = ns;
    origem = false;
    model = new Model3DS("../3ds/palmtree.3DS");
}

void Palmtree::desenha()
{
    glPushMatrix();

        Objeto::desenha();

        glPushMatrix();
            glTranslatef(-0.2,1,0.1);
            glRotatef(-90,1,0,0);
            glScalef(0.005,0.005,0.005);
            model->draw();
        glPopMatrix();

        glPushMatrix();
            if( selecionado ){
                GUI::setColor(1,0,0,0.5);
                GUI::drawBox(-0.7,0,0.8,1,2.5,-0.8);
            }
         glPopMatrix();
    glPopMatrix();
}
