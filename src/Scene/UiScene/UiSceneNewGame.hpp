#pragma once

#include "UiScene.hpp"
#include "../Object/UiObject/Gif.hpp"
#include "../Application/Setting.hpp"

class UiSceneNewGame : public UiScene {
private:
    std::vector<std::string> names;
    int curMap;
    std::vector<Color> colors;
    std::vector<Color> colorScenes;
    std::vector<Vector2> posScenes;
    Gif *burgerGif;
    int tran = 0;
    void transitionMap(int &tran);
public:
    UiSceneNewGame();
    void eventScene() override;
    void draw() override;
    void drawBurger();
};