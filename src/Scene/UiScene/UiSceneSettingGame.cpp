#include "UiSceneSettingGame.hpp"

UiSceneSettingGame::UiSceneSettingGame() : UiScene() {
    buttons.push_back(std::unique_ptr<Button>(new Button()));
    for(int i = 1; i <= 8; ++i) {
        buttons.push_back(std::unique_ptr<Button>(new BoolButton()));
    }
    buttons.push_back(std::unique_ptr<Button>(new Button()));
    buttons[0]->setBox(44.9, 52.8, 175.9, 175.9, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 });
    buttons[1]->setBox(1141.6, 564.9, 166.5, 166.5, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 100 });
    buttons[2]->setBox(1141.6, 797.2, 166.5, 166.5,
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 50 }, 
                        { 0, 0, 0, 100 });
    buttons[3]->setBox(1141.6, 1037.5, 166.5, 166.5,
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 50 }, 
                        { 0, 0, 0, 100 });
    buttons[4]->setBox(1141.6, 1291.9, 166.5, 166.5,
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 50 }, 
                        { 0, 0, 0, 100 });
    buttons[5]->setBox(2086.4, 564.9, 166.5, 166.5,
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 50 }, 
                        { 0, 0, 0, 100 });
    buttons[6]->setBox(2086.4, 816.7, 166.5, 166.5,
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 50 }, 
                        { 0, 0, 0, 100 });
    buttons[7]->setBox(2086.4, 1050.6, 166.5, 166.5,
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 50 }, 
                        { 0, 0, 0, 100 });
    buttons[8]->setBox(2086.4, 1291.9, 166.5, 166.5,
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 50 }, 
                        { 0, 0, 0, 100 });
    setInputFunction(InputSupport::MOUSE_LEFT, InputSupport::RELEASED, [this]() {
        for(int i = 2; i <= 8; ++i) {
            if (((BoolButton*)buttons[i].get())->getIsOn()) {
                return;
            }
        }
        if (buttons[0]->isTouch()) {
            state = Scenes::MENU;
        } else if (buttons[9]->isTouch()) {
            state = Scenes::MENU;
        } 
        for(int i = 1; i <= 8; ++i) {
            if (buttons[i]->isTouch()) {
                ((BoolButton*)buttons[i].get())->toggle();
                if (i == 1) {
                    Setting::getInstance()->toggleMute();
                }
            }
        }
    });
    Setting *setting = Setting::getInstance();
    buttons[2]->setTextCenter(GetFontDefault(), keyToText.at(setting->getCutCook()).c_str(), 50, 0, BLACK, BLACK, BLACK);
    buttons[3]->setTextCenter(GetFontDefault(), keyToText.at(setting->getPickUp()).c_str(), 50, 0, BLACK, BLACK, BLACK);
    buttons[4]->setTextCenter(GetFontDefault(), keyToText.at(setting->getDrop()).c_str(), 50, 0, BLACK, BLACK, BLACK);
    buttons[5]->setTextCenter(GetFontDefault(), keyToText.at(setting->getMoveUp()).c_str(), 50, 0, BLACK, BLACK, BLACK);
    buttons[6]->setTextCenter(GetFontDefault(), keyToText.at(setting->getMoveDown()).c_str(), 50, 0, BLACK, BLACK, BLACK);
    buttons[7]->setTextCenter(GetFontDefault(), keyToText.at(setting->getMoveLeft()).c_str(), 50, 0, BLACK, BLACK, BLACK);
    buttons[8]->setTextCenter(GetFontDefault(), keyToText.at(setting->getMoveRight()).c_str(), 50, 0, BLACK, BLACK, BLACK);
}

void UiSceneSettingGame::eventScene() {
    Setting *setting = Setting::getInstance();
    auto in = inputSp.getKeysPressed();
    for(int i = 2; i <= 8; ++i) {
        if (((BoolButton*)buttons[i].get())->getIsOn()) {
            std::string text = "";
            for(auto& key : in) {
                if (keyToText.find(key) != keyToText.end() && setting->set(i, key)) {
                    text = keyToText.at(key);
                    break;
                }
            }
            
            if (text != "") {
                buttons[i]->setTextCenter(GetFontDefault(), text.c_str(), 50, 0, BLACK, BLACK, BLACK);
                ((BoolButton*)buttons[i].get())->toggle();
            }
            break;
        }
    }
}

void UiSceneSettingGame::draw() {
    DrawTexture(resourcesManager->getTexture("SceneSettingGame"), 0, 0, WHITE);
    DrawTexture(resourcesManager->getTexture("arrowBack"), 0, 0, buttons[0]->getState() == Button::CLICKED ? (Color){ 255, 255, 255, 100 } : WHITE);
    DrawTexture(resourcesManager->getTexture("tick"), 0, 0, ((BoolButton*)buttons[1].get())->getIsOn() ? (Color){ 255, 255, 255, 0 } : WHITE);

    for(auto& button : buttons) {
        button->draw();
    }
}