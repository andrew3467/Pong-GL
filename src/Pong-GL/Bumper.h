//
// Created by Andrew Graser on 11/19/2024.
//


#pragma once

#include <glm/glm.hpp>

class Bumper {
public:
    Bumper(const glm::vec3& pos, const glm::vec3& scale);
    Bumper() = delete;
    ~Bumper() = default;


    void Update(float ts);

    void UpdatePosition(const glm::vec3& newPos) { mPosition = newPos;}


    const glm::vec3& GetPosition() const {return mPosition;}
    const glm::vec3& GetScale() const {return mScale;}

private:
    //returns true if velocity should be inverted, IE. top or bottom bound reached
    bool CheckBounds();


private:
    glm::vec3 mPosition = {};
    glm::vec3 mScale = {1,1,1};

    float mVelocity = 0.0f;
};
