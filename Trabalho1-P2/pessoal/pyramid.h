#ifndef PYRAMID_H
#define PYRAMID_H

#include <objeto.h>
#include <Vetor3D.h>

class Pyramid : public Objeto
{
public:
    Model3DS* model;
public:
    Pyramid();
    Pyramid( Vetor3D nt, Vetor3D na, Vetor3D ns );
    void desenha();
};

#endif // PYRAMID_H
