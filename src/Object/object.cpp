#include <object.hpp>
#include <iostream>

Object::Object() {
    resourcesManager = ResourcesManager::getInstance();
}

Object::~Object() {
    
}

void Object::setType(std::string string_type) {
    type = ObjectType::listOfTypes[string_type];
}

ObjectType::Type Object::getType() const {
    return type;
}

void Object::setActivate(bool activate) {
    this->activate = activate;
}

void Object::setHovered(bool hovered) {
    this->hovered = hovered;
}

void Object::setPressed(bool pressed) {
    this->pressed = pressed;
}

bool Object::isActivate() const {
    return activate;
}

bool Object::isHovered() const {
    return hovered;
}

bool Object::isPressed() const {
    return pressed;
}

void Object::setMediator(IMediator *mediator) {
    this->mediator = mediator;
}

void Object::setName(std::string name) {
    this->name = name;
}

std::string Object::getName() const {
    return name;
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
Object3D::Object3D() : Object() {
    
}

Object3D::Object3D(const std::string path) {
    setModel(path);
}

Object3D::~Object3D() {
    
}

void Object3D::draw() {
    if (isModelLoaded()) DrawModel(model, position, scale, color);
    else {
        ResourcesManager* resourcesManager = ResourcesManager::getInstance();
        if (resourcesManager->hasModel(name)) {
            DrawModel(resourcesManager->getModel(name), position, scale, color);
        }
    }
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
    collisionBox.x += offset.x;
    collisionBox.y += offset.z;
}

Vector3 Object3D::getPosition() const {
    return position;
}

void Object3D::setPosition(const Vector3 &position) {
    this->position = position;
}

void Object3D::setModel(const Model &model) {
    this->model = model;
    modelLoaded = true;
}

void Object3D::setModel(const std::string path) {
    model = LoadModel(path.c_str());

    anim = LoadModelAnimations(path.c_str(), &animMaxFrame);
    modelLoaded = true;
}

void Object3D::setScale(float scale) {
    this->scale = scale;
}

float Object3D::getScale() const {
    return scale;
}

void Object3D::setCurrentDirection(Direction curDirection) {
    this->curDirection = curDirection;
}

void Object3D::setColor(Color color) {
    this->color = color;
}

void Object3D::incScale(float add) {
    scale += add;
}

Model Object3D::getModel() const {
    return model;
}

void Object3D::setCollisionable(Rectangle collisionBox) {
    this->collisionBox = collisionBox;
    collisionable = true;
}

Rectangle Object3D::getCollisionBox() const {
    return collisionBox;
}

bool Object3D::isCollisionable() const {
    return collisionable;
}

bool Object3D::isModelLoaded() const {
    return modelLoaded;
}

Direction Object3D::getCurDirection() const {
    return curDirection;
}