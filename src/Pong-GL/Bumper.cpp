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

}

bool Bumper::CheckBounds()
{
    return true;
}
