#include "UiScene.hpp"

UiScene::UiScene() : AScene() {
    
}

UiScene::~UiScene() {

}

Scenes UiScene::run() {
    while(state == Scenes::DEFAULT) {
        BeginDrawing();
        if (WindowShouldClose())
            return Scenes::QUIT;
        triggerInputActions();
        eventScene();
        draw();
        EndDrawing();
    }
    return endScene();
}