#include "PickableObject.hpp"

#include <iostream>

PickableObject::PickableObject() : Object3D() {
    
}

PickableObject::~PickableObject() {

}

void PickableObject::draw(Vector2 position) {
    DrawModel(getModel(), { position.x, getPosition().y, position.y }, getScale(), WHITE);
}