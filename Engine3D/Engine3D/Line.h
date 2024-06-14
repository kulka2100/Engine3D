#pragma once
#include "BitmapHandler.h"
#include <GL/freeglut.h>
#include <iostream>
#include <glm.hpp>
#include <vec4.hpp>
#include "ShapeObject.h"

/**
 * @brief Klasa reprezentuj¹ca liniê w przestrzeni 2D
 *
 * Klasa `Line` dziedziczy po klasie `ShapeObject` i definiuje funkcjonalnoœæ
 * obiektu liniowego, który mo¿e byæ rysowany w aplikacji graficznej
 */
class Line : public ShapeObject {
private:
    float x1; ///< Wspó³rzêdna x pocz¹tkowego punktu linii
    float y1; ///< Wspó³rzêdna y pocz¹tkowego punktu linii
    float x2; ///< Wspó³rzêdna x koñcowego punktu linii
    float y2; ///< Wspó³rzêdna y koñcowego punktu linii
    float r, g, b; ///< Sk³adowe koloru linii

public:
    /**
     * @brief Konstruktor inicjuj¹cy liniê
     *
     * Konstruktor inicjuje obiekt liniowy z podanymi wspó³rzêdnymi
     * pocz¹tkowymi i koñcowymi
     *
     * @param x1 Wspó³rzêdna x pocz¹tkowego punktu linii
     * @param y1 Wspó³rzêdna y pocz¹tkowego punktu linii
     * @param x2 Wspó³rzêdna x koñcowego punktu linii
     * @param y2 Wspó³rzêdna y koñcowego punktu linii
     */
    Line(float x1, float y1, float x2, float y2);

    /**
     * @brief Zwraca wspó³rzêdn¹ x pocz¹tkowego punktu linii
     *
     * @return Wspó³rzêdna x pocz¹tkowego punktu linii
     */
    float getX1() {
        return x1;
    }

    /**
     * @brief Zwraca wspó³rzêdn¹ x koñcowego punktu linii
     *
     * @return Wspó³rzêdna x koñcowego punktu linii
     */
    float getX2() {
        return x2;
    }

    /**
     * @brief Zwraca wspó³rzêdn¹ y pocz¹tkowego punktu linii
     *
     * @return Wspó³rzêdna y pocz¹tkowego punktu linii
     */
    float getY1() {
        return y1;
    }

    /**
     * @brief Zwraca wspó³rzêdn¹ y koñcowego punktu linii
     *
     * @return Wspó³rzêdna y koñcowego punktu linii
     */
    float getY2() {
        return y2;
    }

    /**
     * @brief Metoda rysuj¹ca liniê
     *
     * Metoda przedefiniowana z klasy bazowej `ShapeObject`
     * Rysuje liniê na scenie
     */
    void draw() override;

    /**
     * @brief Ustawia kolor linii
     *
     * @param r Sk³adowa czerwona koloru (0.0 - 1.0)
     * @param g Sk³adowa zielona koloru (0.0 - 1.0)
     * @param b Sk³adowa niebieska koloru (0.0 - 1.0)
     */
    void setColor(float r, float g, float b);

};