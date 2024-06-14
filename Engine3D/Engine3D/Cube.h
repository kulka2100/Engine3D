#pragma once
#include "BitmapHandler.h"
#include <GL/freeglut.h>
#include <vector>
#include <ext/matrix_transform.hpp> 
#include "ShapeObject.h"

/**
 * @brief Klasa reprezentuj¹ca szeœcian 3D
 *
 * Klasa `Cube` dziedziczy po `ShapeObject` i reprezentuje szeœcian, który mo¿na rysowaæ w przestrzeni 3D
 */
class Cube : public ShapeObject {
private:
    float size; ///< Rozmiar szeœcianu
    std::vector<float> vertices; ///< Tablica wierzcho³ków 
    std::vector<float> normals;  ///< Tablica normalnych 
    std::vector<float> colors;   ///< Tablica kolorów 

    GLubyte indices[24] = { 0, 1, 2, 3, // Front
                            4, 5, 6, 7, // Back
                            0, 3, 7, 4, // Left
                            1, 2, 6, 5, // Right
                            0, 1, 5, 4, // Top
                            2, 3, 7, 6  // Bottom
    }; ///< Indeksy definiuj¹ce wierzcho³ki szeœcianu

    /**
     * @brief Inicjalizuje tablicê wierzcho³ków
     *
     * Metoda ustawiaj¹ca wspó³rzêdne wierzcho³ków szeœcianu
     */
    void initVertices();

public:
    /**
     * @brief Konstruktor inicjalizuj¹cy
     *
     * Tworzy nowy szeœcian o podanym rozmiarze
     *
     * @param[in] size Rozmiar szeœcianu
     */
    Cube(float size) : size(size) {
        // Inicjalizacja tablic wierzcho³ków
        initVertices();
    }

    /**
     * @brief Rysuje szeœcian
     *
     * Implementacja metody `draw` z klasy `ShapeObject`, która rysuje szeœcian w przestrzeni 3D
     */
    void draw() override;

    /**
     * @brief Ustawia kolor wierzcho³ka szeœcianu
     *
     * Ustawia kolor dla konkretnego wierzcho³ka szeœcianu
     *
     * @param[in] index Indeks wierzcho³ka (0-7)
     * @param[in] r Sk³adowa koloru czerwonego (0.0 - 1.0)
     * @param[in] g Sk³adowa koloru zielonego (0.0 - 1.0)
     * @param[in] b Sk³adowa koloru niebieskiego (0.0 - 1.0)
     */
    void setColor(int index, float r, float g, float b);

    /**
     * @brief Ustawia kolor ca³ego szeœcianu
     *
     * Ustawia kolor dla wszystkich wierzcho³ków szeœcianu
     *
     * @param[in] r Sk³adowa koloru czerwonego (0.0 - 1.0)
     * @param[in] g Sk³adowa koloru zielonego (0.0 - 1.0)
     * @param[in] b Sk³adowa koloru niebieskiego (0.0 - 1.0)
     */
    void setFullColor(float r, float g, float b);

};