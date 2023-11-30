#pragma once

#include "MovableObject.hpp"
#include <object.hpp>
#include "../Other/InputObject.hpp"

#include <iostream>

// Player class for loading, drawing, and updating the player
enum HoldingObjectType {
    NONE,
    INGREDIENT,
};
class Player : public MovableObject {
private:
    HoldingObjectType holdingObjectType = HoldingObjectType::NONE;
    Object* holdingObject3D = nullptr;
public:
    Player();
    ~Player();
    void draw() override;
    HoldingObjectType getHoldingObjectType() const;
    bool pickUpObject(std::string name); // return true if pick up object
    bool dropObject(); // return true if drop object
    Vector2 pointInteract() const;
};