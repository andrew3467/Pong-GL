
#include "Tungsten.h"


int main() {
    Tungsten::Logger::Init();

    Tungsten::Window window({1280, 720, "Simple Pong"});

    Tungsten::Renderer::Init();

    while(!window.ShouldClose()) {
        Tungsten::Renderer::SetClearColor(0.5f, 0.3f, 1.0f);
        Tungsten::Renderer::Clear();

        window.Update();
    }
}
