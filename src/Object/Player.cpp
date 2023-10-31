#include "Player.hpp"

Player::Player() {
    
}

Player::~Player() {
    
}

void Player::draw() {
    DrawModel(model, position, scale, WHITE);
}

void Player::update() {
    if (anim) {
        UpdateModelAnimation(model, anim[animCurFrame++], animCurFrame);
        if (animCurFrame >= animMaxFrame) {
            animCurFrame = 0;
        }
    }
}

void Player::moveDirection(Direction direction) {
    rotate(Y, (direction - curDirection) * DEG2RAD);
    switch (direction) {
        case UP:
            position.z -= speed;
            break;
        case DOWN:
            position.z += speed;
            break;
        case LEFT:
            position.x -= speed;
            break;
        case RIGHT:
            position.x += speed;
            break;
    }
    curDirection = direction;
    update();
}

void Player::setSpeed(float speed) {
    this->speed = speed;
}