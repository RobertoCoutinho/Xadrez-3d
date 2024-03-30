#include <iostream>

using namespace std;

#include <gui.h>
#include <Desenha.h>
#include <GL/glut.h>


Vetor3D posEsfera = Vetor3D(2,1,0);
float raioEsfera = 0.2;

//Model3DS carro = Model3DS("../3ds/cartest.3DS");

void casa()
{
    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

    //frontal
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(0,0,1);
        glVertex3f(1,0,1);
        glVertex3f(1,1,1);
        glVertex3f(0,1,1);
    glEnd();
    //traseira
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glVertex3f(0,0,0);
        glVertex3f(0,1,0);
        glVertex3f(1,1,0);
        glVertex3f(1,0,0);
    glEnd();
    //esquerda
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(0,0,1);
        glVertex3f(0,1,1);
        glVertex3f(0,1,0);
    glEnd();
    //direita
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glVertex3f(1,0,0);
        glVertex3f(1,1,0);
        glVertex3f(1,1,1);
        glVertex3f(1,0,1);
    glEnd();
    //superior
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glVertex3f(0,1,0);
        glVertex3f(0,1,1);
        glVertex3f(1,1,1);
        glVertex3f(1,1,0);
    glEnd();
    //inferior
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glVertex3f(0,0,0);
        glVertex3f(1,0,0);
        glVertex3f(1,0,1);
        glVertex3f(0,0,1);
    glEnd();
    //teto esquerdo
    glBegin(GL_POLYGON);
        glNormal3f(-1,1,0);
        glVertex3f(0,1,0);
        glVertex3f(0,1,1);
        glVertex3f(0.5,1.5,0.5);
    glEnd();
}

void objetoCortado() {
    //GUI::drawSphere(posEsfera.x,posEsfera.y,posEsfera.z, raioEsfera);
    GUI::drawHalfSphere(0,0,0, raioEsfera);
    //GUI::drawSphereInsideBox222(posEsfera.x,posEsfera.y,posEsfera.z, raioEsfera);
    //GUI::drawSphereInsideBox222(0,0,0, raioEsfera);

    //    //clipping
    //    //GLdouble plane[4] = { 0.0, 1.0, 0.0, 1}; //deixa a parte acima (y) do plano aparecendo (plano posicionado no y=-1, d desloca o plano no sentido oposto à normal) (corta o y<-1)
    //    //GLdouble plane[4] = { 0.0, -1.0, 0.0, 1}; //deixa a parte abaixo (y) do plano aparecendo (plano posicionado no y=1, d desloca o plano no sentido oposto à normal) (corta o y>1)
    //    GLdouble plane[4] = { 1.0, 1.0, 0.0, -1.0 }; //deixa a parte à frente do plano (z) do plano aparecendo (plano posicionado no z=0, d desloca o plano no sentido oposto à normal) (corta o z<0)
    //    glClipPlane(GL_CLIP_PLANE0, plane);
    //    glEnable(GL_CLIP_PLANE0);



    //    //objeto a ser cortado
    //    //GUI::drawSphere(0,0,0,raioEsfera);
    //    casa();

    //    //clipping
    //    glDisable(GL_CLIP_PLANE0);
}

int idTexture = 0;

void objetoComTextura() {
    //Usando texturas

    GUI::habilitaTextura(true,false,0);
    GUI::selecionaTextura(idTexture);

    //objeto a ser texturizado
    GUI::setColor(0.5,0.5,0.5);
    //GUI::drawBox(-1,-1,-1, 1,1,1);
    //GUI::drawSphere(posEsfera.x,posEsfera.y,posEsfera.z, raioEsfera);

    glBegin(GL_POLYGON);
        glTexCoord2f(0,0); glVertex3d(0,0,0);
        glTexCoord2f(0.5,0); glVertex3d(1,0,0);
        glTexCoord2f(0.5,1); glVertex3d(1,1,0);
        glTexCoord2f(0,1); glVertex3d(0,1,0);
    glEnd();

    GUI::desabilitaTextura(true,false);
}
void peao(float colorR, float colorG, float colorB){

    glPushMatrix();

    glTranslatef(0,-0.35, 0);
    GUI::habilitaTextura(true,false,0);
    GUI::selecionaTextura(6);
    GUI::setColor(colorR,colorG,colorB);

    GUI::drawSphere(0,2,0, 0.3);
    glRotatef(90, 1, 0, 0);
    glTranslatef(0, 0, -1.8);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.33, 0.33, 0.15, 100, 60);

    glTranslatef(0, 0, 0.15);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.17, 0.5, 1, 60, 100);

    glTranslatef(0, 0, 1);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.57, 0.57, 0.15, 100, 60);

    glTranslatef(0, 0, 0.13);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.65, 0.65, 0.15, 100, 60);

    GUI::desabilitaTextura(true,false);

    glPopMatrix();

}

