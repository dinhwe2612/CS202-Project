#pragma once

#include "UiScene.hpp"
#include "../Object/UiObject/Gif.hpp"

class UiSceneNewGame : public UiScene {
private:
    std::vector<std::string> names;
    int curMap;
    std::vector<Color> colors;
    Gif *burgerGif;
public:
    UiSceneNewGame();
    void eventScene() override;
    void draw() override;
    void drawBurger();
};