#pragma once
#include "raylib-cpp.hpp"

enum Scenes {
    DEFAULT = -1,
    MENU,
    SETTING,
    HIGHSCORE,
    NEWGAME,
    GAME,
    PAUSE,
    ENDGAME,
    QUIT
};
// interface for scene
class IScene {
private:

public: 
    virtual Scenes run() = 0;
};