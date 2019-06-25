#include <iostream>
#include <fstream>
#include <sstream>
#include <gui.h>
#include "extra.h"
#include "CameraDistante.h"
#include "CameraJogo.h"

using namespace std;

#include <vector>
#include <cactus.h>
#include <camel.h>
#include <pyramid.h>
#include <skull.h>
#include <tree.h>
#include <mummy.h>
#include <esfinge.h>
#include <farao.h>
#include <sun.h>

vector<Objeto*> objetos;
int posSelecionado = -1;
bool incluirObjeto = false;
bool pontual = true;
bool abilitarSombra = true;
bool abilitarParede = false;
bool abilitarCubo = false;
float k = 0.0;

void desenha() {
    GUI::displayInit();

        GUI::drawOrigin(1);
        GUI::setColor(1,0.7,0);
        glPushMatrix();
            glTranslated(0,-0.01,0);
            GUI::drawFloor(12,15);
        glPopMatrix();

        //Parede
        if( abilitarParede ){
            GUI::setColor(1,1,1);
            GUI::drawBox(-6,0,7, -5.5,5.5,-7);
            GUI::drawBox(6,0,7, 5.5,5.5,-7);
            glPushMatrix();
                glTranslatef(7,2.7,0);
                glRotatef(45,0,0,1);
                glBegin(GL_QUADS);
                  glNormal3f(-1,0,0);
                  glVertex3f(1, 0, 7);
                  glVertex3f(1, 6, 7);
                  glVertex3f(1, 6, -7);
                  glVertex3f(1, 0, -7);
                glEnd();
            glPopMatrix();
            GUI::drawBox(6,5.5,-7.5, -5.5,0,-7);
        }

        //Cubo
        if(abilitarCubo){
           GUI::setColor(0.184314,0.184314,0.309804);
           GUI::drawBox(-1,0,1, 1,2,-1);
        }

        //------------ Inicio Sombra -------------------------------------------------------------
        GLfloat sombra[4][4];
        float lightPos[4] = {glutGUI::lx,glutGUI::ly+4,glutGUI::lz,pontual};

        if( abilitarSombra and glutGUI::enabled_light[7] ){
            glColor3d(0,0,0);
            bool auxiliar = glutGUI::draw_eixos;
            glutGUI::draw_eixos = false;
            glDisable(GL_LIGHTING);
                for (int i = 0; i < objetos.size(); ++i) {
                    //Desenhar Sombra no chao
                    glPushMatrix();
                         GUI::shadowMatrixYk(sombra,lightPos,k);
                         glMultTransposeMatrixf( (GLfloat*)sombra );
                         if( objetos[i]->sombra ){
                              objetos[i]->desenha();
                         }
                     glPopMatrix();
                     //Desenhar Sombra nas paredes
                     if( abilitarParede ){
                         //Parede Esq
                         glPushMatrix();
                             GLfloat plano1[4] = {1,0,0,5.47};
                             GUI::shadowMatrix(sombra,plano1,lightPos);
                             glMultTransposeMatrixf( (GLfloat*)sombra );
                             if( objetos[i]->sombra ){
                                   objetos[i]->desenha();
                             }
                         glPopMatrix();
                         //Parede Dir
                         glPushMatrix();
                             GLfloat plano2[4] = {-1,0,0,5.47};
                             GUI::shadowMatrix(sombra,plano2,lightPos);
                             glMultTransposeMatrixf( (GLfloat*)sombra );
                             if( objetos[i]->sombra ){
                                   objetos[i]->desenha();
                             }
                         glPopMatrix();
                         //Parede Fundo
                         glPushMatrix();
                             GLfloat plano3[4] = {0,0,1,6.97};
                             GUI::shadowMatrix(sombra,plano3,lightPos);
                             glMultTransposeMatrixf( (GLfloat*)sombra );
                             if( objetos[i]->sombra ){
                                   objetos[i]->desenha();
                             }
                         glPopMatrix();
                         //Parede Inclinada
                         glPushMatrix();
                             GLfloat plano4[4] = {-1,-1,0,11};
                             GUI::shadowMatrix(sombra,plano4,lightPos);
                             glMultTransposeMatrixf( (GLfloat*)sombra );
                             if( objetos[i]->sombra ){
                                   objetos[i]->desenha();
                             }
                         glPopMatrix();

                     }
                }
            glEnable(GL_LIGHTING);
            glutGUI::draw_eixos = auxiliar;
        }
        //---------------- Fim Sombra ------------------------------------------------------

        for (int i = 0; i < objetos.size(); ++i) {
            glPushMatrix();
                objetos[i]->desenha();
            glPopMatrix();
        }

        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->t.x += glutGUI::dtx;
            objetos[posSelecionado]->t.y += glutGUI::dty;
            objetos[posSelecionado]->t.z += glutGUI::dtz;

            objetos[posSelecionado]->a.x += glutGUI::dax;
            objetos[posSelecionado]->a.y += glutGUI::day;
            objetos[posSelecionado]->a.z += glutGUI::daz;

            objetos[posSelecionado]->s.x += glutGUI::dsx;
            objetos[posSelecionado]->s.y += glutGUI::dsy;
            objetos[posSelecionado]->s.z += glutGUI::dsz;
        }
    GUI::displayEnd();
}

