#pragma once
#include "AScene.hpp"
#include "Object.hpp"

class UiScene : public AScene {
private:
    int state;
public:
    UiScene();
    ~UiScene();
    virtual void eventScene() = 0;
    Scenes run();
    virtual Scenes endScene() = 0;
};