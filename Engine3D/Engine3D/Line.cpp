#include "Line.h"


Line::Line(float x1, float y1, float x2, float y2) {
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
}


void Line::drawLine() {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void Line::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
    glColor3f(r, g, b);
}