#include "tree.h"

Tree::Tree() : Objeto (6){
    model = new Model3DS("../3ds/tree.3DS");
}

Tree::Tree( Vetor3D nt, Vetor3D na, Vetor3D ns ): Objeto (6) {
    t = nt;
    a = na;
    s = ns;
    origem = false;
    model = new Model3DS("../3ds/tree.3DS");
}

void Tree::desenha(){
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            GUI::setColor(0.81,0.71, 0.23);
            glRotatef(-90,1,0,0);
            glScalef(0.2,0.2,0.2);
            model->draw();
        glPopMatrix();
        glPushMatrix();
            if( selecionado ){
                GUI::setColor(1,0,0,0.5);
                GUI::drawBox(-1.2,0,1,1.2,2.5,-1.2);
            }
         glPopMatrix();
    glPopMatrix();
}
