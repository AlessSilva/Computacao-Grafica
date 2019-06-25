#include "farao.h"

Farao::Farao() : Objeto (9){
    model = new Model3DS("../3ds/farao.3DS");
}

Farao::Farao( Vetor3D nt, Vetor3D na, Vetor3D ns ): Objeto (9){
    t = nt;
    a = na;
    s = ns;
    origem = false;
    model = new Model3DS("../3ds/farao.3DS");
}

void Farao::desenha(){
    glPushMatrix();

        Objeto::desenha();
        glPushMatrix();
            glTranslatef(0.1,0.67,0);
            glRotatef(-90,1,0,0);
            glScalef(0.001,0.001,0.001);
            model->draw();
        glPopMatrix();

        glPushMatrix();
            if( selecionado ){
                GUI::setColor(1,0,0,0.5);
                GUI::drawBox(-0.8,0,0.4, 0.8,1.5,-0.4);
            }
         glPopMatrix();
    glPopMatrix();
}
