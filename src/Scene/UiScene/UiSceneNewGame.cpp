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
                    tran = 1;
                    break;
                } else if (i == 2) {
                    tran = 2;
                    break;
                } else if (i == 3) {
                    Setting::getInstance()->setCurMap(curMap);
                    state = Scenes::GAME;
                    break;
                }
            }
        }
    });
    for(int i = 0; i < buttons.size(); ++i) {
        colors[i] = WHITE;
    }
    curMap = 0;
    colorScenes = { WHITE, { 255, 255, 255, 0 }, { 255, 255, 255, 0 } };
    posScenes = { { 0, 0 }, { 510, 0 }, { 510, 0 } };
}

void UiSceneNewGame::transitionMap(int &tran) {
    if (tran == 0) return;
    if (curMap == 2 && tran == 2) return;
    if (curMap == 0 && tran == 1) return;
    if (tran == 2) {
        colorScenes[curMap].a -= 5;
        posScenes[curMap].x -= 10;
        colorScenes[curMap + 1].a += 5;
        posScenes[curMap + 1].x -= 10;
        if (colorScenes[curMap].a == 0) {
            tran = 0;
            curMap = curMap + 1;
        }
    } else if (tran == 1) {
        colorScenes[curMap].a -= 5;
        posScenes[curMap].x += 10;
        colorScenes[curMap - 1].a += 5;
        posScenes[curMap - 1].x += 10;
        if (colorScenes[curMap].a == 0) {
            tran = 0;
            curMap = curMap - 1;
        }
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
    transitionMap(tran);
}

void UiSceneNewGame::draw() {
    ClearBackground(BLACK);
    DrawTextureEx(resourcesManager->getTexture("backgroundSceneNewGame"), { 0, 0 }, 0, 1, WHITE);
    burgerGif->draw();
    
    for(int i = 0; i < 3; ++i) {
        DrawTextureEx(resourcesManager->getTexture("map" + std::to_string(i + 1)), posScenes[i], 0, 1, colorScenes[i]);
    }
    
    DrawTextureEx(resourcesManager->getTexture("arrowBack"), { 0, 0 }, 0, 1, colors[0]);
    DrawTextureEx(resourcesManager->getTexture("arrowLeft"), { 0, 0 }, 0, 1, colors[1]);
    DrawTextureEx(resourcesManager->getTexture("arrowRight"), { 0, 0 }, 0, 1, colors[2]);
    DrawTextureEx(resourcesManager->getTexture("Select"), { 0, 0 }, 0, 1, colors[3]);
}