#include "Application.hpp"

Application::Application() {
    InitWindow(3000, 1800, "Burger Restaurant");
    state = MENU;
}

Application::~Application() {
    CloseWindow();
}

void Application::run() {
    while (!WindowShouldClose()) {
        if (state != DEFAULT) {
            curScene = enumToConstructor.at(state)();
        }
        state = curScene->run();
        std::cout << "state: " << state << std::endl;
        if (state == Scenes::QUIT) break;
    }
}