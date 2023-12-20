#pragma once

#include "UiScene.hpp"

class UiSceneMenu : public UiScene {
private:
public:
    UiSceneMenu();
    void eventScene() override;
    Scenes endScene() override;
    void draw() override;
};