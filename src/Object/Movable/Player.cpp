#include "Player.hpp"

Player::Player() : MovableObject() {
    setModel(resourcesManager->getModel("player"));
}

Player::~Player() {
    
}

void Player::draw() {
    MovableObject::draw();
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
        case Direction::UL:
            return { area.x - distance, area.y - distance };
        case Direction::UR:
            return { area.x + area.width + distance, area.y - distance };
        case Direction::DL:
            return { area.x - distance, area.y + area.height + distance };
        case Direction::DR:
            return { area.x + area.width + distance, area.y + area.height + distance };
    }
}

bool Player::isPicking() {
    if (pickableObject) return true;
    return false;
}

bool Player::pickUpObject(std::string name) {
    if (pickableObject) return false;
    pickableObject = new PickableObject(name);
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