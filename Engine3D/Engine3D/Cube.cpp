#include "Cube.h"


void Cube::initVertices() {
    float halfSize = size / 2.0f;

    // Wierzcho³ki
    float v[] = {
        // Front
        -halfSize, -halfSize, halfSize,
        halfSize, -halfSize, halfSize,
        halfSize, halfSize, halfSize,
        -halfSize, halfSize, halfSize,
        // Back
        -halfSize, -halfSize, -halfSize,
        halfSize, -halfSize, -halfSize,
        halfSize, halfSize, -halfSize,
        -halfSize, halfSize, -halfSize
    };

    vertices.assign(v, v + 24);

    // Normalne
    float n[] = {
        // Front
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        // Back
        0.0f, 0.0f, -1.0f,
        0.0f, 0.0f, -1.0f,
        0.0f, 0.0f, -1.0f,
        0.0f, 0.0f, -1.0f
    };

    normals.assign(n, n + 24);

    // Kolory
    float c[] = {
        // Front
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        // Back
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f
    };

    colors.assign(c, c + 24);
}

void Cube::draw() {
    glPushMatrix();

    glMultMatrixf(&modelMatrix[0][0]);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    // Rysowanie szeœcianu
    glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
    glNormalPointer(GL_FLOAT, 0, &normals[0]);
    glColorPointer(3, GL_FLOAT, 0, &colors[0]);
    glDrawElements(GL_QUADS, sizeof(indices), GL_UNSIGNED_BYTE, indices);

    glPopMatrix();
}


void Cube::setColor(int index, float r, float g, float b) {
    if (index >= 0 && index <= 7) {
        int start = index * 3; // Indeks pocz¹tkowy koloru w tablicy c[]
        colors[start] = r;
        colors[start + 1] = g;
        colors[start + 2] = b;
    }
}


void Cube::setFullColor(float r, float g, float b) {
    for (int i = 0; i <= 7; i++) {
        int start = i * 3; // Indeks pocz¹tkowy koloru w tablicy c[]
        colors[start] = r;
        colors[start + 1] = g;
        colors[start + 2] = b;
    }
}


void Cube::setPosition(float x, float y, float z) {
    modelMatrix = glm::translate(modelMatrix, glm::vec3(x, y, z));
}

void Cube::scale(float sx, float sy, float sz) {
    modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));
}

void Cube::rotate(float angle, float rx, float ry, float rz) {
    modelMatrix = glm::rotate(modelMatrix, glm::radians(angle), glm::vec3(rx, ry, rz));
}


void Cube::translate(float tx, float ty, float tz) {
    modelMatrix = glm::translate(modelMatrix, glm::vec3(tx, ty, tz));
}