#pragma once

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

class Camera
{
public:
    Camera();
    void setPosition(const glm::vec3& position);
    void setRotation(float pitch, float yaw);
    void move(const glm::vec3& offset);
    void rotate(float pitchOffset, float yawOffset);
    glm::mat4 getViewMatrix() const;

    glm::vec3 getFront() const;
    glm::vec3 getRight() const;

private:
    glm::vec3 position;
    float pitch; // Rotation around x-axis
    float yaw;   // Rotation around y-axis
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;

    void updateCameraVectors();
};

