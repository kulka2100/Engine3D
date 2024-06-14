#pragma once
#include "BitmapHandler.h"
#include "DrawableObject.h"
#include "TransformableObject.h"
#include "BitmapHandler.h"
#include <GL/freeglut.h>
#include <ext/matrix_transform.hpp>
#include <iostream>

/**
 * @brief Klasa bazowa reprezentuj�ca obiekt kszta�tu w przestrzeni 3D
 *
 * Klasa `ShapeObject` dziedziczy po klasach `DrawableObject` i `TransformableObject`
 * i implementuje podstawowe operacje transformacji oraz zarz�dzania tekstur� obiektu.
 * Po tej klasie dziedzicz� wszystkie figury stosowane w silniku.
 */
class ShapeObject :
    public DrawableObject, TransformableObject
{
protected:
    glm::mat4 modelMatrix; ///< Macierz modelu obiektu
    BitmapHandler textureHandler; ///< Obiekt do obs�ugi tekstury
    GLuint textureID; ///< Identyfikator tekstury
public:
    /**
     * @brief Konstruktor domy�lny inicjuj�cy obiekt kszta�tu
     */
    ShapeObject();

    /**
     * @brief Destruktor wirtualny
     */
    virtual ~ShapeObject();

    /**
     * @brief Ustawia pozycj� obiektu w przestrzeni 3D
     *
     * @param x Wsp�rz�dna x pozycji
     * @param y Wsp�rz�dna y pozycji
     * @param z Wsp�rz�dna z pozycji
     */
    void setPosition(float x, float y, float z);

    /**
     * @brief Skaluje obiekt wzd�u� trzech osi
     *
     * @param sx Skalowanie wzd�u� osi x
     * @param sy Skalowanie wzd�u� osi y
     * @param sz Skalowanie wzd�u� osi z
     */
    void scale(float sx, float sy, float sz);

    /**
     * @brief Obraca obiekt wok� osi o zadany k�t
     *
     * @param angle K�t obr�cenia w stopniach
     * @param rx Sk�adowa x osi obrotu
     * @param ry Sk�adowa y osi obrotu
     * @param rz Sk�adowa z osi obrotu
     */
    void rotate(float angle, float rx, float ry, float rz);

    /**
     * @brief Przesuwa obiekt o zadan� odleg�o�� wzd�u� trzech osi
     *
     * @param tx Przesuni�cie wzd�u� osi x
     * @param ty Przesuni�cie wzd�u� osi y
     * @param tz Przesuni�cie wzd�u� osi z
     */
    void translate(float tx, float ty, float tz);

    /**
     * @brief �aduje tekstur� z pliku
     *
     * @param filePath �cie�ka do pliku tekstury
     * @return true je�li tekstura zosta�a za�adowana pomy�lnie, false w przeciwnym razie
     */
    bool loadTexture(const char* filePath) {
        return textureHandler.LoadTexture(filePath);
    }

    /**
     * @brief Zwraca identyfikator tekstury
     *
     * @return Identyfikator tekstury
     */
    GLuint getTextureID() const { return textureHandler.GetTextureID(); }
};