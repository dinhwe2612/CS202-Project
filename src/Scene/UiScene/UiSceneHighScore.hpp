#pragma once

#include "UiScene.hpp"

#include <fstream>

class UiSceneHighScore : public UiScene {
private:
    std::vector<int> highScore;
    std::vector<Rectangle> box;
public:
    UiSceneHighScore();
    void eventScene() override;
    void draw() override;
};