//Manipulação de arquivo
void salvar(){
    ofstream arq("cenario.txt");
    arq.clear();
    arq << objetos.size() << "\n";
    for (int i = 0; i < objetos.size();i++) {
        arq << objetos[i]->tipo << "\n";
        arq << objetos[i]->t.x << "\n";
        arq << objetos[i]->t.y << "\n";
        arq << objetos[i]->t.z << "\n";
        arq << objetos[i]->a.x << "\n";
        arq << objetos[i]->a.y << "\n";
        arq << objetos[i]->a.z << "\n";
        arq << objetos[i]->s.x << "\n";
        arq << objetos[i]->s.y << "\n";
        arq << objetos[i]->s.z << "\n";
    }
}

void carregar(){
    ifstream arq("cenario.txt");
    string linha;
    getline(arq,linha);
    int n_obj = std::stoi (linha);
    int tipo;
    double tx, ty, tz, ax, ay, az, sx, sy, sz;
    for( int i = 0; i < n_obj; i++ ){
      getline(arq,linha);
      tipo = std::stoi (linha);
      getline(arq,linha);
      tx = std::stof(linha);
      getline(arq,linha);
      ty = std::stof(linha);
      getline(arq,linha);
      tz = std::stof(linha);
      getline(arq,linha);
      ax = std::stof(linha);
      getline(arq,linha);
      ay = std::stof(linha);
      getline(arq,linha);
      az = std::stof(linha);
      getline(arq,linha);
      sx = std::stof(linha);
      getline(arq,linha);
      sy = std::stof(linha);
      getline(arq,linha);
      sz = std::stof(linha);
      Vetor3D tn = Vetor3D(tx,ty,tz);
      Vetor3D an = Vetor3D(ax,ay,az);
      Vetor3D sn = Vetor3D(sx,sy,sz);
      if( tipo == 1 ){
        objetos.push_back(new Cactus(tn, an, sn));
      }else if( tipo == 2 ){
        objetos.push_back(new Camel(tn, an, sn));
      }else if( tipo == 4 ){
        objetos.push_back(new Pyramid(tn, an, sn));
      }else if( tipo == 5 ){
          objetos.push_back(new Skull(tn, an, sn));
      }else if( tipo == 6 ){
         objetos.push_back(new Tree(tn, an, sn));
      }else if( tipo == 7 ){
         objetos.push_back(new Mummy(tn, an, sn));
      }else if( tipo == 8 ){
          objetos.push_back(new Esfinge(tn, an, sn));
      }else if( tipo == 9 ){
          objetos.push_back(new Farao(tn, an, sn));
      }

    }
}

void carregarNovamente(){
    objetos.clear();
    carregar();
    glutGUI::trans_obj = false;
}

//Manipulaçao de objeto
void next(){
    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->selecionado = false;
    }
    posSelecionado++;
    posSelecionado = posSelecionado%objetos.size();
    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->selecionado = true;
    }
}

void back(){
    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->selecionado = false;
    }
    posSelecionado--;
    if (posSelecionado < 0) {
        posSelecionado = objetos.size()-1;
    }
    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->selecionado = true;
    }
}

