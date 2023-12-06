#include "Player.hpp"

Player::Player() {
    
}

Player::~Player() {
    
}

void Player::draw() {
    DrawModel(getModel(), getPosition(), getScale(), WHITE);
    if (isPicking()) pickableObject->draw(pointInteract());
}

Vector2 Player::pointInteract() const {
    Rectangle area = getCollisionBox();
    float middle_x = area.x + area.width / 2;
    float middle_y = area.y + area.height / 2;
    float distance = 0.5;
    switch (getCurDirection()) {
    case Direction::UP:
        return { middle_x, area.y - distance };
    case Direction::DOWN:
        return { middle_x, area.y + area.height + distance };
    case Direction::LEFT:
        return { area.x - distance, middle_y };
    case Direction::RIGHT:
        return { area.x + area.width + distance, middle_y };
    }
}

bool Player::isPicking() {
    if (pickableObject) return true;
    return false;
}

bool Player::pickUpObject(std::string name) {
    if (pickableObject) return false;
    Object3D *object;
    InputObject::input(pickables.at(name), object);
    pickableObject = dynamic_cast<PickableObject *>(object);
    return true;
}

bool Player::dropObject() {
    if (pickableObject) {
        delete pickableObject;
        pickableObject = nullptr;
        return true;
    }
    return false;
}