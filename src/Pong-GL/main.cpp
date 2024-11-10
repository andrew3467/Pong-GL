
#include "Tungsten.h"
#include "Tungsten/Core/Window.h"

int main() {
    Tungsten::Logger::Init();

    Tungsten::Window window({1280, 720, "Simple Pong"});

    while(!window.ShouldClose()) {

        window.Update();
    }
}
