#include "Application.hpp"

Application::Application() {
    state = QUIT;
    curScene = new UiSceneMenu();
    InitWindow(3000, 1800, "Burger Restaurant");
}

Application::~Application() {
    CloseWindow();
}

void Application::run() {
    while (!WindowShouldClose()) {
        state = curScene->run();
        if (state == QUIT) break;
    }
}