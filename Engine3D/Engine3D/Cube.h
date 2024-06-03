#pragma once
#include <GL/freeglut.h>
#include <vector>
#include <ext/matrix_transform.hpp> 
#include "ShapeObject.h"

class Cube : public ShapeObject {
private:
    float size; // Rozmiar szeœcianu
    glm::mat4 modelMatrix;
    

    std::vector<float> vertices; // Tablica wierzcho³ków
    std::vector<float> normals;  // Tablica normalnych
    std::vector<float> colors;   // Tablica kolorów

    GLubyte indices[24] = { 0, 1, 2, 3, // Front
                            4, 5, 6, 7, // Back
                            0, 3, 7, 4, // Left
                            1, 2, 6, 5, // Right
                            0, 1, 5, 4, // Top
                            2, 3, 7, 6  // Bottom
    };

    // Metoda inicjalizuj¹ca tablicê wierzcho³ków
    void initVertices();

public:
    // Konstruktor
    Cube(float size) : size(size), modelMatrix(glm::mat4(1.0)) {
        // Inicjalizacja tablic wierzcho³ków
        initVertices();
    }

    // Metoda rysuj¹ca szeœcian
    void draw() override;

    //Metoda ustawiajaca kolor wierzcholka szescianu
    void setColor(int index, float r, float g, float b);

    //Metoda ustawiajaca kolor calego szescianu
    void setFullColor(float r, float g, float b);



};