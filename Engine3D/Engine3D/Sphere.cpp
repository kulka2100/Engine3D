#include "Sphere.h"


void Sphere::draw() {

    glPushMatrix();
    glColor3f(colors.x, colors.y, colors.z);


    glMultMatrixf(glm::value_ptr(modelMatrix));

    if (solid) {
        glutSolidSphere(radius, rings, sectors);
    }
    else
    {
        glutWireSphere(radius, rings, sectors);
    }
    glPopMatrix();

}


void Sphere::isSolid(bool solid) {
    this->solid = solid;
}

void Sphere::setColor(float red, float green, float blue) {
        colors.x = red;
        colors.y = green;
        colors.z = blue;
  
}
