#ifndef PALMTREE_H
#define PALMTREE_H


#include <objeto.h>

class Palmtree : public Objeto
{
public:
    Model3DS* model;
public:
    Palmtree();
    Palmtree( Vetor3D nt, Vetor3D na, Vetor3D ns );
    void desenha();
};

#endif // PALMTREE_H
