#include "Shad.h"

void Shad::init() {
    glEnable(GL_DEPTH_TEST); // W³¹cz test g³êbokoœci
    glEnable(GL_LIGHTING);   // W³¹cz oœwietlenie
    glEnable(GL_LIGHT0);     // W³¹cz pierwsze Ÿród³o œwiat³a

    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);
}


void Shad::setLightPos(float x, float y, float z, float w) {
    lightPos[0] = x;
    lightPos[1] = y;
    lightPos[2] = z;
    lightPos[3] = w;
}


void Shad::setLightAmbient(float x, float y, float z, float w) {
    lightAmbient[0] = x;
    lightAmbient[1] = y;
    lightAmbient[2] = z;
    lightAmbient[3] = w;
}


void Shad::setLightDiffuse(float x, float y, float z, float w) {
    lightDiffuse[0] = x;
    lightDiffuse[1] = y;
    lightDiffuse[2] = z;
    lightDiffuse[3] = w;
}


void Shad::setLightSpecular(float x, float y, float z, float w) {
    lightSpecular[0] = x;
    lightSpecular[1] = y;
    lightSpecular[2] = z;
    lightSpecular[3] = w;
}

void Shad::setMatAmbient(float x, float y, float z, float w) {
    matAmbient[0] = x;
    matAmbient[1] = y;
    matAmbient[2] = z;
    matAmbient[3] = w;
}

void Shad::setMatDiffuse(float x, float y, float z, float w) {
    matDiffuse[0] = x;
    matDiffuse[1] = y;
    matDiffuse[2] = z;
    matDiffuse[3] = w;
}

void Shad::setMatSpecular(float x, float y, float z, float w) {
    matSpecular[0] = x;
    matSpecular[1] = y;
    matSpecular[2] = z;
    matSpecular[3] = w;
}

void Shad::setMatShininess(float x) {
    matShininess[0] = x;
}