#pragma once
#include "raylib-cpp.hpp"

#include "object.hpp"
#include "../Scene/SceneGame.hpp"
#include "../Scene/UiSceneMenu.hpp"

class Application {
private:
    Scenes state;
    IScene *curScene;
public:
    Application();
    ~Application();
    void run();
};