#pragma once
#include <GL/freeglut.h>
#include <iostream>
#include <glm.hpp>
#include <vec4.hpp>
#include <ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <ext/matrix_clip_space.hpp> // glm::perspective
#include <ext/scalar_constants.hpp>


class PrimitiveRenderer {
public:
    // Metoda rysuj�ca prostok�t
    static void drawRectangle(float x, float y, float width, float height);

    // Metoda rysuj�ca ko�o
    static void drawCircle(float cx, float cy, float radius, int segments);

    // Metoda rysuj�ca linie
    static void drawLine(float x1, float y1, float x2, float y2);

    // Metoda rysuj�ca tr�jk�t
    static void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
};

