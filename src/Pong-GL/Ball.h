//
// Created by Andrew Graser on 11/19/2024.
//


#pragma once

#include <glm/vec3.hpp>

#include "Bumper.h"
#include "Tungsten/Core/Logger.h"

struct Ball
{
    glm::vec3 Position = {};
    glm::vec3 Velocity = {};
    float Scale = 0.25f;

    Ball(const glm::vec3& position, const glm::vec3& initialVelocity) : Position(position), Velocity(initialVelocity) {}

    void Update(float ts)
    {
        //Check bound collision, edge of screen space
        float upperEdge = Position.y + (Scale / 2);
        float lowerEdge = Position.y - (Scale / 2);

        if(upperEdge >= 1.7f)
        {
            Velocity.y *= -1;
        }
        if(lowerEdge <= -1.7f)
        {
            Velocity.y *= -1;
        }


        Position += Velocity * ts;
    }

    bool CheckBumperCollision(const Bumper& bumper)
    {
        const auto& bumperPos = bumper.GetPosition();

        if(Velocity.x < 0)
        {
            float leftEdge  = Position.x - (Scale / 2);
            float bumperRight = bumperPos.x + (bumper.GetScale().x / 2);

            if(leftEdge >= bumperRight)
            {
                TUNGSTEN_INFO("Collision 1 at {0}, {1}", Position.x, Position.y);
                Velocity.x *= -1;
                return true;
            }
        }
        else
        {
            float rightEdge  = Position.x + (Scale / 2);

            float bumperLeft = bumperPos.x - (bumper.GetScale().x / 2);

            if(rightEdge <= bumperLeft)
            {
                TUNGSTEN_INFO("Collision 2 at {0}, {1}", Position.x, Position.y);
                Velocity.x *= -1;
                return true;
            }
        }

        return false;
    }
};
