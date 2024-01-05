#include "UiSceneMenu.hpp"

UiSceneMenu::UiSceneMenu() : UiScene() {
    buttons.push_back(std::unique_ptr<Button>(new Button()));
    buttons.back()->setBox(2200, 380, 550, 200, 
                            { 0, 0, 0, 0 }, 
                            { 255, 255, 255, 100 }, 
                            { 0, 0, 0, 50 });
    buttons.back()->setTextCenter(resourcesManager->getFont("cocktail_italic_shadow"),
                            "START",
                            200, 1,
                            BLACK,
                            BLACK,
                            BLACK);
    buttons.push_back(std::unique_ptr<Button>(new Button()));
    buttons.back()->setBox(2120, 680, 700, 200, 
                            { 0, 0, 0, 0 }, 
                            { 255, 255, 255, 100 }, 
                            { 0, 0, 0, 50 });
    buttons.back()->setTextCenter(resourcesManager->getFont("cocktail_italic_shadow"),
                            "SETTING",
                            200, 1,
                            BLACK,
                            BLACK,
                            BLACK);
    buttons.push_back(std::unique_ptr<Button>(new Button()));
    buttons.back()->setBox(2245, 1280, 450, 200, 
                            { 0, 0, 0, 0 }, 
                            { 255, 255, 255, 100 }, 
                            { 0, 0, 0, 50 });
    buttons.back()->setTextCenter(resourcesManager->getFont("cocktail_italic_shadow"),
                            "QUIT",
                            200, 1,
                            BLACK,
                            BLACK,
                            BLACK);
    buttons.push_back(std::unique_ptr<Button>(new Button()));
    buttons.back()->setBox(2000, 980, 960, 200, 
                            { 0, 0, 0, 0 }, 
                            { 255, 255, 255, 100 }, 
                            { 0, 0, 0, 50 });
    buttons.back()->setTextCenter(resourcesManager->getFont("cocktail_italic_shadow"),
                            "HIGH SCORE",
                            200, 1,
                            BLACK,
                            BLACK,
                            BLACK);
    setInputFunction(InputSupport::MOUSE_LEFT, InputSupport::RELEASED, [this]() {
        for(auto &button : buttons) {
            if(button->isTouch()) {
                if (button->getText() == "START")
                    state = Scenes::NEWGAME;
                else if (button->getText() == "SETTING")
                    state = Scenes::SETTING;
                else if (button->getText() == "QUIT")
                    state = Scenes::QUIT;
                else if (button->getText() == "HIGH SCORE")
                    state = Scenes::HIGHSCORE;
                break;
            }
        }
    });
}

void UiSceneMenu::eventScene() {
    for(int i = 0; i < buttons.size(); i++) {
        if (buttons[i]->isTouch()) {
            buttons[i]->setConer(true);
        } else {
            buttons[i]->setConer(false);
        }
    }
}

void UiSceneMenu::draw() {
    ClearBackground({ 127, 171, 169, 255 });
    for(auto &button : buttons)
        button->draw();
    DrawTextureEx(resourcesManager->getTexture("restaurant"), { 0, 200 }, 0, 2.6, WHITE);
}