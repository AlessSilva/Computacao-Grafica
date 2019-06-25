#ifndef CACTUS_H
#define CACTUS_H

#include <objeto.h>

class Cactus : public Objeto
{
public:
    Model3DS* model;
public:
    Cactus();
    Cactus( Vetor3D nt, Vetor3D na, Vetor3D ns );
    void desenha();
};

#endif // CACTUS_H
