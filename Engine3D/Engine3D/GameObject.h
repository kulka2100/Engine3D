#pragma once
#include <glm.hpp>
#include <GL/freeglut.h>

/**
 * @brief Klasa bazowa reprezentuj¹ca obiekt gry
 *
 * Klasa `GameObject` definiuje podstawowe cechy ka¿dego obiektu w grze
 */
class GameObject
{
protected:
    glm::mat4 modelMatrix; ///< Macierz modelu okreœlaj¹ca po³o¿enie, obrót i skalê obiektu
public:
    /**
     * @brief Konstruktor domyœlny
     *
     * Konstruktor domyœlny inicjuje nowy obiekt gry
     */
    GameObject();

    /**
     * @brief Destruktor wirtualny
     *
     * Destruktor wirtualny klasy bazowej `GameObject`
     * Zwalnia zasoby u¿ywane przez obiekt
     */
    virtual ~GameObject();

};

