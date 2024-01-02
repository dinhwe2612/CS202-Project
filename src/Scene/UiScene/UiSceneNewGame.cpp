#include "UiSceneNewGame.hpp"

UiSceneNewGame::UiSceneNewGame() : UiScene() {
    burgerGif = new Gif("../resources/texture/burger.gif", 8);
    burgerGif->setPosition({ 1900, -50 });
    for(int i = 0; i < 4; ++i) {
        buttons.push_back(std::unique_ptr<Button>(new Button()));
    }
    colors.resize(buttons.size());
    buttons[0]->setBox(44.9, 52.8, 175.9, 175.9);
    buttons[1]->setBox(180, 824.8, 368.1, 298.5);
    buttons[2]->setBox(2452.1, 824.8, 368.1, 298.5);
    buttons[3]->setBox(2230.2, 1574.1, 726.7, 206.1);
    setInputFunction(InputSupport::MOUSE_LEFT, InputSupport::RELEASED, [this]() {
        for(int i = 0; i < buttons.size(); ++i) {
            if(buttons[i]->isTouch()) {
                if (i == 0) {
                    state = Scenes::MENU;
                    break;
                } else if (i == 1) {
                    
                    break;
                } else if (i == 2) {
                    
                    break;
                } else if (i == 3) {
                    state = Scenes::GAME;
                    break;
                }
            }
        }
    });
    for(int i = 0; i < buttons.size(); ++i) {
        colors[i] = WHITE;
    }
}

void UiSceneNewGame::eventScene() {
    for(int i = 0; i < buttons.size(); ++i) {
        if (buttons[i]->getState() == Button::CLICKED) {
            colors[i] = { 255, 255, 255, 100 };
        } else {
            colors[i] = WHITE;
        }
    }
    burgerGif->update();
}

void UiSceneNewGame::draw() {
    ClearBackground(BLACK);
    DrawTextureEx(resourcesManager->getTexture("backgroundSceneNewGame"), { 0, 0 }, 0, 1, WHITE);
    burgerGif->draw();
    DrawTextureEx(resourcesManager->getTexture("map1"), { 0, 0 }, 0, 1, WHITE);
    DrawTextureEx(resourcesManager->getTexture("arrowBack"), { 0, 0 }, 0, 1, colors[0]);
    DrawTextureEx(resourcesManager->getTexture("arrowLeft"), { 0, 0 }, 0, 1, colors[1]);
    DrawTextureEx(resourcesManager->getTexture("arrowRight"), { 0, 0 }, 0, 1, colors[2]);
    DrawTextureEx(resourcesManager->getTexture("Select"), { 0, 0 }, 0, 1, colors[3]);
}