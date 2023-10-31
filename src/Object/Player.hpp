#pragma once
#include "object.hpp"

#include <iostream>

// Player class for loading, drawing, and updating the player
class Player : public Object3D {
private:
    float speed;
public:
    Player();
    ~Player();
    void draw();
    void update();
    void moveDirection(Direction direction);
    void setSpeed(float speed);
};