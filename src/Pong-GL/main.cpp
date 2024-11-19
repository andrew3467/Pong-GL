
#include <glm/vec3.hpp>

#include "Tungsten.h"


int main() {
    Tungsten::Logger::Init();

    Tungsten::Window window({1280, 720, "Simple Pong"});

    Tungsten::Renderer::Init();

        glm::vec3 p1(0,0,0);
        glm::vec3 p2(-1, 0,0);
        glm::vec3 p3(1, 0.5,0);
    while(!window.ShouldClose()) {
        Tungsten::Renderer::SetClearColor(0.5f, 0.3f, 1.0f);
        Tungsten::Renderer::Clear();

        Tungsten::Renderer::DrawQuad(p1, {0.5f, 0.5f, 0.5f});
        Tungsten::Renderer::DrawQuad(p2, {2.0f, 0.5f, 1.0f});
        Tungsten::Renderer::DrawQuad(p3, {0.5f, 2.0f, 1.0f});

        window.Update();
    }
}
