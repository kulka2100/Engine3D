#include "ShapeObject.h"

ShapeObject::ShapeObject() : modelMatrix(glm::mat4(1.0f)) {}
//ShapeObject::ShapeObject() {}

ShapeObject::~ShapeObject() {}


void ShapeObject::setPosition(float x, float y, float z) {
    modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z));
}

void ShapeObject::scale(float sx, float sy, float sz) {
    modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));
}

void ShapeObject::rotate(float angle, float rx, float ry, float rz) {
    modelMatrix = glm::rotate(modelMatrix, glm::radians(angle), glm::vec3(rx, ry, rz));
}

void ShapeObject::translate(float tx, float ty, float tz) {
    modelMatrix = glm::translate(modelMatrix, glm::vec3(tx, ty, tz));
}
