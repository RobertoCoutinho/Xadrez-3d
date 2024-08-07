#include <iostream>

using namespace std;

#include <gui.h>
#include <Desenha.h>
#include <GL/glut.h>


Vetor3D posEsfera = Vetor3D(2,1,0);
float raioEsfera = 0.2;

int idTexture = 0;

void peao(float colorR, float colorG, float colorB){

    glPushMatrix();

    glTranslatef(0,-0.35, 0);
    GUI::habilitaTextura(true,false,0);
    GUI::selecionaTextura(0);
    GUI::setColor(colorR,colorG,colorB,true);

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
    GUI::selecionaTextura(0);
    GUI::setColor(colorR,colorG,colorB,true);

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

void cabecaTorre(){
    //frontal
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,0.2,0.5);
        glVertex3f(-0.5,0.2,0.5);
    glEnd();
    //traseira
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glVertex3f(-0.5,0,-0.5);
        glVertex3f(-0.5,0.2,-0.5);
        glVertex3f(0.5,0.2,-0.5);
        glVertex3f(0.5,0,-0.5);
    glEnd();
    //esquerda
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(-0.5,0.2,0.5);
        glVertex3f(-0.5,0.2,-0.5);
        glVertex3f(-0.5,0,-0.5);
    glEnd();
    //direita
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,0,-0.5);
        glVertex3f(0.5,0.2,-0.5);
        glVertex3f(0.5,0.2,0.5);
    glEnd();
    //superior
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glVertex3f(-0.5,0.2,0.5);
        glVertex3f(0.5,0.2,0.5);
        glVertex3f(0.5,0.2,-0.5);
        glVertex3f(-0.5,0.2,-0.5);
    glEnd();
    //inferior
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(-0.5,0,-0.5);
        glVertex3f(0.5,0,-0.5);
        glVertex3f(0.5,0,0.5);
    glEnd();

    //batente frente frente
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(-0.3,0.2,0.5);
        glVertex3f(0.3,0.2,0.5);
        glVertex3f(0.3,0.4,0.5);
        glVertex3f(-0.3,0.4,0.5);
    glEnd();
    //batente frente esquerda
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glVertex3f(-0.3,0.2,0.5);
        glVertex3f(-0.3,0.4,0.5);
        glVertex3f(-0.3,0.4,0.35);
        glVertex3f(-0.3,0.2,0.35);
    glEnd();
    //batente frente direita
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glVertex3f(0.3,0.2,0.5);
        glVertex3f(0.3,0.2,0.35);
        glVertex3f(0.3,0.4,0.35);
        glVertex3f(0.3,0.4,0.5);
    glEnd();
    //batente frente traseira
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glVertex3f(-0.3,0.2,0.35);
        glVertex3f(-0.3,0.4,0.35);
        glVertex3f(0.3,0.4,0.35);
        glVertex3f(0.3,0.2,0.35);
    glEnd();
    //batente frente superior
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glVertex3f(-0.3,0.4,0.5);
        glVertex3f(0.3,0.4,0.5);
        glVertex3f(0.3,0.4,0.35);
        glVertex3f(-0.3,0.4,0.35);
    glEnd();

    //batente traz frente
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glVertex3f(-0.3,0.2,-0.5);
        glVertex3f(-0.3,0.4,-0.5);
        glVertex3f(0.3,0.4,-0.5);
        glVertex3f(0.3,0.2,-0.5);
    glEnd();
    //batente traz esquerda
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glVertex3f(-0.3,0.2,-0.5);
        glVertex3f(-0.3,0.2,-0.35);
        glVertex3f(-0.3,0.4,-0.35);
        glVertex3f(-0.3,0.4,-0.5);
    glEnd();
    //batente frente direita
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glVertex3f(0.3,0.2,-0.5);
        glVertex3f(0.3,0.4,-0.5);
        glVertex3f(0.3,0.4,-0.35);
        glVertex3f(0.3,0.2,-0.35);
    glEnd();
    //batente traz traseira
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(-0.3,0.2,-0.35);
        glVertex3f(0.3,0.2,-0.35);
        glVertex3f(0.3,0.4,-0.35);
        glVertex3f(-0.3,0.4,-0.35);
    glEnd();
    //batente traz superior
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glVertex3f(-0.3,0.4,-0.5);
        glVertex3f(-0.3,0.4,-0.35);
        glVertex3f(0.3,0.4,-0.35);
        glVertex3f(0.3,0.4,-0.5);
    glEnd();

    //batente esquerda frente
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glVertex3f(-0.5,0.2,0.3);
        glVertex3f(-0.5,0.4,0.3);
        glVertex3f(-0.5,0.4,-0.3);
        glVertex3f(-0.5,0.2,-0.3);
    glEnd();
    //batente esquerda traz
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glVertex3f(-0.35,0.2,0.3);
        glVertex3f(-0.35,0.2,-0.3);
        glVertex3f(-0.35,0.4,-0.3);
        glVertex3f(-0.35,0.4,0.3);
    glEnd();
    //batente esquerda direita
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(-0.35,0.2,0.3);
        glVertex3f(-0.35,0.4,0.3);
        glVertex3f(-0.5,0.4,0.3);
        glVertex3f(-0.5,0.2,0.3);
    glEnd();
    //batente esquerda esquerda
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glVertex3f(-0.35,0.2,-0.3);
        glVertex3f(-0.5,0.2,-0.3);
        glVertex3f(-0.5,0.4,-0.3);
        glVertex3f(-0.35,0.4,-0.3);
    glEnd();
    //batente frente superior
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glVertex3f(-0.5,0.4,0.3);
        glVertex3f(-0.35,0.4,0.3);
        glVertex3f(-0.35,0.4,-0.3);
        glVertex3f(-0.5,0.4,-0.3);
    glEnd();

    //batente direita frente
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glVertex3f(0.5,0.2,0.3);
        glVertex3f(0.5,0.2,-0.3);
        glVertex3f(0.5,0.4,-0.3);
        glVertex3f(0.5,0.4,0.3);
    glEnd();
    //batente direita traz
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glVertex3f(0.35,0.2,0.3);
        glVertex3f(0.35,0.4,0.3);
        glVertex3f(0.35,0.4,-0.3);
        glVertex3f(0.35,0.2,-0.3);
    glEnd();
    //batente direita direita
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glVertex3f(0.35,0.2,-0.3);
        glVertex3f(0.35,0.4,-0.3);
        glVertex3f(0.5,0.4,-0.3);
        glVertex3f(0.5,0.2,-0.3);
    glEnd();
    //batente direita esquerda
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(0.5,0.2,0.3);
        glVertex3f(0.5,0.4,0.3);
        glVertex3f(0.35,0.4,0.3);
        glVertex3f(0.35,0.2,0.3);
    glEnd();
    //batente frente superior
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glVertex3f(0.5,0.4,0.3);
        glVertex3f(0.5,0.4,-0.3);
        glVertex3f(0.35,0.4,-0.3);
        glVertex3f(0.35,0.4,0.3);
    glEnd();
}

