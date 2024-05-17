#pragma once
#include <GL/freeglut.h>
#include <iostream>
#include <glm.hpp>
#include <vec4.hpp>

class Circle{
private:
	float cx;
	float cy;
	float radius;
	const int segments = 50;
	float r, g, b;
public:
	Circle(float cx, float cy, float radius);

	float getCx() {
		return cx;
	}

	float getCy() {
		return cy;
	}

	float getRadius() {
		return radius;
	}

	void drawCircle();

	void setColor(float r, float g, float b);


};

