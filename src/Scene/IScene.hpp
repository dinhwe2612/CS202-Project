#pragma once
#include "raylib-cpp.hpp"

enum Scenes {
    DEFAULT = -1,
    MENU,
    GAME,
    QUIT
};
// interface for scene
class IScene {
private:

public: 
    virtual Scenes run() = 0;
};