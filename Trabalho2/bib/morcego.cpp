#include "morcego.h"

Morcego::Morcego()
{
   model = new Model3DS("../3DS/batima_beguinha.3DS");
}

void Morcego::desenha(){
     glPushMatrix();
        glTranslatef(-2,6,0);
        glScalef(0.02,0.02,0.02);
        glRotatef(-90,1,0,0);
        glRotatef(-270,0,0,1);
        model->draw();
     glPopMatrix();
}
