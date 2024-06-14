#pragma once
#include <glm.hpp>
#include <GL/freeglut.h>

/**
 * @brief Klasa bazowa reprezentuj�ca obiekt gry
 *
 * Klasa `GameObject` definiuje podstawowe cechy ka�dego obiektu w grze
 */
class GameObject
{
protected:
    glm::mat4 modelMatrix; ///< Macierz modelu okre�laj�ca po�o�enie, obr�t i skal� obiektu
public:
    /**
     * @brief Konstruktor domy�lny
     *
     * Konstruktor domy�lny inicjuje nowy obiekt gry
     */
    GameObject();

    /**
     * @brief Destruktor wirtualny
     *
     * Destruktor wirtualny klasy bazowej `GameObject`
     * Zwalnia zasoby u�ywane przez obiekt
     */
    virtual ~GameObject();

};

