#include "MovableObject.hpp"

MovableObject::MovableObject() : Object3D() {
    
}

void MovableObject::setSpeed(float speed) {
    this->speed = speed;
}

float MovableObject::getSpeed() const {
    return speed;
}

void MovableObject::moveDirection(Direction direction) {
    rotate(Y, (direction - getCurDirection()) * DEG2RAD);
    float sqrt_speed = sqrt(speed);
    switch (direction) {
        case UP:
            move({ 0, 0, -speed });
            break;
        case DOWN:
            move({ 0, 0, speed });
            break;
        case LEFT:
            move({ -speed, 0, 0 });
            break;
        case RIGHT:
            move({ speed, 0, 0 });
            break;
        case UL:
            move({ -sqrt_speed, 0, -sqrt_speed });
            break;
        case UR:
            move({ sqrt_speed, 0, -sqrt_speed });
            break;
        case DL:
            move({ -sqrt_speed, 0, sqrt_speed });
            break;
        case DR:
            move({ sqrt_speed, 0, sqrt_speed });
            break;
    }
    setCurrentDirection(direction);
}

bool checkBounding(Rectangle A, Rectangle B) {
    // return true if A is inside B
    if (A.x >= B.x && A.y >= B.y && A.x + A.width <= B.x + B.width && A.y + A.height <= B.y + B.height) return true;
    return false;
}

bool checkIntersection(Rectangle A, Rectangle B) {
    // return true if the rectangles overlap each other
    if (checkBounding(A, B) || checkBounding(B, A)) return false;
    Vector2 leftdownA = {A.x, A.y + A.height};
    Vector2 rightupA = {A.x + A.width, A.y};
    Vector2 leftdownB = {B.x, B.y + B.height};
    Vector2 rightupB = {B.x + B.width, B.y};
    // check Ox
    if (leftdownA.x > rightupB.x || leftdownB.x > rightupA.x) return false;
    // check Oy
    if (leftdownA.y < rightupB.y || leftdownB.y < rightupA.y) return false;
    return true;
}

bool MovableObject::isColliding(Direction direction, std::vector<std::shared_ptr<Object>> &objects) {
    Rectangle newCollisionBox = getCollisionBox();
    switch (direction) {
        case Direction::UP:
            newCollisionBox.y -= getSpeed();
            break;
        case Direction::DOWN:
            newCollisionBox.y += getSpeed();
            break;
        case Direction::LEFT:
            newCollisionBox.x -= getSpeed();
            break;
        case Direction::RIGHT:
            newCollisionBox.x += getSpeed();
            break;
    }
    for (auto &object : objects) {
        if (object->getType() == ObjectType::PLAYER) continue;
        if (object->getType() == ObjectType::INPUTBOX) continue;
        if (object->getType() == ObjectType::BUTTON) continue;
        Object3D *object3D = dynamic_cast<Object3D*>(object.get());
        if (object3D->isCollisionable() == false) continue;
        if (checkIntersection(newCollisionBox, object3D->getCollisionBox())) {
            return true;
        }
    }
    return false;
}