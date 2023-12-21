#pragma once

#include "UiScene.hpp"

class UiSceneNewGame : public UiScene {
private:
    std::vector<std::string> names;
    int curMap;
    std::vector<Color> colors;
    
    int animFrames = 0;
    unsigned int nextFrameDataOffset = 0;  // Current byte offset to next frame in image.data
    int currentAnimFrame = 0;       // Current animation frame to load and draw
    int frameDelay = 8;             // Frame delay to switch between animation frames
    int frameCounter = 0;           // General frames counter
    Image burgerImage;
    Texture2D burger;
public:
    UiSceneNewGame();
    void eventScene() override;
    void draw() override;
    void drawBurger();
};