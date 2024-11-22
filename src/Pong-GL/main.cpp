
#include <glm/vec3.hpp>

#include "Ball.h"
#include "Bumper.h"
#include "Tungsten.h"


int main() {
    Tungsten::Logger::Init();

    Tungsten::Window window({1280, 720, "Simple Pong"});

    Tungsten::Renderer::Init();

    Bumper player1({-2.75, 1.2, 0}, {0.25, 1.f, 1.0f});
    Bumper player2({2.75, 0.8, 0}, {0.25, 1.f, 1.0f});

    Ball ball({0,0,0}, {0.2f, 0.2f, 0.0f});


    while(!window.ShouldClose()) {
        player1.Update(1.0f);
        player2.Update(1.0f);
        ball.Update(.025f);

        ball.CheckBumperCollision(player1, player2);

        Tungsten::Renderer::SetClearColor(0.5f, 0.3f, 1.0f);
        Tungsten::Renderer::Clear();

        Tungsten::Renderer::DrawQuad(player1.GetPosition(), player1.GetScale());
        Tungsten::Renderer::DrawQuad(player2.GetPosition(), player2.GetScale());
        Tungsten::Renderer::DrawQuad(ball.Position, glm::vec3(ball.Scale));

        window.Update();
    }
}
