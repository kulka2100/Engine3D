#include "Sphere.h"


void Sphere::generateVertices() {
    // Obliczanie kroku dla pier�cieni (R) i sektor�w (S)
    float const R = 1.0f / (float)(rings - 1);
    float const S = 1.0f / (float)(sectors - 1);
    int r, s;

    vertices.resize(rings * sectors * 3);
    std::vector<GLfloat>::iterator v = vertices.begin();

    // P�tla generuj�ca wierzcho�ki
    for (r = 0; r < rings; r++) {
        for (s = 0; s < sectors; s++) {
            // Obliczanie wsp�rz�dnych sferycznych
            float const y = sin(-M_PI_2 + M_PI * r * R);
            float const x = cos(2 * M_PI * s * S) * sin(M_PI * r * R);
            float const z = sin(2 * M_PI * s * S) * sin(M_PI * r * R);


            // Skalowanie wsp�rz�dnych przez promie�
            *v++ = x * radius;  // Wsp�rz�dna x
            *v++ = y * radius;  // Wsp�rz�dna y
            *v++ = z * radius;  // Wsp�rz�dna z
        }
    }

    indices.resize(rings * sectors * 4);
    std::vector<GLuint>::iterator i = indices.begin();
    for (r = 0; r < rings - 1; r++) {
        for (s = 0; s < sectors - 1; s++) {
            // Ustalenie indeks�w wierzcho�k�w tworz�cych czworok�t
            *i++ = r * sectors + s;                  // Lewy g�rny wierzcho�ek
            *i++ = r * sectors + (s + 1);            // Prawy g�rny wierzcho�ek
            *i++ = (r + 1) * sectors + (s + 1);      // Prawy dolny wierzcho�ek
            *i++ = (r + 1) * sectors + s;            // Lewy dolny wierzcho�ek
        }
    }
}



void Sphere::draw() {
    glPushMatrix();

    glMultMatrixf(&modelMatrix[0][0]);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
    glColorPointer(3, GL_FLOAT, 0, &colors[0]);

    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, &indices[0]);

    glPopMatrix();

}


void Sphere::setColor(float red, float green, float blue) {
    colors.clear();
    for (int i = 0; i < vertices.size() / 3; ++i) {
        colors.push_back(red);
        colors.push_back(green);
        colors.push_back(blue);
    }
}

void Sphere::scale(float sx, float sy, float sz) {
    modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));
}

void Sphere::rotate(float angle, float rx, float ry, float rz) {
    modelMatrix = glm::rotate(modelMatrix, glm::radians(angle), glm::vec3(rx, ry, rz));
}


void Sphere::translate(float tx, float ty, float tz) {
    modelMatrix = glm::translate(modelMatrix, glm::vec3(tx, ty, tz));
}