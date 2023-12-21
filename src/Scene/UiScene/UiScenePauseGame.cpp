#include "UiScenePauseGame.hpp"

UiScenePauseGame::UiScenePauseGame() : UiScene() {
    // resume, setting, quit
    // buttons.emplace_back(std::unique_ptr<Button>(new Button("Resume", 0, 0, 0, 0)));
}

void UiScenePauseGame::eventScene() {
    if (buttons[0]->getState() == Button::CLICKED) {
        state = DEFAULT;
    } else if (buttons[1]->getState() == Button::CLICKED) {
        state = QUIT;
    }
}

void UiScenePauseGame::draw() {
    for (auto &button : buttons) {
        button->draw();
    }
}