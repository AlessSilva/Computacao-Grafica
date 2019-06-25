#ifndef TREE_H
#define TREE_H


#include <objeto.h>

class Tree : public Objeto
{
public:
    Model3DS* model;
public:
    Tree();
    Tree( Vetor3D nt, Vetor3D na, Vetor3D ns );
    void desenha();
};

#endif // TREE_H
