#pragma once
#include "raylib-cpp.hpp"

// interface for scene
class IScence {
private:

public: 
    virtual void draw() = 0;
};