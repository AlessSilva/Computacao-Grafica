#include "bruxa.h"

Bruxa::Bruxa()
{
    model = new Model3DS("../3DS/noisQvoaBruxao.3DS");
}

void Bruxa::desenha(){

    glPushMatrix();
        GUI::setColor(1,0.43,0.78);
        Desenha::drawGrid( 1, 3.5, 2, 1 );
        glTranslatef(0,5,0);
        glScalef(0.02,0.02,0.02);
        glRotatef(-90,1,0,0);
        glRotatef(-270,0,0,1);
        model->draw();
    glPopMatrix();

}