void torre(float colorR, float colorG, float ColorB){

    glPushMatrix();
    GUI::habilitaTextura(true,false,0);
    GUI::selecionaTextura(0);
    GUI::setColor(colorR,colorG,ColorB,true);
    glTranslatef(0,1.45,0);
    cabecaTorre();
    glTranslatef(0,-1.45,0);

    glTranslatef(0,-0.35, 0);

    glRotatef(90, 1, 0, 0);
    glTranslatef(0, 0, -1.8);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.47, 0.47, 0.15, 100, 60);

    glTranslatef(0, 0, 0.15);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.4, 0.4, 1, 60, 100);

    glTranslatef(0, 0, 1);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.57, 0.57, 0.15, 100, 60);

    glTranslatef(0, 0, 0.13);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.65, 0.65, 0.15, 100, 60);

    GUI::desabilitaTextura(true,false);

    glPopMatrix();

}

void rainha(float colorR, float colorG, float ColorB){
    GUI::habilitaTextura(true,false,0);
    GUI::selecionaTextura(0);
    GUI::setColor(colorR,colorG,ColorB,true);

    glPushMatrix();

    glRotatef(-90, 1, 0, 0);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.65, 0.65, 0.15, 100, 60);

    glTranslatef(0, 0, 0.15);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.57, 0.57, 0.15, 100, 60);

    glTranslatef(0, 0, 0.15);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.46, 0.23, 1.15, 60, 100);

    glTranslatef(0, 0, 1.1);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.33, 0.33, 0.15, 100, 60);

    glTranslatef(0, 0, 0.15);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.23, 0.38, 0.35, 60, 100);

    glTranslatef(0, 0, 0.35);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.32, 0.06, 0.20, 60, 100);
    GUI::desabilitaTextura(true,false);
    glPopMatrix();

    GUI::drawSphere(0, 2.15, 0, 0.1);
}

