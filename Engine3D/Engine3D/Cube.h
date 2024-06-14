#pragma once
#include "BitmapHandler.h"
#include <GL/freeglut.h>
#include <vector>
#include <ext/matrix_transform.hpp> 
#include "ShapeObject.h"

/**
 * @brief Klasa reprezentuj�ca sze�cian 3D
 *
 * Klasa `Cube` dziedziczy po `ShapeObject` i reprezentuje sze�cian, kt�ry mo�na rysowa� w przestrzeni 3D
 */
class Cube : public ShapeObject {
private:
    float size; ///< Rozmiar sze�cianu
    std::vector<float> vertices; ///< Tablica wierzcho�k�w 
    std::vector<float> normals;  ///< Tablica normalnych 
    std::vector<float> colors;   ///< Tablica kolor�w 

    GLubyte indices[24] = { 0, 1, 2, 3, // Front
                            4, 5, 6, 7, // Back
                            0, 3, 7, 4, // Left
                            1, 2, 6, 5, // Right
                            0, 1, 5, 4, // Top
                            2, 3, 7, 6  // Bottom
    }; ///< Indeksy definiuj�ce wierzcho�ki sze�cianu

    /**
     * @brief Inicjalizuje tablic� wierzcho�k�w
     *
     * Metoda ustawiaj�ca wsp�rz�dne wierzcho�k�w sze�cianu
     */
    void initVertices();

public:
    /**
     * @brief Konstruktor inicjalizuj�cy
     *
     * Tworzy nowy sze�cian o podanym rozmiarze
     *
     * @param[in] size Rozmiar sze�cianu
     */
    Cube(float size) : size(size) {
        // Inicjalizacja tablic wierzcho�k�w
        initVertices();
    }

    /**
     * @brief Rysuje sze�cian
     *
     * Implementacja metody `draw` z klasy `ShapeObject`, kt�ra rysuje sze�cian w przestrzeni 3D
     */
    void draw() override;

    /**
     * @brief Ustawia kolor wierzcho�ka sze�cianu
     *
     * Ustawia kolor dla konkretnego wierzcho�ka sze�cianu
     *
     * @param[in] index Indeks wierzcho�ka (0-7)
     * @param[in] r Sk�adowa koloru czerwonego (0.0 - 1.0)
     * @param[in] g Sk�adowa koloru zielonego (0.0 - 1.0)
     * @param[in] b Sk�adowa koloru niebieskiego (0.0 - 1.0)
     */
    void setColor(int index, float r, float g, float b);

    /**
     * @brief Ustawia kolor ca�ego sze�cianu
     *
     * Ustawia kolor dla wszystkich wierzcho�k�w sze�cianu
     *
     * @param[in] r Sk�adowa koloru czerwonego (0.0 - 1.0)
     * @param[in] g Sk�adowa koloru zielonego (0.0 - 1.0)
     * @param[in] b Sk�adowa koloru niebieskiego (0.0 - 1.0)
     */
    void setFullColor(float r, float g, float b);

};