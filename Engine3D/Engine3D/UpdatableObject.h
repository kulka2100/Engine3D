#pragma once
#include "GameObject.h"

/**
 * @brief Klasa bazowa dla obiekt�w, kt�re mog� by� aktualizowane
 *
 * Klasa `UpdatableObject` dziedziczy po klasie `GameObject` i wprowadza
 * wirtualn� metod� `update`, kt�r� musz� implementowa� klasy pochodne
 */
class UpdatableObject :
    public GameObject
{
public:
    /**
     * @brief Konstruktor domy�lny
     *
     * Inicjuje obiekt klasy `UpdatableObject`
     */
    UpdatableObject();

    /**
     * @brief Wirtualny destruktor
     *
     * Umo�liwia poprawne usuwanie obiekt�w pochodnych
     */
    virtual ~UpdatableObject();

    /**
     * @brief Wirtualna metoda aktualizuj�ca
     *
     * Musi by� zaimplementowana w klasach pochodnych, aby zaktualizowa� stan obiektu
     */
    virtual void update() = 0;
};

