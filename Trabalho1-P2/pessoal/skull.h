#ifndef SKULL_H
#define SKULL_H

#include <objeto.h>
#include <Vetor3D.h>

class Skull : public Objeto
{
public:
    Model3DS* model;
public:
    Skull();
    Skull( Vetor3D nt, Vetor3D na, Vetor3D ns );
    void desenha();
};
#endif // SKULL_H
