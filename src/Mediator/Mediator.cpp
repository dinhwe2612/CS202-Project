#include "Mediator.hpp"

ObjectMediator::ObjectMediator(std::vector<std::shared_ptr<Object>> &objects) {
    for(auto &object : objects) {
        this->objects.push_back(object);
    }
}

void ObjectMediator::do_pick() {
    Player *player = dynamic_cast<Player *>(objects.back().get());
    for(auto &object : objects) {
        std::string nameObject = object->getName();
        if (nameObject.size() > 5 && nameObject.substr(0, 5) == "crate") {
            Object3D *object3d = dynamic_cast<Object3D *>(object.get());
            if (CheckCollisionPointRec(player->pointInteract(), object3d->getCollisionBox())) {
                if (player->pickUpObject(nameObject.substr(6, (int)nameObject.size() - 1))) {
                    break;
                }
            }
        }
        if (object->getType() == ObjectType::CONTAINER) {
            Container *objectContainer = dynamic_cast<Container *>(object.get());
            if (CheckCollisionPointRec(player->pointInteract(), objectContainer->getCollisionBox())) {
                if (!player->isPicking() && objectContainer->isPlaceObjectOn()) {
                    std::cout << objectContainer->getName() << '\n';
                    player->pickUpObject(objectContainer->getName());
                    objectContainer->removeObject();
                    break;
                }
            }
        }
    }
}

void ObjectMediator::do_drop() {
    Player *player = dynamic_cast<Player *>(objects.back().get());
    for(auto &object : objects) {
        std::string nameObject = object->getName();
        if (object->getType() == ObjectType::CONTAINER) {
            Container *objectContainer = dynamic_cast<Container *>(object.get());
            if (CheckCollisionPointRec(player->pointInteract(), objectContainer->getCollisionBox())) {
                if (player->isPicking() && !objectContainer->isPlaceObjectOn()) {
                    objectContainer->placeObjectOn(player->pickableObject);
                    player->dropObject();
                    break;
                }
            }
        }
        if (nameObject == "trash") {
            Object3D *object3d = dynamic_cast<Object3D *>(object.get());
            if (CheckCollisionPointRec(player->pointInteract(), object3d->getCollisionBox())) {
                if (player->dropObject()) {
                    break;
                }
            }
        }
    }
}

void ObjectMediator::do_cut_cook() {
    Player *player = dynamic_cast<Player *>(objects.back().get());
    for(auto &object : objects) {
        if ()
    }
}

void ObjectMediator::notify(std::vector<std::string> messages) {
    if (messages[0] == "pick") {
        do_pick();
    }
    if (messages[0] == "drop") {
        do_drop();
    }
    if (messages[0] == "cut_cook") {

    }
}