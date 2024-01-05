#include "SceneGame.hpp"

SceneGame::SceneGame() {
    music = Setting::getInstance()->getMusic("Game");
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
    BeginMode3D(*camera);
        objectManager->draw();
    EndMode3D();
    objectManager->draw_tasks();
}

Scenes SceneGame::run() {
    // fade(false);
    SetMusicVolume(music, 0.2);
    PlayMusicStream(music);
    while(state == Scenes::DEFAULT) {
        if (!Setting::getInstance()->IsMute()) {
            UpdateMusicStream(music);
        }
        
        BeginDrawing();
        ClearBackground(BLACK);
        triggerInputActions();
        objectManager->update();
        camera->position.x = objectManager->getPosPlayer().x;
        camera->target.x = camera->position.x;
        if (objectManager->isEndGame())
            state = Scenes::ENDGAME;
        draw();
        if (WindowShouldClose())
            return Scenes::PAUSE;
        EndDrawing();
    }
    fade(true);
    return state;
}