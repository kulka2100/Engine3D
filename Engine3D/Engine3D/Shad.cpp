#include "Shad.h"


void Shad::init() {
    glEnable(GL_DEPTH_TEST); // W³¹cz z-buffer
    glEnable(GL_LIGHTING);   // W³¹cz oœwietlenie

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, glm::value_ptr(lightAmbient));

    //Wlaczanie skladowych oswietlenia ambient, diffuse, specular
    glLightfv(GL_LIGHT0, GL_DIFFUSE, glm::value_ptr(lightDiffuse));
    glLightfv(GL_LIGHT0, GL_POSITION, glm::value_ptr(lightPos));
    glLightfv(GL_LIGHT0, GL_SPECULAR, glm::value_ptr(lightSpecular));

    glEnable(GL_LIGHT0);     // W³¹cz pierwsze Ÿród³o œwiat³a


    if (traceColor == true) {
        glEnable(GL_COLOR_MATERIAL); // W³¹cz GL_COLOR_MATERIAL
        glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE); // ŒledŸ ambient i diffuse
    }
    else {
       //Wlaczanie skladowych materialu ambient, diffuse, specular
        glMaterialfv(GL_FRONT, GL_DIFFUSE, glm::value_ptr(matDiffuse));
        glMaterialfv(GL_FRONT, GL_AMBIENT, glm::value_ptr(matAmbient));
        glMaterialfv(GL_FRONT, GL_SPECULAR, glm::value_ptr(matSpecular));
        glMateriali(GL_FRONT, GL_SHININESS, shininess);
    }

}

void Shad::setLightPos(glm::vec4 pos) {
    lightPos = pos;
}


void Shad::setLightAmbient(glm::vec4 ambientLight) {
    lightAmbient = ambientLight;
}


void Shad::setLightDiffuse(glm::vec4 diffuse) {
    lightDiffuse = diffuse;
}


void Shad::setLightSpecular(glm::vec4 specular) {
    lightSpecular = specular;
}


void Shad::setMatDiffuse(glm::vec4 matDiffuse) {
    this->matDiffuse = matDiffuse;
}

void Shad::setTraceColor(bool trace) {
    this->traceColor = trace;
}

void Shad::setMatAmbient(glm::vec4 matAmbient) {
    this->matAmbient = matAmbient;
}

void Shad::setMatSpecular(glm::vec4 specular) {
    matSpecular = specular;
}

void Shad::setMatShininess(int shinines){
    this->shininess = shinines;
}

