#pragma once

#include "MovableObject.hpp"
#include <object.hpp>
#include "../Other/InputObject.hpp"
#include "../Object/Pickable/PickableObject.hpp"

#include <iostream>
#include <unordered_map>

// Player class for loading, drawing, and updating the player
class Player : public MovableObject {
private:
    PickableObject *pickableObject = nullptr;
public:
    Player();
    ~Player();
    void draw() override;
    bool isPicking();
    bool pickUpObject(std::string name); // return true if pick up object
    bool dropObject(); // return true if drop object
    Vector2 pointInteract() const;
};