#pragma once

#include "raylib-cpp.hpp"
#include <object.hpp>

#include <vector>
#include <memory>
#include <iostream>

class MovableObject : public Object3D {
private: 
    float speed;
public:
    void setSpeed(float speed);
    float getSpeed() const;
    void moveDirection(Direction direction);
    bool isColliding(Direction direction, std::vector<std::shared_ptr<Object>> &objects);
};