void apagarSelecionado(){
    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos.erase(objetos.begin()+posSelecionado);
    }
}

void apagarUltimo(){
    if(objetos.size() >0 ){
        objetos.pop_back();
    }
}

void naoSelecionar(){
    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->selecionado = false;
    }
    glutGUI::trans_obj = false;
}

void mostrarOrigem(){

    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->origem = !objetos[posSelecionado]->origem;
    }
    glutGUI::trans_obj = false;

}

void mostrarSombra(){
    if(posSelecionado >= 0 and posSelecionado < objetos.size()){
        objetos[posSelecionado]->sombra = !objetos[posSelecionado]->sombra;
    }
}

void teclado(unsigned char key, int x, int y) {

    GUI::keyInit(key,x,y);

    switch (key) {

    case 't':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;

    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;

    case 'n':
        next();
        break;

    case 'b':
        back();
        break;

    case '@':
        naoSelecionar();
        break;

    case '0':
        mostrarOrigem();
        break;

    case 'p':
        apagarSelecionado();
        break;

    case 'P':
        apagarUltimo();
        break;

    case 'S':
        salvar();
        break;

    case 's':
        carregarNovamente();
        break;

    case 'O':
        incluirObjeto = !incluirObjeto;
        break;

    case 'w':
        if (incluirObjeto) {
            objetos.push_back( new Cactus() );
        }
        break;

    case 'W':
        if (incluirObjeto) {
            objetos.push_back( new Camel() );
        }
        break;

    case 'e':
        if (incluirObjeto) {
            objetos.push_back( new Pyramid() );
        }
        break;

    case 'E':
        if (incluirObjeto) {
            objetos.push_back( new Skull() );
        }
        break;

    case 'r':
        if (incluirObjeto) {
            objetos.push_back( new Farao() );
        }
        break;

    case 'R':
        if (incluirObjeto) {
            objetos.push_back( new Tree() );
        }
        break;

    case 'a':
        if (incluirObjeto) {
            objetos.push_back( new Mummy() );
        }
        break;

    case 'A':
        if (incluirObjeto) {
            objetos.push_back( new Esfinge() );
        }
        break;

    case '1':
        glutGUI::cam = new CameraDistante(0,0,15, 0,0,0, 0,1,0);

        break;

    case '2':
        glutGUI::cam = new CameraDistante(0,15,0, 0,0,0, 0,0,1);
        break;

    case '3':
        glutGUI::cam = new CameraDistante(5,5,5, 0,0,0, 0,1,0);

        break;

    case '4':
        glutGUI::cam = new CameraDistante(10,1,10, 0,0,0, 0,1,0);

        break;

    case '5':
        glutGUI::cam = new CameraDistante(5,3,7, 0,0,0, 0,1,0);

        break;

    case '6':
        glutGUI::obliqua = false;
        glutGUI::perspective = true;
        glutGUI::ortografica = false;
        break;

    case '8':
        glutGUI::obliqua = true;
        glutGUI::perspective = false;
        glutGUI::ortografica = false;
        break;

    case '9':
        glutGUI::obliqua = false;
        glutGUI::perspective = false;
        glutGUI::ortografica = true;
        break;

    case 'M':
        mostrarSombra();
        break;

    case '?':
        abilitarSombra = !abilitarSombra;
        break;

    case '/':
        abilitarParede = !abilitarParede;
        break;

    case '.':
        pontual = !pontual;
        break;    

    case '+':
       abilitarCubo = !abilitarCubo;
       break;

    case ')':
        glutGUI::anguloObliqua += 1;
        break;

    case '(':
        glutGUI::anguloObliqua -= 1;
        break;

    case '*':
        glutGUI::anguloObliqua = 30;
        break;
    case 'K':
        k += 0.1;
        break;

    case 'k':
        k -= 0.1;
        break;

    default:
        break;
    }
}

int main()
{
    //glutGUI::perspective = false;
    carregar();
    GUI::setLight(7,0,4,0,true,false,false,false,true);
    glutGUI::enabled_light[7] = true;
    GUI gui = GUI(800,600,desenha,teclado);
}
