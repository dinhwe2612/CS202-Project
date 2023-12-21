#pragma once

#include "UiScene.hpp"

class UiScenePauseGame : public UiScene {
private:
public:
    UiScenePauseGame();
    void eventScene() override;
    void draw() override;
};