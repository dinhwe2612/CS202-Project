#pragma once

#include "raylib-cpp.hpp"

#include <Object/object.hpp>
#include "../Object/Movable/MovableObject.hpp"
#include "../Object/Movable/Player.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include <dirent.h>

namespace InputObject {
    enum Init {
        MODEL,
        POSITION,
        SPEED,
        SCALE,
        COLLISION,
        ACTIVATE,
        TYPE
    };
    void input(std::string path, Object *&object);
    void input(std::string pathToDirectory, std::vector<std::shared_ptr<Object>> &objects);
    
}