#include "Camera.h"

Camera::Camera()
    : position(0.0f, 0.0f, 0.0f), pitch(0.0f), yaw(-90.0f), front(0.0f, 0.0f, -1.0f), up(0.0f, 1.0f, 0.0f) {
    updateCameraVectors();
}

void Camera::setPosition(const glm::vec3& newPosition) {
    position = newPosition;
    updateCameraVectors();
}

void Camera::setRotation(float newPitch, float newYaw) {
    pitch = newPitch;
    yaw = newYaw;
    updateCameraVectors();
}

void Camera::move(const glm::vec3& offset) {
    position += offset;
    updateCameraVectors();
}

void Camera::rotate(float pitchOffset, float yawOffset) {
    pitch += pitchOffset;
    yaw += yawOffset;
    updateCameraVectors();
}

glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(position, position + front, up);
}

glm::vec3 Camera::getFront() const {
    return front;
}

glm::vec3 Camera::getRight() const {
    return right;
}

void Camera::updateCameraVectors() {
    glm::vec3 newFront;
    newFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    newFront.y = sin(glm::radians(pitch));
    newFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(newFront);
    right = glm::normalize(glm::cross(front, up));
    up = glm::normalize(glm::cross(right, front));
}