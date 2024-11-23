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
    glm::vec3 StartVelocity = {};

    int Player1Score = 0;
    int Player2Score = 0;

    float Scale = 0.25f;

    Ball(const glm::vec3& position, const glm::vec3& initialVelocity) : Position(position), StartVelocity(initialVelocity), Velocity(initialVelocity) {}

    void ResetBall()
    {
        Position = {};
        Velocity = StartVelocity;
    }

    void Update(float ts)
    {
        //Check bound collision, edge of screen space
        float upperEdge = Position.y + (Scale / 2);
        float lowerEdge = Position.y - (Scale / 2);
        float leftEdge = Position.x - (Scale / 2);
        float rightEdge = Position.x + (Scale / 2);


        if(upperEdge >= 1.7f)
        {
            Velocity.y *= -1.2;
        }
        if(lowerEdge <= -1.7f)
        {
            Velocity.y *= -1.2;
        }

        //Check edge collision
        if(leftEdge <= -3.0f)
        {
            Velocity.x *= -1;
            ResetBall();
            Player2Score++;

            TUNGSTEN_INFO("Player 1: {0}, Player 2 {1}", Player1Score, Player2Score);
        }
        if(rightEdge >= 3.0f)
        {
            Velocity.x *= -1;
            ResetBall();
            Player1Score++;

            TUNGSTEN_INFO("Player 1: {0}, Player 2: {1}", Player1Score, Player2Score);
        }


        Position += Velocity * ts;
    }

    bool CheckBumperCollision(const Bumper& leftBumper, const Bumper& rightBumper)
    {
        const auto& leftBumperPos = leftBumper.GetPosition();
        const auto& rightBumperPos = rightBumper.GetPosition();

        float upperEdge = Position.y + (Scale / 2);
        float lowerEdge = Position.y - (Scale / 2);

        if(Velocity.x < 0)
        {
            float leftEdge  = Position.x - (Scale / 2);
            float bumperRight = leftBumperPos.x + (leftBumper.GetScale().x / 2);
            float bumperUpper = leftBumperPos.y + (leftBumper.GetScale().y / 2);
            float bumperLower = leftBumperPos.y - (leftBumper.GetScale().y / 2);

            if(leftEdge <= bumperRight && upperEdge <= bumperUpper && lowerEdge >= bumperLower)
            {
                Velocity.x *= -1;
                return true;
            }
        }
        else
        {
            float rightEdge  = Position.x + (Scale / 2);

            float bumperLeft = rightBumperPos.x - (rightBumper.GetScale().x / 2);
            float bumperUpper = rightBumperPos.y + (rightBumper.GetScale().y / 2);
            float bumperLower = rightBumperPos.y - (rightBumper.GetScale().y / 2);

            if(rightEdge >= bumperLeft)
                if(upperEdge <= bumperUpper && lowerEdge >= bumperLower)
            {
                Velocity.x *= -1;
                return true;
            }
        }

        return false;
    }
};
