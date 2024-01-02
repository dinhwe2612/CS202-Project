#include "UiScene.hpp"

UiScene::UiScene() : AScene() {
    state = Scenes::DEFAULT;
    setInputFunction(InputSupport::MOUSE_LEFT, InputSupport::DEFAULT, [this]() {
        for(auto &button : buttons) {
            if(button->isTouch()) {
                button->setState(Button::TOUCHED);
            } else {
                button->setState(Button::DEFAULT);
            }
        }
    });
    setInputFunction(InputSupport::MOUSE_LEFT, InputSupport::DOWN, [this]() {
        for(auto &button : buttons) {
            if(button->isTouch()) {
                button->setState(Button::CLICKED);
                break;
            }
        }
    });
}

UiScene::~UiScene() {

}

Scenes UiScene::run() {
    fade(false);
    while(state == DEFAULT) {
        BeginDrawing();
        if (WindowShouldClose())
            return Scenes::QUIT;
        eventScene();
        triggerInputActions();
        draw();
        EndDrawing();
    }
    fade(true);
    return state;
}