void bispo(float colorR, float colorG, float colorB){

    glPushMatrix();

    glTranslatef(0,-0.35, 0);
    GUI::habilitaTextura(true,false,0);
    GUI::selecionaTextura(6);
    GUI::setColor(colorR,colorG,colorB);

    GUI::drawSphere(0,2.51,0, 0.12);

    GUI::drawSphere(0,2.15,0, 0.3);

    glRotatef(90, 1, 0, 0);
    glTranslatef(0, 0, -1.8);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.33, 0.33, 0.15, 100, 60);

    glTranslatef(0, 0, 0.15);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.13, 0.40, 1, 60, 100);

    glTranslatef(0, 0, 1);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.5, 0.5, 0.15, 100, 60);

    glTranslatef(0, 0, 0.13);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.6, 0.6, 0.15, 100, 60);

    glTranslatef(0, 0, -1.39);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.27, 0.27, 0.15, 100, 60);

    GUI::desabilitaTextura(true,false);

    glPopMatrix();

}

void casaTaboleiro(){
    //frontal
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,1,0.5);
        glVertex3f(-0.5,1,0.5);
    glEnd();
    //traseira
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glVertex3f(-0.5,0,-0.5);
        glVertex3f(-0.5,1,-0.5);
        glVertex3f(0.5,1,-0.5);
        glVertex3f(0.5,0,-0.5);
    glEnd();
    //esquerda
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(-0.5,1,0.5);
        glVertex3f(-0.5,1,-0.5);
        glVertex3f(-0.5,0,-0.5);
    glEnd();
    //direita
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,0,-0.5);
        glVertex3f(0.5,1,-0.5);
        glVertex3f(0.5,1,0.5);
    glEnd();
    //superior
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glVertex3f(-0.5,1,0.5);
        glVertex3f(0.5,1,0.5);
        glVertex3f(0.5,1,-0.5);
        glVertex3f(-0.5,1,-0.5);
    glEnd();
    //inferior
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(-0.5,0,-0.5);
        glVertex3f(0.5,0,-0.5);
        glVertex3f(0.5,0,0.5);
    glEnd();
}
void tabuleiro(){
    glPushMatrix();

    int color = 0;
    for(int i=1; i<=8; i++){
      for(int j=1; j<=8; j++){
          if(color%2==0){
              GUI::setColor(0,0,0, 1,true);
              casaTaboleiro();
              glTranslatef(1, 0, 0);
          }
          else{
              GUI::setColor(1,1,1, 1,true);
              casaTaboleiro();
              glTranslatef(1, 0, 0);
          }
          color++;
      }
      glTranslatef(-8, 0, -1);
      color++;
    }

    glPopMatrix();
}

void desenha() {
    GUI::displayInit();

    GUI::setLight(0, 0,2,2, true, false);

    GUI::drawOrigin(0.5);
    //GUI::drawOriginAL(5,0.5);
    GUI::setColor(0.8,0.0,0.0, 1,true);
    //GUI::drawFloor(5,5);

    GUI::setColor(0.0,0.8,0.0, 1,true);

    tabuleiro();
    glTranslatef(0,1,-1);

    glPushMatrix();
    glScalef(0.5,0.5,0.5);
    for(int i=1; i<=8; i++){
        peao(1,1,1);
        glTranslatef(2,0,0);
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,-5);
    glScalef(0.5,0.5,0.5);
    for(int i=1; i<=8; i++){
        peao(0.2,0.2,0.2);
        glTranslatef(2,0,0);
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2,0,1);
    glScalef(0.5,0.5,0.5);
    bispo(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,0,1);
    glScalef(0.5,0.5,0.5);
    bispo(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2,0,-6);
    glScalef(0.5,0.5,0.5);
    bispo(0.2,0.2,0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,0,-6);
    glScalef(0.5,0.5,0.5);
    bispo(0.2,0.2,0.2);
    glPopMatrix();
    GUI::displayEnd();

}

void teclado(unsigned char tecla, int x, int y) {
    GUI::keyInit(tecla,x,y);

    switch (tecla) {
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;
    case 'p':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;
    case 'a':
        posEsfera.x -= 0.1;
        break;
    case 'd':
        posEsfera.x += 0.1;
        break;
    case 's':
        posEsfera.y -= 0.1;
        break;
    case 'w':
        posEsfera.y += 0.1;
        break;
    case 't':
        idTexture ++;
        idTexture = idTexture%7;
        break;
    default:
        break;
    }
}

int main()
{
    cout << "Hello World!" << endl;

    GUI gui = GUI(800,600,desenha,teclado);
}

//inicializando OpenGL
//while(true) {
//    desenha();
//    interacaoUsuario();
//    //if () {
//    //    break;
//    //}
//}



