#include "UiScenePauseGame.hpp"

UiScenePauseGame::UiScenePauseGame() : UiScene() {
    buttons.push_back(std::unique_ptr<Button>(new Button()));
    buttons.back()->setBox(1096.9, 605.9, 806.2, 242.5, 
                            { 0, 0, 0, 0 }, 
                            { 0, 0, 0, 0 }, 
                            { 0, 0, 0, 50 });
    buttons.push_back(std::unique_ptr<Button>(new Button()));
    buttons.back()->setBox(1096.9, 961.2, 806.2, 242.5, 
                            { 0, 0, 0, 0 }, 
                            { 0, 0, 0, 0 }, 
                            { 0, 0, 0, 50 });
    setInputFunction(InputSupport::MOUSE_LEFT, InputSupport::RELEASED, [this]() {
        if (buttons[0]->isTouch()) {
            state = Scenes::GAME;
        } else if (buttons[1]->isTouch()) {
            state = Scenes::MENU;
        }
    });
    setFade(false, 0);
}

void UiScenePauseGame::eventScene() {
    for(auto& button : buttons) {
        int stateButton = button->getState();
        if (stateButton == Button::TOUCHED || stateButton == Button::CLICKED) {
            button->setConer(true);
        } else {
            button->setConer(false);
        }
    }
}

void UiScenePauseGame::draw() {
    DrawTexture(resourcesManager->getTexture("ScenePauseGame"), 0, 0, WHITE);
    for(auto& button : buttons) {
        button->draw();
    }
}