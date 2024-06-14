#pragma once
#include "BitmapHandler.h"
#include "DrawableObject.h"
#include "TransformableObject.h"
#include "BitmapHandler.h"
#include <GL/freeglut.h>
#include <ext/matrix_transform.hpp>
#include <iostream>

/**
 * @brief Klasa bazowa reprezentuj¹ca obiekt kszta³tu w przestrzeni 3D
 *
 * Klasa `ShapeObject` dziedziczy po klasach `DrawableObject` i `TransformableObject`
 * i implementuje podstawowe operacje transformacji oraz zarz¹dzania tekstur¹ obiektu.
 * Po tej klasie dziedzicz¹ wszystkie figury stosowane w silniku.
 */
class ShapeObject :
    public DrawableObject, TransformableObject
{
protected:
    glm::mat4 modelMatrix; ///< Macierz modelu obiektu
    BitmapHandler textureHandler; ///< Obiekt do obs³ugi tekstury
    GLuint textureID; ///< Identyfikator tekstury
public:
    /**
     * @brief Konstruktor domyœlny inicjuj¹cy obiekt kszta³tu
     */
    ShapeObject();

    /**
     * @brief Destruktor wirtualny
     */
    virtual ~ShapeObject();

    /**
     * @brief Ustawia pozycjê obiektu w przestrzeni 3D
     *
     * @param x Wspó³rzêdna x pozycji
     * @param y Wspó³rzêdna y pozycji
     * @param z Wspó³rzêdna z pozycji
     */
    void setPosition(float x, float y, float z);

    /**
     * @brief Skaluje obiekt wzd³u¿ trzech osi
     *
     * @param sx Skalowanie wzd³u¿ osi x
     * @param sy Skalowanie wzd³u¿ osi y
     * @param sz Skalowanie wzd³u¿ osi z
     */
    void scale(float sx, float sy, float sz);

    /**
     * @brief Obraca obiekt wokó³ osi o zadany k¹t
     *
     * @param angle K¹t obrócenia w stopniach
     * @param rx Sk³adowa x osi obrotu
     * @param ry Sk³adowa y osi obrotu
     * @param rz Sk³adowa z osi obrotu
     */
    void rotate(float angle, float rx, float ry, float rz);

    /**
     * @brief Przesuwa obiekt o zadan¹ odleg³oœæ wzd³u¿ trzech osi
     *
     * @param tx Przesuniêcie wzd³u¿ osi x
     * @param ty Przesuniêcie wzd³u¿ osi y
     * @param tz Przesuniêcie wzd³u¿ osi z
     */
    void translate(float tx, float ty, float tz);

    /**
     * @brief £aduje teksturê z pliku
     *
     * @param filePath Œcie¿ka do pliku tekstury
     * @return true jeœli tekstura zosta³a za³adowana pomyœlnie, false w przeciwnym razie
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