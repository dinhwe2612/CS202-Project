#include <object.hpp>
#include <iostream>

Object::Object() {
    
}

Object::~Object() {
    
}

void Object::draw() {
    
}

/////////////////////////////////
Object2D::Object2D() {
    
}

Object2D::~Object2D() {
    
}

void Object2D::draw() {
    
}

Vector2 Object2D::getPosition() const {
    return position;
}

void Object2D::setPosition(const Vector2 &position) {
    this->position = position;
}

/////////////////////////////////
Object3D::Object3D() {
    
}

Object3D::~Object3D() {
    
}

void Object3D::draw() {
    
}

void Object3D::rotate(Vector3 axis, float angle) {
    ownOx = Vector3RotateByAxisAngle(ownOx, axis, angle);
    ownOy = Vector3RotateByAxisAngle(ownOy, axis, angle);
    ownOz = Vector3RotateByAxisAngle(ownOz, axis, angle);
    axis.x = abs(axis.x);
    axis.y = abs(axis.y);
    axis.z = abs(axis.z);
    model.transform = MatrixMultiply(MatrixRotate(axis, angle), model.transform);
}

void Object3D::rotate(const Axis axis, float angle) {
    switch (axis) {
        case X:
            rotate(ownOx, angle);
            break;
        case Y:
            rotate(ownOy, angle);
            break;
        case Z:
            rotate(ownOz, angle);
            break;
    }
}

void Object3D::move(const Vector3 offset) {
    position = Vector3Add(position, offset);
}

Vector3 Object3D::getPosition() const {
    return position;
}

void Object3D::setPosition(const Vector3 &position) {
    this->position = position;
}

void Object3D::setModel(const Model &model) {
    this->model = model;
}

void Object3D::setModel(const std::string path) {
    model = LoadModel(path.c_str());

    anim = LoadModelAnimations(path.c_str(), &animMaxFrame);
}

void Object3D::setMediator(Mediator *mediator) {
    this->mediator = mediator;
}

void Object3D::setScale(float scale) {
    this->scale = scale;
}

void Object3D::setCurrentDirection(int curDirection) {
    this->curDirection = curDirection;
}