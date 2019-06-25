#include <iostream>
#include <fstream>
#include <sstream>
#include <gui.h>
#include <vector>
#include <CurvaCubica.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <demonio.h>

using namespace std;

vector<Vetor3D> pontosControle;
CurvaCubica* curva = new CurvaCubica();
int tipoCurva = 5;
int pontoSelecionado = 0;
float delta_u_pista = 0.05;
float delta_u_carrinho = 0.01;
Model3DS* arvore = new Model3DS("../3DS/tree.3DS");
Demonio demonio;
Morcego morcego;
float t = 0;

/*-------- Manipulacao dos pontos de controle ---------*/
void salvarPontosApresentacao(){
    ofstream arq("ap.txt");
    arq.clear();
    arq << pontosControle.size() << "\n";
    for (int i = 0; i < pontosControle.size();i++) {
        arq << pontosControle[i].x << "\n";
        arq << pontosControle[i].y << "\n";
        arq << pontosControle[i].z << "\n";
    }
}

void salvarPontosMontanhaRussa(){
    ofstream arq("pontos.txt");
    arq.clear();
    arq << pontosControle.size() << "\n";
    for (int i = 0; i < pontosControle.size();i++) {
        arq << pontosControle[i].x << "\n";
        arq << pontosControle[i].y << "\n";
        arq << pontosControle[i].z << "\n";
    }
}

void carregarPontosApresentacao(){
    ifstream arq("ap.txt");
    pontosControle.clear();

    string linha;
    getline(arq,linha);
    int n_pontos = std::stoi (linha);
    for( int i = 0; i < n_pontos; i++ ){
        Vetor3D ponto;
        getline(arq,linha);
        ponto.x = std::stof(linha);
        getline(arq,linha);
        ponto.y = std::stof(linha);
        getline(arq,linha);
        ponto.z = std::stof(linha);
        pontosControle.push_back(ponto);
    }
}

void carregarPontosMontanhaRussa(){
    ifstream arq("pontos.txt");
    pontosControle.clear();

    string linha;
    getline(arq,linha);
    int n_pontos = std::stoi (linha);
    for( int i = 0; i < n_pontos; i++ ){
        Vetor3D ponto;
        getline(arq,linha);
        ponto.x = std::stof(linha);
        getline(arq,linha);
        ponto.y = std::stof(linha);
        getline(arq,linha);
        ponto.z = std::stof(linha);
        pontosControle.push_back(ponto);
    }
}

void adicionaPonto(){
    Vetor3D novoPonto;
    novoPonto.x = 0;
    novoPonto.y = 0;
    novoPonto.z = 0;
    if( pontoSelecionado != 0 ){
        pontosControle.insert(pontosControle.begin()+pontoSelecionado,novoPonto);
    }
    else{
        pontosControle.push_back(novoPonto);
    }

}

void removerPonto(){
    pontosControle.erase(pontosControle.begin()+pontoSelecionado-1);
}

void desenhaPontosDeControle()
{
    for (int i=0; i<pontosControle.size(); i++) {
        if (i == pontoSelecionado-1) {
            GUI::setColor(1,0.43,0.78,1,true);
        } else {
            GUI::setColor(1,1,1,true);
        }
        Vetor3D p = pontosControle[i];
        glPushName(i+1);
            glPushMatrix();
            GUI::drawSphere(p.x,p.y,p.z,2);
            GUI::setColor(0,0,0);
            GUI::drawSphere(p.x+0.5,p.y+1,p.z+1,0.5);
            GUI::drawSphere(p.x-0.5,p.y+1,p.z+1,0.5);
            glBegin(GL_LINE_STRIP);
            glVertex3f(p.x+1,p.y,p.z+2);
            glVertex3f(p.x+1,p.y-0.5,p.z+2);
            glVertex3f(p.x+0.5,p.y,p.z+2);
            glVertex3f(p.x+0.5,p.y-0.5,p.z+2);
            glVertex3f(p.x,p.y,p.z+2);
            glVertex3f(p.x,p.y-0.5,p.z+2);
            glVertex3f(p.x-0.5,p.y,p.z+2);
            glVertex3f(p.x-0.5,p.y-0.5,p.z+2);
            glVertex3f(p.x-1,p.y,p.z+2);
            glVertex3f(p.x-1,p.y-0.5,p.z+2);
            glEnd();
            glPopMatrix();
        glPopName();
    }
}

//-------------------Picking------------------

int picking( GLint cursorX, GLint cursorY, int w, int h ) {
    int BUFSIZE = 512;
    GLuint selectBuf[512];

    GUI::pickingInit(cursorX,cursorY,w,h,selectBuf,BUFSIZE);

    GUI::displayInit();
    desenhaPontosDeControle();
    return GUI::pickingClosestName(selectBuf,BUFSIZE);
}

//-------------------ViewPorts------------------
bool viewports = false;
bool scissored = false;

void cenario();

