#include "Circle.h"

Circle::Circle(float cx, float cy, float radius) {
	this->cx = cx;
	this->cy = cy;
	this->radius = radius;
}


void Circle::drawCircle() {
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < segments; ++i) {
		float theta = 2.0f * 3.1415926f * float(i) / float(segments); // Wartoœæ k¹ta w radianach
		float x = radius * cosf(theta);
		float y = radius * sinf(theta);
		glVertex2f(x + cx, y + cy);
	}
	glEnd();
}


void Circle::setColor(float r, float g, float b) {
	this->r = r;
	this->g = g;
	this->b = b;
	glColor3f(r, g, b);
}