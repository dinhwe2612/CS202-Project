#include "PickableObject.hpp"

#include <iostream>
#include <fstream>

PickableObject::PickableObject() : Object3D() {
    setPosition({ 0, 0.6, 0 });
}

PickableObject::PickableObject(std::string name) : Object3D() {
    std::string pathToFile = resourcesManager->pathPickableObject(name);
    if (pathToFile == "") {
        setName(name);
        setScale(1);
        setPosition({ 0, 0.6, 0 });
        return;
    }
    std::ifstream fin(pathToFile);
    std::string inst;
    while(fin >> inst) {
        if (inst == "NAME") {
            std::string name; fin >> name;
            setName(name);
        } else if (inst == "SCALE") {
            float scale; fin >> scale;
            setScale(scale);
        } else if (inst == "POSITION") {
            float x, y, z; fin >> x >> y >> z;
            setPosition({ x, y, z });
        } else if (inst == "ROTATE") {
            char axis; fin >> axis;
            float angle; fin >> angle;
            switch (axis) {
            case 'X':
                rotate(Axis::X, angle);
                break;
            case 'Y':
                rotate(Axis::Y, angle);
                break;
            case 'Z':
                rotate(Axis::Z, angle);
                break;
            }
        }
    }
    fin.close();
}

PickableObject::~PickableObject() {

}

void PickableObject::draw(Vector2 position) {
    if (isModelLoaded()) DrawModel(getModel(), { position.x, getPosition().y, position.y }, getScale(), WHITE);
    else {
        ResourcesManager* resourcesManager = ResourcesManager::getInstance();
        if (resourcesManager->hasModel(getName())) {
            DrawModel(resourcesManager->getModel(getName()), { position.x, getPosition().y, position.y }, getScale(), WHITE);
        }
    }
}