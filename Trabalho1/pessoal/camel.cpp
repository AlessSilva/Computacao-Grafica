#include "camel.h"

Camel::Camel() : Objeto (2){
    model = new Model3DS("../3ds/camel.3DS");
}

Camel::Camel( Vetor3D nt, Vetor3D na, Vetor3D ns ): Objeto (2){
    t = nt;
    a = na;
    s = ns;
    origem = false;
    model = new Model3DS("../3ds/camel.3DS");
}

void Camel::desenha(){
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            srand((unsigned)time(0));
            int maior = 100;
            int menor = 1;
            int aleatorio = rand()%(maior-menor+1) + menor;

            if( aleatorio < 10 ){
                glTranslatef(0,0.05,0);
            }
            if( aleatorio >= 10 and aleatorio < 20  ){
                glRotatef(2,0,1,0);
            }
            if( aleatorio >= 20 and aleatorio < 35  ){
                glRotatef(-2,0,1,0);
            }

            glTranslatef(-0.05,0,0.2);
            glRotatef(-90,1,0,0);
            glScalef(0.0002,0.0002,0.0002);
            model->draw();
        glPopMatrix();

        glPushMatrix();
            if( selecionado ){
                GUI::setColor(1,0,0,0.5);
                GUI::drawBox(-0.5,0,1,0.5,1.5,-1);
            }
        glPopMatrix();
    glPopMatrix();
}
