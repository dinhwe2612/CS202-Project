#include "SceneGame.hpp"

SceneGame::SceneGame() {
    // Create camera
    camera = Setting::getInstance()->getCamera();
    // Create object manager
    objectManager = new ObjectManager(Setting::getInstance()->getPathMap());
    Setting *setting = Setting::getInstance();
    setInputFunction(setting->getPickUp(), InputSupport::PRESSED, [this]() {
        objectManager->pick();
    });
    setInputFunction(setting->getDrop(), InputSupport::PRESSED, [this]() {
        objectManager->drop();
    });
    setInputFunction(setting->getCutCook(), InputSupport::PRESSED, [this]() {
        objectManager->cut_cook();
        objectManager->submitTask();
    });
    setInputFunction(setting->getMoveUp(), InputSupport::DOWN, [this]() {
        objectManager->movePlayer(Direction::UP);
    });
    setInputFunction(setting->getMoveDown(), InputSupport::DOWN, [this]() {
        objectManager->movePlayer(Direction::DOWN);
    });
    setInputFunction(setting->getMoveLeft(), InputSupport::DOWN, [this]() {
        objectManager->movePlayer(Direction::LEFT);
    });
    setInputFunction(setting->getMoveRight(), InputSupport::DOWN, [this]() {
        objectManager->movePlayer(Direction::RIGHT);
    });
}

SceneGame::~SceneGame() {

}

void SceneGame::draw() {
    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode3D(*camera);
        objectManager->draw();
    EndMode3D();
    objectManager->draw_tasks();
    EndDrawing();
}

Scenes SceneGame::run() {
    while(state == Scenes::DEFAULT) {
        triggerInputActions();
        objectManager->update();
        if (objectManager->isEndGame())
            state = Scenes::ENDGAME;
        draw();
        if (WindowShouldClose())
            return Scenes::PAUSE;
    }
    fade(true);
    return state;
}