void cruzRei(){
    //vertical frente
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(-0.05,0,0.05);
        glVertex3f(0.05,0,0.05);
        glVertex3f(0.05,0.4,0.05);
        glVertex3f(-0.05,0.4,0.05);
    glEnd();
    //vertical traz
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glVertex3f(-0.05,0,-0.05);
        glVertex3f(-0.05,0.4,-0.05);
        glVertex3f(0.05,0.4,-0.05);
        glVertex3f(0.05,0,-0.05);
    glEnd();
    //vertical esquerda
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glVertex3f(-0.05,0,0.05);
        glVertex3f(-0.05,0.4,0.05);
        glVertex3f(-0.05,0.4,-0.05);
        glVertex3f(-0.05,0,-0.05);
    glEnd();
    //vertical direita
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glVertex3f(0.05,0,0.05);
        glVertex3f(0.05,0,-0.05);
        glVertex3f(0.05,0.4,-0.05);
        glVertex3f(0.05,0.4,0.05);
    glEnd();
    //vertical superior
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glVertex3f(-0.05,0.4,0.05);
        glVertex3f(0.05,0.4,0.05);
        glVertex3f(0.05,0.4,-0.05);
        glVertex3f(-0.05,0.4,-0.05);
    glEnd();
    //horizontal frente
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(-0.15,0.2,0.05);
        glVertex3f(0.15,0.2,0.05);
        glVertex3f(0.15,0.3,0.05);
        glVertex3f(-0.15,0.3,0.05);
    glEnd();
    //horizontal traz
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glVertex3f(-0.15,0.2,-0.05);
        glVertex3f(-0.15,0.3,-0.05);
        glVertex3f(0.15,0.3,-0.05);
        glVertex3f(0.15,0.2,-0.05);
    glEnd();
    //horizontal superior
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glVertex3f(-0.15,0.3,0.05);
        glVertex3f(0.15,0.3,0.05);
        glVertex3f(0.15,0.3,-0.05);
        glVertex3f(-0.15,0.3,-0.05);
    glEnd();
    //horizontal inferior
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glVertex3f(-0.15,0.2,0.05);
        glVertex3f(-0.15,0.2,-0.05);
        glVertex3f(0.15,0.2,-0.05);
        glVertex3f(0.15,0.2,0.05);
    glEnd();
    //horizontal direita
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glVertex3f(0.15,0.2,0.05);
        glVertex3f(0.15,0.2,-0.05);
        glVertex3f(0.15,0.3,-0.05);
        glVertex3f(0.15,0.3,0.05);
    glEnd();
    //horizontal esquerda
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glVertex3f(-0.15,0.2,0.05);
        glVertex3f(-0.15,0.3,0.05);
        glVertex3f(-0.15,0.3,-0.05);
        glVertex3f(-0.15,0.2,-0.05);
    glEnd();
}

void rei(float colorR, float colorG, float ColorB){
    GUI::habilitaTextura(true,false,0);
    GUI::selecionaTextura(0);
    GUI::setColor(colorR,colorG,ColorB,true);

    glPushMatrix();

    glRotatef(-90, 1, 0, 0);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.65, 0.65, 0.15, 100, 60);

    glTranslatef(0, 0, 0.15);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.57, 0.57, 0.15, 100, 60);

    glTranslatef(0, 0, 0.15);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.46, 0.23, 1.15, 60, 100);

    glTranslatef(0, 0, 1.1);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.33, 0.33, 0.15, 100, 60);

    glTranslatef(0, 0, 0.15);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.23, 0.38, 0.35, 60, 100);

    glTranslatef(0, 0, 0.35);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.32, 0.06, 0.20, 60, 100);
    glPopMatrix();

    glTranslatef(0, 2, 0);
    cruzRei();
    GUI::desabilitaTextura(true,false);

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

