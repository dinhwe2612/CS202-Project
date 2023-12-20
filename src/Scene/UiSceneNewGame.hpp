#pragma once

#include "UiScene.hpp"

class UiSceneNewGame : public UiScene {
private:
public:
    UiSceneNewGame();
    void eventScene() override;
    void draw() override;
};