
#include <glm/vec3.hpp>

#include "Ball.h"
#include "Bumper.h"
#include "Tungsten.h"


void MovePlayer(float ts, Bumper& bumper, const Tungsten::Window& window, int upkey, int downkey)
{
    const float movespeed = 0.125f;

    //Downward movement
    if(glfwGetKey(window.GetNativeWindow(), downkey) == GLFW_PRESS)
    {
        const glm::vec3& curPos = bumper.GetPosition();

        float dir = movespeed * ts;
        float newPos = curPos.y - dir;
        bumper.UpdatePosition({curPos.x, newPos, curPos.z});
    }


    //Upward movement
    if(glfwGetKey(window.GetNativeWindow(), upkey) == GLFW_PRESS)
    {
        const glm::vec3& curPos = bumper.GetPosition();

        float dir = movespeed * ts;
        float newPos = curPos.y + dir;
        bumper.UpdatePosition({curPos.x, newPos, curPos.z});
    }
}

int main() {
    Tungsten::Logger::Init();

    Tungsten::Window window({1280, 720, "Simple Pong"});

    Tungsten::Renderer::Init();

    Bumper player1({-2.75, 0, 0}, {0.25, 1.f, 1.0f});
    Bumper player2({2.75, 0, 0}, {0.25, 1.f, 1.0f});

    Ball ball({0,0,0}, {0.1f, 0.1f, 0.0f});


    float ts = 0.0f;
    float lastframe = 0.0f;

    float currentframe = (float)glfwGetTime();
    ts = currentframe - lastframe;
    lastframe = currentframe;

    while(!window.ShouldClose()) {
        MovePlayer(ts, player1, window, GLFW_KEY_W, GLFW_KEY_S);
        MovePlayer(ts, player2, window, GLFW_KEY_UP, GLFW_KEY_DOWN);
        player1.Update(ts);
        player2.Update(ts);
        ball.Update(ts);

        ball.CheckBumperCollision(player1, player2);

        Tungsten::Renderer::SetClearColor(0.5f, 0.3f, 1.0f);
        Tungsten::Renderer::Clear();

        Tungsten::Renderer::DrawQuad(player1.GetPosition(), player1.GetScale());
        Tungsten::Renderer::DrawQuad(player2.GetPosition(), player2.GetScale());
        Tungsten::Renderer::DrawQuad(ball.Position, glm::vec3(ball.Scale));

        window.Update();
    }
}
