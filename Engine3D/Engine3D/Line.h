#pragma once
#include "BitmapHandler.h"
#include <GL/freeglut.h>
#include <iostream>
#include <glm.hpp>
#include <vec4.hpp>
#include "ShapeObject.h"

/**
 * @brief Klasa reprezentuj�ca lini� w przestrzeni 2D
 *
 * Klasa `Line` dziedziczy po klasie `ShapeObject` i definiuje funkcjonalno��
 * obiektu liniowego, kt�ry mo�e by� rysowany w aplikacji graficznej
 */
class Line : public ShapeObject {
private:
    float x1; ///< Wsp�rz�dna x pocz�tkowego punktu linii
    float y1; ///< Wsp�rz�dna y pocz�tkowego punktu linii
    float x2; ///< Wsp�rz�dna x ko�cowego punktu linii
    float y2; ///< Wsp�rz�dna y ko�cowego punktu linii
    float r, g, b; ///< Sk�adowe koloru linii

public:
    /**
     * @brief Konstruktor inicjuj�cy lini�
     *
     * Konstruktor inicjuje obiekt liniowy z podanymi wsp�rz�dnymi
     * pocz�tkowymi i ko�cowymi
     *
     * @param x1 Wsp�rz�dna x pocz�tkowego punktu linii
     * @param y1 Wsp�rz�dna y pocz�tkowego punktu linii
     * @param x2 Wsp�rz�dna x ko�cowego punktu linii
     * @param y2 Wsp�rz�dna y ko�cowego punktu linii
     */
    Line(float x1, float y1, float x2, float y2);

    /**
     * @brief Zwraca wsp�rz�dn� x pocz�tkowego punktu linii
     *
     * @return Wsp�rz�dna x pocz�tkowego punktu linii
     */
    float getX1() {
        return x1;
    }

    /**
     * @brief Zwraca wsp�rz�dn� x ko�cowego punktu linii
     *
     * @return Wsp�rz�dna x ko�cowego punktu linii
     */
    float getX2() {
        return x2;
    }

    /**
     * @brief Zwraca wsp�rz�dn� y pocz�tkowego punktu linii
     *
     * @return Wsp�rz�dna y pocz�tkowego punktu linii
     */
    float getY1() {
        return y1;
    }

    /**
     * @brief Zwraca wsp�rz�dn� y ko�cowego punktu linii
     *
     * @return Wsp�rz�dna y ko�cowego punktu linii
     */
    float getY2() {
        return y2;
    }

    /**
     * @brief Metoda rysuj�ca lini�
     *
     * Metoda przedefiniowana z klasy bazowej `ShapeObject`
     * Rysuje lini� na scenie
     */
    void draw() override;

    /**
     * @brief Ustawia kolor linii
     *
     * @param r Sk�adowa czerwona koloru (0.0 - 1.0)
     * @param g Sk�adowa zielona koloru (0.0 - 1.0)
     * @param b Sk�adowa niebieska koloru (0.0 - 1.0)
     */
    void setColor(float r, float g, float b);

};