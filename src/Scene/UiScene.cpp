#include "UiScene.hpp"

UiScene::UiScene() : AScene() {
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
    while(state == DEFAULT) {
        BeginDrawing();
        if (WindowShouldClose())
            return Scenes::QUIT;
        triggerInputActions();
        draw();
        EndDrawing();
    }
    return state;
}