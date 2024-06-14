#pragma once
#include "BitmapHandler.h"
#include <GL/freeglut.h>
#include <iostream>
#include <glm.hpp>
#include <vec4.hpp>
#include "ShapeObject.h"

/**
 * @brief Klasa reprezentuj�ca ko�o 2D
 *
 * Klasa `Circle` dziedziczy po `ShapeObject` i reprezentuje ko�o, kt�re mo�na rysowa� w przestrzeni 2D
 */
class Circle : public ShapeObject {
private:
	float cx; ///< Wsp�rz�dna x �rodka ko�a
	float cy; ///< Wsp�rz�dna y �rodka ko�a
	float radius; ///< Promie� ko�a
	const int segments = 50; ///< Liczba segment�w u�ywanych do rysowania ko�a
	float r, g, b; ///< Kolory RGB ko�a

public:
	/**
	 * @brief Konstruktor inicjalizuj�cy
	 *
	 * Tworzy nowe ko�o z podanymi wsp�rz�dnymi �rodka i promieniem
	 *
	 * @param[in] cx Wsp�rz�dna x �rodka ko�a
	 * @param[in] cy Wsp�rz�dna y �rodka ko�a
	 * @param[in] radius Promie� ko�a
	 */
	Circle(float cx, float cy, float radius);

	/**
	 * @brief Pobiera wsp�rz�dn� x �rodka ko�a
	 *
	 * @return Wsp�rz�dna x �rodka ko�a
	 */
	float getCx() {
		return cx;
	}

	/**
	 * @brief Pobiera wsp�rz�dn� y �rodka ko�a
	 *
	 * @return Wsp�rz�dna y �rodka ko�a
	 */
	float getCy() {
		return cy;
	}

	/**
	 * @brief Pobiera promie� ko�a
	 *
	 * @return Promie� ko�a
	 */
	float getRadius() {
		return radius;
	}

	/**
	 * @brief Rysuje ko�o
	 *
	 * Implementacja metody `draw` z klasy `ShapeObject`, kt�ra rysuje ko�o w przestrzeni 2D
	 */
	void draw() override;

	/**
	 * @brief Ustawia kolor ko�a
	 *
	 * Ustawia warto�ci kolor�w RGB ko�a
	 *
	 * @param[in] r Sk�adowa koloru czerwonego (0.0 - 1.0)
	 * @param[in] g Sk�adowa koloru zielonego (0.0 - 1.0)
	 * @param[in] b Sk�adowa koloru niebieskiego (0.0 - 1.0)
	 */
	void setColor(float r, float g, float b);


};

