#include "esfinge.h"

Esfinge::Esfinge() : Objeto (8){
    model = new Model3DS("../3ds/esfinge.3DS");
}

Esfinge::Esfinge( Vetor3D nt, Vetor3D na, Vetor3D ns ): Objeto (8){
    t = nt;
    a = na;
    s = ns;
    origem = false;
    model = new Model3DS("../3ds/esfinge.3DS");
}

void Esfinge::desenha(){
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glRotatef(-90,1,0,0);
            glScalef(0.04,0.04,0.04);
            model->draw();
        glPopMatrix();

        glPushMatrix();
            if( selecionado ){
                GUI::setColor(1,0,0,0.5);
                GUI::drawBox(-1.2,0,3, 1.2,1.7,-3);
            }
         glPopMatrix();
    glPopMatrix();
}
