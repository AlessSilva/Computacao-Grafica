#include "CurvaCubica.h"
#include <gui.h>
#include <vector>

CurvaCubica::CurvaCubica(){
    //ug = 0;
    ug = 1;
    inverse = false;
}

void CurvaCubica::PolinomioInterpolador(){


    M[0][0] = -4.5; M[0][1] = 13.5; M[0][2] = -13.5; M[0][3] = 4.5;
    M[1][0] = 9.0; M[1][1] = -22.5; M[1][2] = 18.0; M[1][3] = -4.5;
    M[2][0] = -5.5; M[2][1] = 9.0; M[2][2] = -4.5; M[2][3] = 1.0;
    M[3][0] = 1.0; M[3][1] = 0.0; M[3][2] = 0.0; M[3][3] = 0.0;

}

void CurvaCubica::Hermite(){


    M[0][0] = 2.0; M[0][1] = -2.0; M[0][2] = 1.0; M[0][3] = 1.0;
    M[1][0] = -3.0; M[1][1] = 3.0; M[1][2] = -2.0; M[1][3] = -1.0;
    M[2][0] = 0.0; M[2][1] = 0.0; M[2][2] = 1.0; M[2][3] = 0.0;
    M[3][0] = 1.0; M[3][1] = 0.0; M[3][2] = 0.0; M[3][3] = 0.0;

}

void CurvaCubica::Bezier(){


    M[0][0] = -1.0; M[0][1] = 3.0; M[0][2] = -3.0; M[0][3] = 1.0;
    M[1][0] = 3.0; M[1][1] = -6.0; M[1][2] = 3.0; M[1][3] = 0.0;
    M[2][0] = -3.0; M[2][1] = 3.0; M[2][2] = 0.0; M[2][3] = 0.0;
    M[3][0] = 1.0; M[3][1] = 0.0; M[3][2] = 0.0; M[3][3] = 0.0;

}

void CurvaCubica::CatmullRom(){

    M[0][0] = -0.5; M[0][1] = 1.5; M[0][2] = -1.5; M[0][3] = 0.5;
    M[1][0] = 1.0; M[1][1] = -2.5; M[1][2] = 2.0; M[1][3] = -0.5;
    M[2][0] = -0.5; M[2][1] = 0.0; M[2][2] = 0.5; M[2][3] = 0.0;
    M[3][0] = 0.0; M[3][1] = 1.0; M[3][2] = 0.0; M[3][3] = 0.0;

}

void CurvaCubica::BSplines(){

    M[0][0] = -1/6.0; M[0][1] = 0.5; M[0][2] = -0.5; M[0][3] = 1/6.0;
    M[1][0] = 0.5; M[1][1] = -1.0; M[1][2] = 0.5; M[1][3] = 0.0;
    M[2][0] = -0.5; M[2][1] = 0.0; M[2][2] = 0.5; M[2][3] = 0.0;
    M[3][0] = 1/6.0; M[3][1] = 2/3.0; M[3][2] = 1/6.0; M[3][3] = 0.0;


}

Vetor3D CurvaCubica::Pt( float u, vector<Vetor3D> pontos, int ordemDerivada ){

    float U[4];

    switch (ordemDerivada) {
    case 0:
        U[0] = pow(u,3);
        U[1] = pow(u,2);
        U[2] = u;
        U[3] = 1;
        break;
    case 1:
        U[0] = 3*pow(u,2);
        U[1] = 2*u;
        U[2] = 1;
        U[3] = 0;
        break;
    case 2:
        U[0] = 6*u;
        U[1] = 2;
        U[2] = 0;
        U[3] = 0;
        break;
    }

    float UM[4] = {0,0,0,0};

    for( int i = 0; i < 4; i++ ){

        for( int j = 0; j < 4; j++ ){

            UM[i] += U[j]*M[j][i];

        }
    }

    Vetor3D ponto;

    for( int j = 0; j < 4; j++ ){
        ponto.x += UM[j]*(pontos[j].x);
    }

    for( int j = 0; j < 4; j++ ){
        ponto.y += UM[j]*(pontos[j].y);
    }

    for( int j = 0; j < 4; j++ ){
        ponto.z += UM[j]*(pontos[j].z);
    }

    return ponto;

}

