#include "Application.hpp"

Application::Application() {
    state = QUIT;
    InitWindow(3000, 1800, "Burger Restaurant");
    curScene = new UiSceneMenu();
}

Application::~Application() {
    CloseWindow();
}

void Application::run() {
    while (!WindowShouldClose()) {
        state = curScene->run();
        std::cout << "state: " << state << std::endl;
        if (state != Scenes::DEFAULT) break;
    }
}