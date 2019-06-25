#ifndef MUMMY_H
#define MUMMY_H


#include <objeto.h>
#include <Vetor3D.h>

class Mummy : public Objeto
{
public:
    Model3DS* model;
    double angulocabeca = -70;
    int giro;
public:
    Mummy();
    Mummy( Vetor3D nt, Vetor3D na, Vetor3D ns );
    void desenha();
};

#endif // CHARACTER_H
