#ifndef ESFINGE_H
#define ESFINGE_H


#include <objeto.h>

class Esfinge : public Objeto
{
public:
    Model3DS* model;
public:
    Esfinge();
    Esfinge( Vetor3D nt, Vetor3D na, Vetor3D ns );
    void desenha();
};

#endif // ESFINGE_H
