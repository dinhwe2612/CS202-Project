#include "Application.hpp"

Application::Application() {
    InitWindow(3000, 1800, "Burger Restaurant");
    state = Scenes::MENU;
}

Application::~Application() {
    CloseWindow();
}

void Application::run() {
    while (!WindowShouldClose()) {
        if (state != DEFAULT) {
            if (state == PAUSE) {
                prevScene = std::move(curScene);
            }
            if (state == GAME && prevScene != NULL) {
                curScene = std::move(prevScene);
            } else {
                curScene = std::move(enumToConstructor.at(state)());
            }
        }
        state = curScene->run();
        if (state != PAUSE && state != GAME) {
            prevScene.release();
            prevScene = NULL;
        }
        std::cout << "state: " << state << std::endl;
        if (state == Scenes::QUIT) break;
    }
}