#ifndef FARAO_H
#define FARAO_H


#include <objeto.h>

class Farao : public Objeto
{
public:
    Model3DS* model;
public:
    Farao();
    Farao( Vetor3D nt, Vetor3D na, Vetor3D ns );
    void desenha();
};
#endif // FARAO_H
