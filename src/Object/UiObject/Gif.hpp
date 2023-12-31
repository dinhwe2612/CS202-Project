#pragma once

#include "raylib-cpp.hpp"

#include "object.hpp"

class Gif : public Object2D {
private:
    Image image;
    Texture2D texture;
    int animFrames = 0;
    unsigned int nextFrameDataOffset = 0;  // Current byte offset to next frame in image.data
    int currentAnimFrame = 0;       // Current animation frame to load and draw
    int frameDelay = 8;             // Frame delay to switch between animation frames
    int frameCounter = 0;           // General frames counter
public:
    Gif(std::string path, int frameDelay);
    ~Gif();
    void draw();
    void update();
};