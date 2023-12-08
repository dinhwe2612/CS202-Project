#include "Container.hpp"

Container::Container() :Object3D() {
    
}

Container::~Container() {
    
}

bool Container::placeObjectOn(PickableObject *object) {
    placeObject = true;
    if (object->isModelLoaded()) setModel(object->getModel());
    setScale(object->getScale());
    setName(object->getName());
    setPosition(object->getPosition());
    return true;
}

bool Container::removeObject() {
    placeObject = false;
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
        if (resourcesManager->hasModel(name)) {
            DrawModel(resourcesManager->getModel(name), { x, getPosition().y, y }, getScale(), WHITE);
        }
    }
}