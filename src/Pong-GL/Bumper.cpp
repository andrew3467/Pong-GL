//
// Created by Andrew Graser on 11/19/2024.
//

#include "Bumper.h"

Bumper::Bumper(const glm::vec3 &pos, const glm::vec3 &scale)
    : mPosition(pos), mScale(scale)
{

}

void Bumper::Update(float ts)
{
    //Clamp bumper within screen
    mPosition.y = glm::clamp(mPosition.y, -1.25f, 1.25f);
}

bool Bumper::CheckBounds()
{
    return true;
}
