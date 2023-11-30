#pragma once
#include "raylib-cpp.hpp"

// interface for scene
class IScene {
private:

public: 
    virtual void draw() = 0;
};