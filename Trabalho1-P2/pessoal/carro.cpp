#include "carro.h"

Carro::Carro()
{
    model = new Model3DS("/home/alessandro/Desktop/04_descricao trabalho 1/3ds/pharaoh.3ds");
}

void Carro::desenha()
{
    glPushMatrix();
        Objeto::desenha();
        GUI::setColor(2,0,0);
        glScalef(5,5,5.2);
        glRotatef(-90,1,0,0);
        glTranslatef(0,0,0);
        glScalef(0.001,0.001,0.001);
        model->draw();
    glPopMatrix();
}
