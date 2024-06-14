#pragma once
#include "GameObject.h"

/**
 * @brief Klasa bazowa dla obiektów, które mog¹ byæ aktualizowane
 *
 * Klasa `UpdatableObject` dziedziczy po klasie `GameObject` i wprowadza
 * wirtualn¹ metodê `update`, któr¹ musz¹ implementowaæ klasy pochodne
 */
class UpdatableObject :
    public GameObject
{
public:
    /**
     * @brief Konstruktor domyœlny
     *
     * Inicjuje obiekt klasy `UpdatableObject`
     */
    UpdatableObject();

    /**
     * @brief Wirtualny destruktor
     *
     * Umo¿liwia poprawne usuwanie obiektów pochodnych
     */
    virtual ~UpdatableObject();

    /**
     * @brief Wirtualna metoda aktualizuj¹ca
     *
     * Musi byæ zaimplementowana w klasach pochodnych, aby zaktualizowaæ stan obiektu
     */
    virtual void update() = 0;
};

