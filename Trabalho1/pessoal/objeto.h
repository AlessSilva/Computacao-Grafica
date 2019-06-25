#ifndef OBJETO_H
#define OBJETO_H

#include <gui.h>

class Objeto
{
public:
    Vetor3D t = Vetor3D(0,0,0);
    Vetor3D a = Vetor3D(0,0,0);
    Vetor3D s = Vetor3D(1,1,1);
    int tipo;
    bool selecionado = false;
    bool origem = true;
public:
    Objeto( int t );
    virtual void desenha();
};

#endif // OBJETO_H
