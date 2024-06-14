#pragma once
#include "BitmapHandler.h"
#include <GL/freeglut.h>
#include <vector>
#include <ext/matrix_transform.hpp> 
#include <corecrt_math_defines.h>
#include <glm.hpp>
#include "ShapeObject.h"

/**
 * @brief Klasa reprezentuj�ca obiekt sfery w przestrzeni 3D
 *
 * Klasa `Sphere` dziedziczy po klasie `ShapeObject` i implementuje
 * metod� rysowania oraz dodatkowe funkcje do zarz�dzania cechami sfery
 */
class Sphere : public ShapeObject {
private:
    float radius; ///< Promie� sfery
    unsigned int rings; ///< Liczba pier�cieni
    unsigned int sectors; ///< Liczba sektor�w
    glm::vec3 colors = { 0.5, 0.5, 0.0 }; ///< Kolor sfery
    bool solid; ///< Flaga okre�laj�ca typ sfery (solidna czy siatkowa)

public:
    /**
     * @brief Konstruktor inicjuj�cy sfer� z podanymi parametrami
     *
     * @param radius Promie� sfery
     * @param rings Liczba pier�cieni sfery
     * @param sectors Liczba sektor�w sfery
     */
    Sphere(float radius, unsigned int rings, unsigned int sectors)
        : radius(radius), rings(rings), sectors(sectors), solid(false) {
    }

    /**
     * @brief Metoda odpowiedzialna za rysowanie sfery
     *
     * Metoda przes�aniaj�ca metod� z klasy bazowej `ShapeObject`
     */
    void draw() override;

    /**
     * @brief Ustawia typ sfery (solidna lub siatkowa)
     *
     * @param solid Warto�� true dla sfery solidnej, false dla sfery siatkowej
     */
    void isSolid(bool solid);

    /**
     * @brief Ustawia kolor sfery
     *
     * @param red Sk�adowa czerwona koloru
     * @param green Sk�adowa zielona koloru
     * @param blue Sk�adowa niebieska koloru
     */
    void setColor(float red, float green, float blue);
    
};

