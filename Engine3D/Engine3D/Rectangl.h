#pragma once
#include "BitmapHandler.h"
#include <GL/freeglut.h>
#include <iostream>
#include <glm.hpp>
#include <vec4.hpp>
#include "ShapeObject.h"

/**
 * @brief Klasa reprezentuj�ca prostok�t w przestrzeni 2D
 *
 * Klasa `Rectangl` dziedziczy po klasie `ShapeObject` i definiuje funkcjonalno��
 * obiektu prostok�tnego, kt�ry mo�e by� rysowany w aplikacji graficznej
 */
class Rectangl : public ShapeObject {
private:
    float x; ///< Wsp�rz�dna x lewego dolnego rogu prostok�ta
    float y; ///< Wsp�rz�dna y lewego dolnego rogu prostok�ta
    float width; ///< Szeroko�� prostok�ta
    float height; ///< Wysoko�� prostok�ta
    float r, g, b; ///< Sk�adowe koloru prostok�ta


public:
    /**
     * @brief Konstruktor inicjuj�cy prostok�t
     *
     * Konstruktor inicjuje obiekt prostok�ta z podanymi parametrami
     *
     * @param x Wsp�rz�dna x lewego dolnego rogu prostok�ta
     * @param y Wsp�rz�dna y lewego dolnego rogu prostok�ta
     * @param width Szeroko�� prostok�ta
     * @param height Wysoko�� prostok�ta
     */
    Rectangl(float x, float y, float width, float height);

    /**
     * @brief Zwraca wsp�rz�dn� x lewego dolnego rogu prostok�ta
     *
     * @return Wsp�rz�dna x lewego dolnego rogu prostok�ta
     */
    float getX() {
        return x;
    }

    /**
     * @brief Zwraca wsp�rz�dn� y lewego dolnego rogu prostok�ta
     *
     * @return Wsp�rz�dna y lewego dolnego rogu prostok�ta
     */
    float getY() {
        return y;
    }

    /**
     * @brief Zwraca szeroko�� prostok�ta
     *
     * @return Szeroko�� prostok�ta
     */
    float getWidth() {
        return width;
    }

    /**
     * @brief Zwraca wysoko�� prostok�ta
     *
     * @return Wysoko�� prostok�ta
     */
    float getHeight() {
        return height;
    }

    /**
     * @brief Metoda rysuj�ca prostok�t
     *
     * Metoda przedefiniowana z klasy bazowej `ShapeObject`
     * Rysuje prostok�t na scenie
     */
    void draw() override;

    /**
     * @brief Ustawia kolor prostok�ta
     *
     * @param r Sk�adowa czerwona koloru (0.0 - 1.0)
     * @param g Sk�adowa zielona koloru (0.0 - 1.0)
     * @param b Sk�adowa niebieska koloru (0.0 - 1.0)
     */
    void setColor(float r, float g, float b);

  
};

