#pragma once
#include "GameObject.h"
#include <iostream>
#include <gtc/matrix_transform.hpp> 
#include <glm.hpp>
#include <GL/freeglut.h>
#include <ext/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

/**
 * @brief Klasa bazowa reprezentuj¹ca transformowalny obiekt w przestrzeni 3D
 *
 * Klasa `TransformableObject` dziedziczy po klasie `GameObject` i implementuje
 * podstawowe operacje transformacji obiektu
 */
class TransformableObject :
    public GameObject
{
protected:
    glm::mat4 modelMatrix; ///< Macierz modelu obiektu
public:
    /**
     * @brief Konstruktor domyœlny inicjuj¹cy obiekt transformowalny
     */
    TransformableObject();

    /**
     * @brief Destruktor wirtualny
     */
    virtual ~TransformableObject();

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


};
