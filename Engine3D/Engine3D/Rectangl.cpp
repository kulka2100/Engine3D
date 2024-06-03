#include "Rectangl.h"


Rectangl:: Rectangl(float x, float y, float width, float height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}


void Rectangl::draw() {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}


void Rectangl::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
    glColor3f(r, g, b);
}