void viewPorts() {
    float width = glutGUI::width;
    float height = glutGUI::height;

    glViewport(0, 0, width, height);
        //glLoadIdentity();
        //gluLookAt(glutGUI::cam->e.x,glutGUI::cam->e.y,glutGUI::cam->e.z, glutGUI::cam->c.x,glutGUI::cam->c.y,glutGUI::cam->c.z, glutGUI::cam->u.x,glutGUI::cam->u.y,glutGUI::cam->u.z);
            cenario();

    if (!scissored) {
        glViewport(0, (3*height/4), width/4, height/4);
    } else {
        GUI::glScissoredViewport(0, 3*height/4, width/4, height/4);
    }
        glLoadIdentity();
        gluLookAt(0,7.5,4.2,0,8,0,0,1,0);
        Camera* c = curva->coordCamGoPro(pontosControle);
        gluLookAt(c->e.x,c->e.y,c->e.z, c->c.x,c->c.y,c->c.z, c->u.x,c->u.y,c->u.z);
            cenario();
}

/*------------Cenario-------------------*/
void cenario() {
    GUI::setLight(0,1,3,5,true,false);
    GUI::drawOrigin(3);

    GUI::setColor(0,0,0);
    Desenha::drawGrid( 15, 0, 15, 2 );

    glPushMatrix();
    glTranslatef(-8,5,8);
    demonio.desenha();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(12,10,4);
    demonio.desenha();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15,0,-10);
    glRotatef(-90,1,0,0);
    arvore->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-20,0,-15);
    glRotatef(-90,1,0,0);
    arvore->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,-23);
    glRotatef(-90,1,0,0);
    arvore->draw();
    glPopMatrix();

    desenhaPontosDeControle();

    if( pontosControle.size() >= 4 ){
        curva->desenhaPista(pontosControle,tipoCurva,delta_u_pista);
        curva->desenhaCarrinho(pontosControle,delta_u_carrinho);
    }

    if( glutGUI::gopro != 3 ){
        glutGUI::cam = curva->coordCamGoPro(pontosControle);
    }
}

void desenha() {
    GUI::displayInit();

    if (!viewports) {
        cenario();
    } else {
        viewPorts();
    }

    if (pontoSelecionado!=0) {
        pontosControle[pontoSelecionado-1].x += glutGUI::dtx;
        pontosControle[pontoSelecionado-1].y += glutGUI::dty;
        pontosControle[pontoSelecionado-1].z += glutGUI::dtz;
    }

    GUI::displayEnd();
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
    case 'v':
        viewports = !viewports;
        break;
    case 'b':
        scissored = !scissored;
        break;
    case 'S':
        salvarPontosMontanhaRussa();
        break;
    case 'K':
        carregarPontosMontanhaRussa();
        break;
    case 's':
        salvarPontosApresentacao();
        break;
    case 'k':
        carregarPontosApresentacao();
        break;
    case 'a':
        adicionaPonto();
        break;
    case 'r':
        if( pontosControle.size() != 1 ){
        removerPonto();
        }
    case 'Q':
        delta_u_pista+=0.001;
        break;
    case 'W':
        delta_u_pista-=0.001;
        break;
    case 'O':
        delta_u_carrinho+=0.001;
        break;
    case 'P':
        delta_u_carrinho-=0.001;
        break;
    case 'i':
        curva->inverse =  !curva->inverse;
        break;
    case '1':
        tipoCurva  = 1;
        break;
    case '2':
        tipoCurva  = 2;
        break;
    case '3':
        tipoCurva  = 3;
        break;
    case '4':
        tipoCurva  = 4;
        break;
    case '5':
        tipoCurva  = 5;
        break;
    case '=':
        glutGUI::gopro = 2;
        break;
    case 'c':
        glutGUI::gopro = 3;
        glutGUI::cam = new CameraDistante(0,100,50,0,0,3,0,1,0);
        break;
    case '+':
        glutGUI::gopro =  1;
        Mix_Chunk *risada = Mix_LoadWAV("../Music/br.wav");
        Mix_PlayChannel(-1,risada,0);
        break;

    }

}

void mouse(int button, int state, int x, int y) {
    GUI::mouseButtonInit(button,state,x,y);

    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            int pick = picking( x, y, 5, 5 );
            if (pick != 0) {
                pontoSelecionado = pick;
                glutGUI::lbpressed = false;
            }
        }
    }
}

int main()
{
    cout << "Hello World!" << endl;
    SDL_Init(SDL_INIT_AUDIO);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2,2048);
        Mix_Music *backgroundSound = Mix_LoadMUS("../Music/bs.mp3");
        Mix_PlayMusic(backgroundSound,-1);
        carregarPontosMontanhaRussa();
        Mix_Chunk *risada = Mix_LoadWAV("../Music/br.wav");
        Mix_PlayChannel(-1,risada,0);
        GUI gui = GUI(800,600,desenha,teclado,mouse);
        Mix_FreeMusic(backgroundSound);
    Mix_CloseAudio();
    SDL_Quit();
}
