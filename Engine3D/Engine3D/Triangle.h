#pragma once
#include "BitmapHandler.h"
#include <GL/freeglut.h>
#include <iostream>
#include <glm.hpp>
#include <vec4.hpp>
#include "ShapeObject.h"

/**
 * @brief Klasa reprezentuj¹ca trójk¹t w przestrzeni 2D
 *
 * Klasa `Triangle` dziedziczy po klasie `ShapeObject` i implementuje
 * metody do zarz¹dzania parametrami trójk¹ta oraz jego rysowania
 */
class Triangle : public ShapeObject {
private:
    float x1, x2, y1, y2, x3, y3; ///< Wspó³rzêdne wierzcho³ków trójk¹ta
    float r, g, b; ///< Sk³adowe koloru trójk¹ta

public:
    /**
     * @brief Konstruktor inicjuj¹cy trójk¹t z podanymi wspó³rzêdnymi
     *
     * @param x1 Wspó³rzêdna x pierwszego wierzcho³ka
     * @param y1 Wspó³rzêdna y pierwszego wierzcho³ka
     * @param x2 Wspó³rzêdna x drugiego wierzcho³ka
     * @param y2 Wspó³rzêdna y drugiego wierzcho³ka
     * @param x3 Wspó³rzêdna x trzeciego wierzcho³ka
     * @param y3 Wspó³rzêdna y trzeciego wierzcho³ka
     */
    Triangle(float x1, float y1, float x2, float y2, float x3, float y3) : x1(x1), y1(y1), x2(x2), y2(y2), y3(y3), x3(x3){

    }

    /**
     * @brief Zwraca wspó³rzêdn¹ x pierwszego wierzcho³ka
     *
     * @return Wspó³rzêdna x pierwszego wierzcho³ka
     */
    float getX1() {
        return x1;
    }

    /**
     * @brief Zwraca wspó³rzêdn¹ x drugiego wierzcho³ka
     *
     * @return Wspó³rzêdna x drugiego wierzcho³ka
     */
    float getX2() {
        return x2;
    }

    /**
     * @brief Zwraca wspó³rzêdn¹ y pierwszego wierzcho³ka
     *
     * @return Wspó³rzêdna y pierwszego wierzcho³ka
     */
    float getY1() {
        return y1;
    }

    /**
     * @brief Zwraca wspó³rzêdn¹ y drugiego wierzcho³ka
     *
     * @return Wspó³rzêdna y drugiego wierzcho³ka
     */
    float getY2() {
        return y2;
    }

    /**
     * @brief Zwraca wspó³rzêdn¹ x trzeciego wierzcho³ka
     *
     * @return Wspó³rzêdna x trzeciego wierzcho³ka
     */
    float getX3() {
        return x3;
    }

    /**
     * @brief Zwraca wspó³rzêdn¹ y trzeciego wierzcho³ka
     *
     * @return Wspó³rzêdna y trzeciego wierzcho³ka
     */
    float getY3() {
        return y3;
    }

    /**
     * @brief Metoda odpowiedzialna za rysowanie trójk¹ta
     *
     * Metoda przes³aniaj¹ca metodê z klasy bazowej `ShapeObject`
     */
    void draw() override;

    /**
     * @brief Ustawia kolor trójk¹ta
     *
     * @param r Sk³adowa czerwona koloru (0.0 - 1.0)
     * @param g Sk³adowa zielona koloru (0.0 - 1.0)
     * @param b Sk³adowa niebieska koloru (0.0 - 1.0)
     */
    void setColor(float r, float g, float b);
};

