#include "SceneGame.hpp"

SceneGame::SceneGame() {
    // Create camera
    camera.position = (Vector3){ -10.0f, 13.0f, 18.0f };//-10 13 18
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 90.0f, 0.0f };
    camera.fovy = 40.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    // Create object manager
    objectManager = new ObjectManager("../resources/map");
    setInputFunction(InputSupport::E, InputSupport::PRESSED, [this]() {
        objectManager->pick();
    });
    setInputFunction(InputSupport::Q, InputSupport::PRESSED, [this]() {
        objectManager->drop();
    });
    setInputFunction(InputSupport::SPACE, InputSupport::PRESSED, [this]() {
        objectManager->cut_cook();
        objectManager->submitTask();
    });
    setInputFunction(InputSupport::W, InputSupport::DOWN, [this]() {
        objectManager->movePlayer(Direction::UP);
    });
    setInputFunction(InputSupport::S, InputSupport::DOWN, [this]() {
        objectManager->movePlayer(Direction::DOWN);
    });
    setInputFunction(InputSupport::A, InputSupport::DOWN, [this]() {
        objectManager->movePlayer(Direction::LEFT);
    });
    setInputFunction(InputSupport::D, InputSupport::DOWN, [this]() {
        objectManager->movePlayer(Direction::RIGHT);
    });
}

SceneGame::~SceneGame() {

}

void SceneGame::draw() {
    triggerInputActions();
    objectManager->update();
    
    ClearBackground(BLACK);
    BeginDrawing();
    BeginMode3D(camera);
        objectManager->draw();
    EndMode3D();
    objectManager->draw_tasks();
    EndDrawing();
}

Scenes SceneGame::run() {
    while(state == Scenes::DEFAULT) {
        if (WindowShouldClose())
            return Scenes::QUIT;
        draw();
    }
    return state;
}