#pragma once
#include "BitmapHandler.h"
#include <GL/freeglut.h>
#include <iostream>
#include <glm.hpp>
#include <vec4.hpp>
#include "ShapeObject.h"

/**
 * @brief Klasa reprezentuj¹ca ko³o 2D
 *
 * Klasa `Circle` dziedziczy po `ShapeObject` i reprezentuje ko³o, które mo¿na rysowaæ w przestrzeni 2D
 */
class Circle : public ShapeObject {
private:
	float cx; ///< Wspó³rzêdna x œrodka ko³a
	float cy; ///< Wspó³rzêdna y œrodka ko³a
	float radius; ///< Promieñ ko³a
	const int segments = 50; ///< Liczba segmentów u¿ywanych do rysowania ko³a
	float r, g, b; ///< Kolory RGB ko³a

public:
	/**
	 * @brief Konstruktor inicjalizuj¹cy
	 *
	 * Tworzy nowe ko³o z podanymi wspó³rzêdnymi œrodka i promieniem
	 *
	 * @param[in] cx Wspó³rzêdna x œrodka ko³a
	 * @param[in] cy Wspó³rzêdna y œrodka ko³a
	 * @param[in] radius Promieñ ko³a
	 */
	Circle(float cx, float cy, float radius);

	/**
	 * @brief Pobiera wspó³rzêdn¹ x œrodka ko³a
	 *
	 * @return Wspó³rzêdna x œrodka ko³a
	 */
	float getCx() {
		return cx;
	}

	/**
	 * @brief Pobiera wspó³rzêdn¹ y œrodka ko³a
	 *
	 * @return Wspó³rzêdna y œrodka ko³a
	 */
	float getCy() {
		return cy;
	}

	/**
	 * @brief Pobiera promieñ ko³a
	 *
	 * @return Promieñ ko³a
	 */
	float getRadius() {
		return radius;
	}

	/**
	 * @brief Rysuje ko³o
	 *
	 * Implementacja metody `draw` z klasy `ShapeObject`, która rysuje ko³o w przestrzeni 2D
	 */
	void draw() override;

	/**
	 * @brief Ustawia kolor ko³a
	 *
	 * Ustawia wartoœci kolorów RGB ko³a
	 *
	 * @param[in] r Sk³adowa koloru czerwonego (0.0 - 1.0)
	 * @param[in] g Sk³adowa koloru zielonego (0.0 - 1.0)
	 * @param[in] b Sk³adowa koloru niebieskiego (0.0 - 1.0)
	 */
	void setColor(float r, float g, float b);


};

