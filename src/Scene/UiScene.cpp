#include "UiScene.hpp"

UiScene::UiScene() : state(0) {

}

UiScene::~UiScene() {

}

Scenes UiScene::run() {
    while(state == -1) {
        if (WindowShouldClose())
            return Scenes::QUIT;
        triggerInputActions();
        eventScene();
        draw();
    }
    return endScene();
}