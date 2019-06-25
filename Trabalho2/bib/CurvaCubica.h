#ifndef CURVACUBICA_H
#define CURVACUBICA_H

#include <Vetor3D.h>
#include <gui.h>
#include <vector>
#include <bruxa.h>
#include <morcego.h>
#include <trilho.h>

class CurvaCubica
{
public:
    CurvaCubica();
    float ug;
    bool inverse;
    float M[4][4];
    void PolinomioInterpolador();
    void Hermite();
    void Bezier();
    void CatmullRom();
    void BSplines();
    Vetor3D Pt( float u, vector<Vetor3D> pontos, int ordemDerivada );
    void desenhaPista( vector<Vetor3D> pontos, int tipoCurva, float delta_u );
    void desenhaTrilho( vector<Vetor3D> pontos, float u);
    void desenhaCarrinho( vector<Vetor3D> pontos, float delta_u );
    Camera* coordCamGoPro( vector<Vetor3D> pontos );
    Bruxa bruxa;
    Morcego morcego;
    Trilho trilho;
};

#endif CURVACUBICA_H
