#ifndef CAMEL_H
#define CAMEL_H

#include <objeto.h>

class Camel : public Objeto
{
public:
    Model3DS* model;
public:
    Camel();
    Camel( Vetor3D nt, Vetor3D na, Vetor3D ns );
    void desenha();
};

#endif // CAMEL_H