void bordaTabuleiro(){
    //frontal
    GUI::habilitaTextura(true,false,0);
    GUI::selecionaTextura(1);
    GUI::setColor(0.92,0.78,0.62,1);

    // fernte - frente
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glTexCoord2d(0,0);
        glVertex3f(-0.9,0,0.9);
        glTexCoord2d(1,0);
        glVertex3f(7.9,0,0.9);
        glTexCoord2d(1,1);
        glVertex3f(7.9,1.05,0.9);
        glTexCoord2d(0,1);
        glVertex3f(-0.9,1.05,0.9);
    glEnd();


    // fernte - trazeira
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glTexCoord2d(0,0);
        glVertex3f(-0.9,0,0.5);
        glTexCoord2d(1,0);
        glVertex3f(-0.9,1.05,0.5);
        glTexCoord2d(1,1);
        glVertex3f(7.9,1.05,0.5);
        glTexCoord2d(0,1);
        glVertex3f(7.9,0,0.5);
    glEnd();

    // fernte - topo
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glTexCoord2d(0,0);
        glVertex3f(-0.9,1.05,0.9);
        glTexCoord2d(1,0);
        glVertex3f(7.9,1.05,0.9);
        glTexCoord2d(1,1);
        glVertex3f(7.9,1.05,0.5);
        glTexCoord2d(0,1);
        glVertex3f(-0.9,1.05,0.5);
    glEnd();

    // fernte - inferior
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glTexCoord2d(0,0);
        glVertex3f(-0.9,0,0.9);
        glTexCoord2d(1,0);
        glVertex3f(-0.9,0,0.5);
        glTexCoord2d(1,1);
        glVertex3f(7.9,0,0.5);
        glTexCoord2d(0,1);
        glVertex3f(7.9,0,0.9);
    glEnd();

    // direita - frente
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glTexCoord2d(0,0);
        glVertex3f(7.9,0,0.9);
        glTexCoord2d(1,0);
        glVertex3f(7.9,0,-7.9);
        glTexCoord2d(1,1);
        glVertex3f(7.9,1.05,-7.9);
        glTexCoord2d(0,1);
        glVertex3f(7.9,1.05,0.9);
    glEnd();
    // direita - trazeira
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glTexCoord2d(0,0);
        glVertex3f(7.5,0,0.9);
        glTexCoord2d(1,0);
        glVertex3f(7.5,1.05,0.9);
        glTexCoord2d(1,1);
        glVertex3f(7.5,1.05,-7.9);
        glTexCoord2d(0,1);
        glVertex3f(7.5,0,-7.9);
    glEnd();
    // direita - topo
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glTexCoord2d(0,0);
        glVertex3f(7.5,1.05,0.9);
        glTexCoord2d(1,0);
        glVertex3f(7.9,1.05,0.9);
        glTexCoord2d(1,1);
        glVertex3f(7.9,1.05,-7.9);
        glTexCoord2d(0,1);
        glVertex3f(7.5,1.05,-7.9);
    glEnd();
    // direita - inferior
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glTexCoord2d(0,0);
        glVertex3f(7.5,0,0.9);
        glTexCoord2d(1,0);
        glVertex3f(7.5,0,-7.9);
        glTexCoord2d(1,1);
        glVertex3f(7.9,0,-7.9);
        glTexCoord2d(0,1);
        glVertex3f(7.9,0,0.9);
    glEnd();

    // esquerda - frente
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glTexCoord2d(0,0);
        glVertex3f(-0.9,0,0.9);
        glTexCoord2d(1,0);
        glVertex3f(-0.9,1.05,0.9);
        glTexCoord2d(1,1);
        glVertex3f(-0.9,1.05,-7.9);
        glTexCoord2d(0,1);
        glVertex3f(-0.9,0,-7.9);
    glEnd();
    // esquerda - trazeira
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glTexCoord2d(0,0);
        glVertex3f(-0.5,0,0.9);
        glTexCoord2d(1,0);
        glVertex3f(-0.5,0,-7.9);
        glTexCoord2d(1,1);
        glVertex3f(-0.5,1.05,-7.9);
        glTexCoord2d(0,1);
        glVertex3f(-0.5,1.05,0.9);
    glEnd();
    // esquerda - topo
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glTexCoord2d(0,0);
        glVertex3f(-0.5,1.05,0.9);
        glTexCoord2d(1,0);
        glVertex3f(-0.5,1.05,-7.9);
        glTexCoord2d(1,1);
        glVertex3f(-0.9,1.05,-7.9);
        glTexCoord2d(0,1);
        glVertex3f(-0.9,1.05,0.9);
    glEnd();
    // esquerda - inferior
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glTexCoord2d(0,0);
        glVertex3f(-0.5,0,0.9);
        glTexCoord2d(1,0);
        glVertex3f(-0.9,0,0.9);
        glTexCoord2d(1,1);
        glVertex3f(-0.9,0,-7.9);
        glTexCoord2d(0,1);
        glVertex3f(-0.5,0,-7.9);
    glEnd();

    // trazeira - trazeira
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glTexCoord2d(0,0);
        glVertex3f(7.9,0,-7.9);
        glTexCoord2d(1,0);
        glVertex3f(-0.9,0,-7.9);
        glTexCoord2d(1,1);
        glVertex3f(-0.9,1.05,-7.9);
        glTexCoord2d(0,1);
        glVertex3f(7.9,1.05,-7.9);
    glEnd();
    // trazeira - frente
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glTexCoord2d(0,0);
        glVertex3f(7.9,0,-7.5);
        glTexCoord2d(1,0);
        glVertex3f(7.9,1.05,-7.5);
        glTexCoord2d(1,1);
        glVertex3f(-0.9,1.05,-7.5);
        glTexCoord2d(0,1);
        glVertex3f(-0.9,0,-7.5);
    glEnd();
    // trazeira - topo
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glTexCoord2d(0,0);
        glVertex3f(-0.9,1.05,-7.9);
        glTexCoord2d(1,0);
        glVertex3f(-0.9,1.05,-7.5);
        glTexCoord2d(1,1);
        glVertex3f(7.9,1.05,-7.5);
        glTexCoord2d(0,1);
        glVertex3f(7.9,1.05,-7.9);
    glEnd();
    // trazeira - inferior
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glTexCoord2d(0,0);
        glVertex3f(-0.9,0,-7.9);
        glTexCoord2d(1,0);
        glVertex3f(7.9,0,-7.9);
        glTexCoord2d(1,1);
        glVertex3f(7.9,0,-7.5);
        glTexCoord2d(0,1);
        glVertex3f(-0.9,0,-7.5);
    glEnd();
    GUI::desabilitaTextura(true,false);
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

    GUI::setLight(0, 4,5,-3, true, false);

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
        peao(0.1,0.1,0.1);
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
    bispo(0.1,0.1,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,0,-6);
    glScalef(0.5,0.5,0.5);
    bispo(0.1,0.1,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,1);
    glScalef(0.5,0.5,0.5);
    torre(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7,0,1);
    glScalef(0.5,0.5,0.5);
    torre(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,-6);
    glScalef(0.5,0.5,0.5);
    torre(0.1,0.1,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7,0,-6);
    glScalef(0.5,0.5,0.5);
    torre(0.1,0.1,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4,0,1);
    glScalef(0.5,0.63,0.5);
    rainha(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4,0,-6);
    glScalef(0.5,0.63,0.5);
    rainha(0.1,0.1,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3,0,1);
    glScalef(0.5,0.63,0.5);
    rei(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3,0,-6);
    glScalef(0.5,0.63,0.5);
    rei(0.1,0.1,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-1,1);
    bordaTabuleiro();
    glPopMatrix();
    GUI::displayEnd();
}
Model3DS carro = Model3DS("../3ds/cartest2.3DS");
Model3DS cavalo = Model3DS("../3ds/cavalo.3ds");
void desenhaTeste() {
    GUI::displayInit();

    GUI::setLight(0, 4,2.5,-3, true, false);

    GUI::drawOrigin(0.5);
    //GUI::drawOriginAL(5,0.5);
    GUI::setColor(0.8,0.0,0.0, 1,true);
    GUI::drawFloor(5,5);

    GUI::setColor(0.0,0.8,0.0, 1,true);

    GUI::draw3ds(carro);
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



