#pragma once
#include "GameObject.h"
#include <iostream>
#include <gtc/matrix_transform.hpp> 
#include <glm.hpp>
#include <GL/freeglut.h>
#include <ext/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

/**
 * @brief Klasa bazowa reprezentuj�ca transformowalny obiekt w przestrzeni 3D
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
     * @brief Konstruktor domy�lny inicjuj�cy obiekt transformowalny
     */
    TransformableObject();

    /**
     * @brief Destruktor wirtualny
     */
    virtual ~TransformableObject();

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


};
