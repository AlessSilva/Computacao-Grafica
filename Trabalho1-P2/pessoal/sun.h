#ifndef SUN_H
#define SUN_H


#include <objeto.h>
#include <Vetor3D.h>
#include "extra.h"


class Sun : public Objeto
{
public:
    Model3DS* model;
    double angulo = 0;
    bool shadow;
public:
    Sun();
    void desenha();
};

#endif // SUN_H
