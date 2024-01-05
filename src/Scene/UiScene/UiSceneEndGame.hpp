#pragma once 

#include "UiScene.hpp"
#include "../Object/UiObject/Gif.hpp"

#include <fstream>

class UiSceneEndGame : public UiScene {
private:
    Gif *congrats;
    Gif *balloon;
    Gif *firework;
    Button *button;
public:
    UiSceneEndGame();
    void eventScene() override;
    void draw() override;
};