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
            move({ -speed, 0, -speed });
            break;
        case UR:
            move({ speed, 0, -speed });
            break;
        case DL:
            move({ -speed, 0, speed });
            break;
        case DR:
            move({ speed, 0, speed });
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
    float speed = getSpeed();
    float sqrt_speed = sqrt(speed);
    switch (direction) {
        case Direction::UP:
            newCollisionBox.y -= speed;
            break;
        case Direction::DOWN:
            newCollisionBox.y += speed;
            break;
        case Direction::LEFT:
            newCollisionBox.x -= speed;
            break;
        case Direction::RIGHT:
            newCollisionBox.x += speed;
            break;
        case Direction::UL:
            newCollisionBox.x -= sqrt_speed;
            newCollisionBox.y -= sqrt_speed;
            break;
        case Direction::UR:
            newCollisionBox.x += sqrt_speed;
            newCollisionBox.y -= sqrt_speed;
            break;
        case Direction::DL:
            newCollisionBox.x -= sqrt_speed;
            newCollisionBox.y += sqrt_speed;
            break;
        case Direction::DR:
            newCollisionBox.x += sqrt_speed;
            newCollisionBox.y += sqrt_speed;
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