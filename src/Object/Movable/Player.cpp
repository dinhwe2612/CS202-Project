#include "Player.hpp"

Player::Player() {
    
}

Player::~Player() {
    
}

void Player::draw() {
    DrawModel(getModel(), getPosition(), getScale(), WHITE);
    if (getHoldingObjectType() != HoldingObjectType::NONE) {
        holdingObject3D->draw();
    }
}

HoldingObjectType Player::getHoldingObjectType() const {
    return holdingObjectType;
}

bool Player::pickUpObject(std::string name) {
    if (holdingObjectType != HoldingObjectType::NONE) return false;
    if (name.substr(0, 9) != "ingredient") {
        InputObject::input("../resources/Object/ingredient_" + name + ".txt", holdingObject3D);
        holdingObjectType = HoldingObjectType::INGREDIENT;
    }
    std::cout << name << std::endl;
}

bool Player::dropObject() {

}

Vector2 Player::pointInteract() const {
    Rectangle area = getCollisionBox();
    float middle_x = area.x + area.width / 2;
    float middle_y = area.y + area.height / 2;
    switch (getCurDirection()) {
    case Direction::UP:
        return { middle_x, area.y - 1 };
    case Direction::DOWN:
        return { middle_x, area.y + area.height + 1 };
    case Direction::LEFT:
        return { area.x - 1, middle_y };
    case Direction::RIGHT:
        return { area.x + area.width + 1, middle_y };
    }
}