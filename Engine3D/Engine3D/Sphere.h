#pragma once
#include "BitmapHandler.h"
#include <GL/freeglut.h>
#include <vector>
#include <ext/matrix_transform.hpp> 
#include <corecrt_math_defines.h>
#include <glm.hpp>
#include "ShapeObject.h"

/**
 * @brief Klasa reprezentuj¹ca obiekt sfery w przestrzeni 3D
 *
 * Klasa `Sphere` dziedziczy po klasie `ShapeObject` i implementuje
 * metodê rysowania oraz dodatkowe funkcje do zarz¹dzania cechami sfery
 */
class Sphere : public ShapeObject {
private:
    float radius; ///< Promieñ sfery
    unsigned int rings; ///< Liczba pierœcieni
    unsigned int sectors; ///< Liczba sektorów
    glm::vec3 colors = { 0.5, 0.5, 0.0 }; ///< Kolor sfery
    bool solid; ///< Flaga okreœlaj¹ca typ sfery (solidna czy siatkowa)

public:
    /**
     * @brief Konstruktor inicjuj¹cy sferê z podanymi parametrami
     *
     * @param radius Promieñ sfery
     * @param rings Liczba pierœcieni sfery
     * @param sectors Liczba sektorów sfery
     */
    Sphere(float radius, unsigned int rings, unsigned int sectors)
        : radius(radius), rings(rings), sectors(sectors), solid(false) {
    }

    /**
     * @brief Metoda odpowiedzialna za rysowanie sfery
     *
     * Metoda przes³aniaj¹ca metodê z klasy bazowej `ShapeObject`
     */
    void draw() override;

    /**
     * @brief Ustawia typ sfery (solidna lub siatkowa)
     *
     * @param solid Wartoœæ true dla sfery solidnej, false dla sfery siatkowej
     */
    void isSolid(bool solid);

    /**
     * @brief Ustawia kolor sfery
     *
     * @param red Sk³adowa czerwona koloru
     * @param green Sk³adowa zielona koloru
     * @param blue Sk³adowa niebieska koloru
     */
    void setColor(float red, float green, float blue);
    
};

