#include "Gif.hpp"

Gif::Gif(std::string path, int frameDelay) {
    image = LoadImageAnim(path.c_str(), &animFrames);
    texture = LoadTextureFromImage(image);
    this->frameDelay = frameDelay;
    setScale(1);
}

Gif::~Gif() {
    UnloadImage(image);
    UnloadTexture(texture);
}

void Gif::draw() {
    DrawTextureEx(texture, getPosition(), 0, getScale(), WHITE);
}

void Gif::update() {
    frameCounter++;
    if (frameCounter >= frameDelay) {
        currentAnimFrame++;
        if (currentAnimFrame >= animFrames) currentAnimFrame = 0;
        nextFrameDataOffset = image.width*image.height*4*currentAnimFrame;
        UpdateTexture(texture, ((unsigned char *)image.data) + nextFrameDataOffset);
        frameCounter = 0;
    }
}