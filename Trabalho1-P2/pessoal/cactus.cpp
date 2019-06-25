#include "cactus.h"

Cactus::Cactus() : Objeto (1){
    model = new Model3DS("../3ds/cactus.3DS");
}

Cactus::Cactus( Vetor3D nt, Vetor3D na, Vetor3D ns ): Objeto (1){
    t = nt;
    a = na;
    s = ns;
    origem = false;
    model = new Model3DS("../3ds/cactus.3DS");
}

void Cactus::desenha(){   
    glPushMatrix(); 
        Objeto::desenha();
        glPushMatrix();
            glRotatef(-90,1,0,0);
            glScalef(0.005,0.005,0.005);
            model->draw();
        glPopMatrix();

        glPushMatrix();
            if( selecionado ){
                GUI::setColor(1,0,0, 0.5);
                GUI::drawBox(-1.2,0,0.5, 1.2,1,-0.5);
            }
        glPopMatrix();
    glPopMatrix();
}
