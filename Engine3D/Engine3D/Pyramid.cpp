#include "Pyramid.h"


void Pyramid::initVertices() {
    float halfSize = size / 2.0f;

    //Wierzcholki ostroslupa

    vertices = {

        0.0f, size, 0.0f,             //Szczyt ostroslupa
        -halfSize, 0.0f, halfSize,    //Przedni - lewy
        halfSize, 0.0f, halfSize,     //Przedni - prawy
        halfSize, 0.0f, -halfSize,    //Tylni - prawy
        -halfSize, 0.0, -halfSize   //Tylni - lewy
    };



    // Wektory normalne dla �cian
    normals = {
        0.0f, 0.707f, 0.707f,  // Normalna dla przedniej �ciany
        0.707f, 0.707f, 0.0f,  // Normalna dla prawej �ciany
        0.0f, 0.707f, -0.707f, // Normalna dla tylnej �ciany
        -0.707f, 0.707f, 0.0f, // Normalna dla lewej �ciany
        0.0f, -1.0f, 0.0f,     // Normalna dla dolnej �ciany
    };


    colors = {
       0.0f, 0.0f, 0.0f, // Przednia �ciana
       0.0f, 1.0f, 0.0f, // Lewa �ciana
       0.0f, 0.0f, 1.0f, // Prawa �ciana
       0.0f, 0.0f, 1.0f, // Tylna Prawa 
       0.0f, 1.0f, 0.0f  // Tylna Lewa
    };


}




void Pyramid::draw() {
    glPushMatrix();

    glMultMatrixf(&modelMatrix[0][0]);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    // Przekazywanie wska�nik�w do funkcji OpenGL
    glVertexPointer(3, GL_FLOAT, 0, vertices.data());
    glNormalPointer(GL_FLOAT, 0, normals.data());
    glColorPointer(3, GL_FLOAT, 0, colors.data());
    glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_BYTE, indices);

    glPopMatrix();
}

void Pyramid::scale(float sx, float sy, float sz) {
    modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));
}

void Pyramid::rotate(float angle, float rx, float ry, float rz) {
    modelMatrix = glm::rotate(modelMatrix, glm::radians(angle), glm::vec3(rx, ry, rz));
}

void Pyramid::translate(float tx, float ty, float tz) {
    modelMatrix = glm::translate(modelMatrix, glm::vec3(tx, ty, tz));
}