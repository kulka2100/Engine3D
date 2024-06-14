#pragma once
#include "BitmapHandler.h"
#include <GL/freeglut.h>
#include <iostream>
#include <glm.hpp>
#include <vec4.hpp>
#include "ShapeObject.h"

/**
 * @brief Klasa reprezentuj¹ca prostok¹t w przestrzeni 2D
 *
 * Klasa `Rectangl` dziedziczy po klasie `ShapeObject` i definiuje funkcjonalnoœæ
 * obiektu prostok¹tnego, który mo¿e byæ rysowany w aplikacji graficznej
 */
class Rectangl : public ShapeObject {
private:
    float x; ///< Wspó³rzêdna x lewego dolnego rogu prostok¹ta
    float y; ///< Wspó³rzêdna y lewego dolnego rogu prostok¹ta
    float width; ///< Szerokoœæ prostok¹ta
    float height; ///< Wysokoœæ prostok¹ta
    float r, g, b; ///< Sk³adowe koloru prostok¹ta


public:
    /**
     * @brief Konstruktor inicjuj¹cy prostok¹t
     *
     * Konstruktor inicjuje obiekt prostok¹ta z podanymi parametrami
     *
     * @param x Wspó³rzêdna x lewego dolnego rogu prostok¹ta
     * @param y Wspó³rzêdna y lewego dolnego rogu prostok¹ta
     * @param width Szerokoœæ prostok¹ta
     * @param height Wysokoœæ prostok¹ta
     */
    Rectangl(float x, float y, float width, float height);

    /**
     * @brief Zwraca wspó³rzêdn¹ x lewego dolnego rogu prostok¹ta
     *
     * @return Wspó³rzêdna x lewego dolnego rogu prostok¹ta
     */
    float getX() {
        return x;
    }

    /**
     * @brief Zwraca wspó³rzêdn¹ y lewego dolnego rogu prostok¹ta
     *
     * @return Wspó³rzêdna y lewego dolnego rogu prostok¹ta
     */
    float getY() {
        return y;
    }

    /**
     * @brief Zwraca szerokoœæ prostok¹ta
     *
     * @return Szerokoœæ prostok¹ta
     */
    float getWidth() {
        return width;
    }

    /**
     * @brief Zwraca wysokoœæ prostok¹ta
     *
     * @return Wysokoœæ prostok¹ta
     */
    float getHeight() {
        return height;
    }

    /**
     * @brief Metoda rysuj¹ca prostok¹t
     *
     * Metoda przedefiniowana z klasy bazowej `ShapeObject`
     * Rysuje prostok¹t na scenie
     */
    void draw() override;

    /**
     * @brief Ustawia kolor prostok¹ta
     *
     * @param r Sk³adowa czerwona koloru (0.0 - 1.0)
     * @param g Sk³adowa zielona koloru (0.0 - 1.0)
     * @param b Sk³adowa niebieska koloru (0.0 - 1.0)
     */
    void setColor(float r, float g, float b);

  
};

