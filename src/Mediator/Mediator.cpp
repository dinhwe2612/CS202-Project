#include "Mediator.hpp"

ObjectMediator::ObjectMediator(std::vector<Object3D*> objects, std::vector<Object3D*> players) {
    this->objects = objects;
    this->players = players;
}

void ObjectMediator::notify(std::string event) {

}