void CurvaCubica::desenhaPista(vector<Vetor3D> pontos, int tipoCurva, float delta_u){

    switch (tipoCurva) {
    case 1:
        PolinomioInterpolador();
        break;
    case 2:
        Hermite();
        break;
    case 3:
        Bezier();
        break;
    case 4:
        CatmullRom();
        break;
    default:
        BSplines();
        break;
    }

    if( tipoCurva == 4 || tipoCurva == 5 ){

        vector<Vetor3D> pontosAtuais;
        for( int i = 0; i <= pontos.size(); i++ ){

            pontosAtuais.push_back( pontos[ (i)%pontos.size() ] );
            pontosAtuais.push_back( pontos[ (i+1)%pontos.size() ] );
            pontosAtuais.push_back( pontos[ (i+2)%pontos.size() ] );
            pontosAtuais.push_back( pontos[ (i+3)%pontos.size() ] );

            for( float u = 0; u <= 1; u = u + delta_u ){
                desenhaTrilho(pontosAtuais,u);
            }
            pontosAtuais.clear();

        }

    }else{
       vector<Vetor3D> pontosAtuais;

       pontosAtuais.push_back(pontos[0]);
       pontosAtuais.push_back(pontos[1]);
       pontosAtuais.push_back(pontos[2]);
       pontosAtuais.push_back(pontos[3]);

       for( float u = 0; u <= 1; u = u + delta_u ){
           desenhaTrilho(pontosAtuais,u);
        }
    }

}

void CurvaCubica::desenhaTrilho( vector<Vetor3D> pontos, float u){

    Vetor3D origem = Pt(u,pontos,0);

    Vetor3D k = Pt(u,pontos,1)*(-1);
    k.normaliza();

    Vetor3D up = Pt(u,pontos,2);
    up.normaliza();

    Vetor3D i = up.operator ^(k);
    i.normaliza();

    Vetor3D j = k.operator ^(i);

    float T[16] = {
        i.x, j.x, k.x, origem.x,
        i.y, j.y, k.y, origem.y,
        i.z, j.z, k.z, origem.z,
        0,  0,   0,   1
    };

    glPushMatrix();
        glMultTransposeMatrixf(T);
        trilho.desenha();
    glPopMatrix();

}

void CurvaCubica::desenhaCarrinho(vector<Vetor3D> pontos, float delta_u){

    if( ug < 0 ){
        ug+=pontos.size();
    }
    if(ug > pontos.size()){
        ug -= pontos.size();
    }
    int in = ug;
    float u = ug-in;

    vector<Vetor3D> pontosAtuais;

    pontosAtuais.push_back( pontos[ in%pontos.size() ] );
    pontosAtuais.push_back( pontos[ (in+1)%pontos.size() ] );
    pontosAtuais.push_back( pontos[ (in+2)%pontos.size() ] );
    pontosAtuais.push_back( pontos[ (in+3)%pontos.size() ] );

    Vetor3D origem = Pt(u,pontosAtuais,0);

    Vetor3D k = Pt(u,pontosAtuais,1)*(-1);
    k.normaliza();

    Vetor3D up = Pt(u,pontosAtuais,2);
    up.normaliza();

    Vetor3D i = up.operator ^(k);
    i.normaliza();

    Vetor3D j = k.operator ^(i);

    float T[16] = {
        i.x, j.x, k.x, origem.x,
        i.y, j.y, k.y, origem.y,
        i.z, j.z, k.z, origem.z,
        0,  0,   0,   1
    };

    glPushMatrix();
      glMultTransposeMatrixf(T);
      bruxa.desenha();
      morcego.desenha();
    glPopMatrix();

    if( inverse ){
        ug-=delta_u;
    }else{
        ug+=delta_u;
    }

}

Camera* CurvaCubica::coordCamGoPro(vector<Vetor3D> pontos){

    int in = ug;
    float u = ug-in;

    vector<Vetor3D> pontosAtuais;

    pontosAtuais.push_back( pontos[ in%pontos.size() ] );
    pontosAtuais.push_back( pontos[ (in+1)%pontos.size() ] );
    pontosAtuais.push_back( pontos[ (in+2)%pontos.size() ] );
    pontosAtuais.push_back( pontos[ (in+3)%pontos.size() ] );

   Camera * cam = new CameraDistante();
   cam->e = Pt(u,pontosAtuais,0);
   cam->c = cam->e + Pt(u,pontosAtuais,1);
   cam->u = Pt(u,pontosAtuais,2);

   return cam;

}
