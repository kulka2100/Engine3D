#pragma once
#include "BitmapHandler.h"
#include <GL/freeglut.h>
#include <iostream>
#include <glm.hpp>
#include <vec4.hpp>
#include "ShapeObject.h"

/**
 * @brief Klasa reprezentuj�ca tr�jk�t w przestrzeni 2D
 *
 * Klasa `Triangle` dziedziczy po klasie `ShapeObject` i implementuje
 * metody do zarz�dzania parametrami tr�jk�ta oraz jego rysowania
 */
class Triangle : public ShapeObject {
private:
    float x1, x2, y1, y2, x3, y3; ///< Wsp�rz�dne wierzcho�k�w tr�jk�ta
    float r, g, b; ///< Sk�adowe koloru tr�jk�ta

public:
    /**
     * @brief Konstruktor inicjuj�cy tr�jk�t z podanymi wsp�rz�dnymi
     *
     * @param x1 Wsp�rz�dna x pierwszego wierzcho�ka
     * @param y1 Wsp�rz�dna y pierwszego wierzcho�ka
     * @param x2 Wsp�rz�dna x drugiego wierzcho�ka
     * @param y2 Wsp�rz�dna y drugiego wierzcho�ka
     * @param x3 Wsp�rz�dna x trzeciego wierzcho�ka
     * @param y3 Wsp�rz�dna y trzeciego wierzcho�ka
     */
    Triangle(float x1, float y1, float x2, float y2, float x3, float y3) : x1(x1), y1(y1), x2(x2), y2(y2), y3(y3), x3(x3){

    }

    /**
     * @brief Zwraca wsp�rz�dn� x pierwszego wierzcho�ka
     *
     * @return Wsp�rz�dna x pierwszego wierzcho�ka
     */
    float getX1() {
        return x1;
    }

    /**
     * @brief Zwraca wsp�rz�dn� x drugiego wierzcho�ka
     *
     * @return Wsp�rz�dna x drugiego wierzcho�ka
     */
    float getX2() {
        return x2;
    }

    /**
     * @brief Zwraca wsp�rz�dn� y pierwszego wierzcho�ka
     *
     * @return Wsp�rz�dna y pierwszego wierzcho�ka
     */
    float getY1() {
        return y1;
    }

    /**
     * @brief Zwraca wsp�rz�dn� y drugiego wierzcho�ka
     *
     * @return Wsp�rz�dna y drugiego wierzcho�ka
     */
    float getY2() {
        return y2;
    }

    /**
     * @brief Zwraca wsp�rz�dn� x trzeciego wierzcho�ka
     *
     * @return Wsp�rz�dna x trzeciego wierzcho�ka
     */
    float getX3() {
        return x3;
    }

    /**
     * @brief Zwraca wsp�rz�dn� y trzeciego wierzcho�ka
     *
     * @return Wsp�rz�dna y trzeciego wierzcho�ka
     */
    float getY3() {
        return y3;
    }

    /**
     * @brief Metoda odpowiedzialna za rysowanie tr�jk�ta
     *
     * Metoda przes�aniaj�ca metod� z klasy bazowej `ShapeObject`
     */
    void draw() override;

    /**
     * @brief Ustawia kolor tr�jk�ta
     *
     * @param r Sk�adowa czerwona koloru (0.0 - 1.0)
     * @param g Sk�adowa zielona koloru (0.0 - 1.0)
     * @param b Sk�adowa niebieska koloru (0.0 - 1.0)
     */
    void setColor(float r, float g, float b);
};

