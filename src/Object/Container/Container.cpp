#include "Container.hpp"

Container::Container() {
    
}

Container::~Container() {
    
}

bool Container::placeObjectOn(PickableObject *object) {
    placeObject = true;
    setModel(object->getModel());
    setScale(object->getScale());
    setName(object->getName());
    setPosition(object->getPosition());
    return true;
}

bool Container::removeObject() {
    placeObject = false;
    UnloadModel(model);
    return true;
}

bool Container::isPlaceObjectOn() {
    return placeObject;
}

void Container::draw() {
    if (isPlaceObjectOn()) {
        Rectangle area = getCollisionBox();
        float x = area.x + area.width / 2;
        float y = area.y + area.height / 2;
        DrawModel(model, { x, getPosition().y, y }, getScale(), WHITE);
    }
}