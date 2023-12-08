#include "Mediator.hpp"

ObjectMediator::ObjectMediator(std::vector<std::shared_ptr<Object>> &objects) {
    for(auto &object : objects) {
        this->objects.push_back(object);
    }
}

void ObjectMediator::do_pick() {
    Player *player = dynamic_cast<Player *>(objects.back().get());
    if (player->isPicking()) return;
    for(auto &object : objects) {
        std::string nameObject = object->getName();
        if (nameObject.size() > 5 && nameObject.substr(0, 5) == "crate") {
            Object3D *object3d = dynamic_cast<Object3D *>(object.get());
            if (CheckCollisionPointRec(player->pointInteract(), object3d->getCollisionBox())) {
                if (player->pickUpObject(nameObject.substr(6, (int)nameObject.size() - 1))) {

                }
                break;
            }
        }
        if (object->getType() == ObjectType::CONTAINER) {
            Container *objectContainer = dynamic_cast<Container *>(object.get());
            if (CheckCollisionPointRec(player->pointInteract(), objectContainer->getCollisionBox())) {
                if (objectContainer->isPlaceObjectOn()) {
                    player->pickUpObject(objectContainer->getName());
                    objectContainer->removeObject();
                }
                break;
            }
        }
        if (object->getType() == ObjectType::CUTTINGBOARD) {
            CuttingBoard *cuttingBoard = dynamic_cast<CuttingBoard *>(object.get());
            if (!cuttingBoard->isPlaceObjectOn()) continue;
            if (CheckCollisionPointRec(player->pointInteract(), cuttingBoard->getCollisionBox())) {
                if (player->pickUpObject(cuttingBoard->getName())) {
                    cuttingBoard->removeObject();
                }
                break;
            }
        }
        if (object->getType() == ObjectType::FOODCOOKER) {
            FoodCooker *foodCooker = dynamic_cast<FoodCooker *>(object.get());
            if (!foodCooker->isPlaceObjectOn()) continue;
            if (CheckCollisionPointRec(player->pointInteract(), foodCooker->getCollisionBox())) {
                if (player->pickUpObject(foodCooker->getName())) {
                    foodCooker->removeObject();
                }
                break;
            }
        }
    }
}

void ObjectMediator::do_drop() {
    Player *player = dynamic_cast<Player *>(objects.back().get());
    if (!player->isPicking()) return;
    for(auto &object : objects) {
        std::string nameObject = object->getName();
        if (object->getType() == ObjectType::CONTAINER) {
            Container *objectContainer = dynamic_cast<Container *>(object.get());
            if (CheckCollisionPointRec(player->pointInteract(), objectContainer->getCollisionBox())) {
                if (!objectContainer->isPlaceObjectOn()) {
                    objectContainer->placeObjectOn(player->pickableObject);
                    player->dropObject();
                }
                break;
            }
        }
        if (nameObject == "trash") {
            Object3D *object3d = dynamic_cast<Object3D *>(object.get());
            if (CheckCollisionPointRec(player->pointInteract(), object3d->getCollisionBox())) {
                if (player->dropObject()) {

                }
                break;
            }
        }
        if (object->getType() == ObjectType::CUTTINGBOARD) {
            CuttingBoard *cuttingBoard = dynamic_cast<CuttingBoard *>(object.get());
            if (CheckCollisionPointRec(player->pointInteract(), cuttingBoard->getCollisionBox())) {
                if (cuttingBoard->placeObjectOn(player->pickableObject)) {
                    player->dropObject();
                }
                break;
            }
        }
        if (object->getType() == ObjectType::FOODCOOKER) {
            FoodCooker *foodCooker = dynamic_cast<FoodCooker *>(object.get());
            if (CheckCollisionPointRec(player->pointInteract(), foodCooker->getCollisionBox())) {
                if (foodCooker->placeObjectOn(player->pickableObject)) {
                    player->dropObject();
                }
                break;
            }
        }
    }
}

void ObjectMediator::do_cut_cook() {
    Player *player = dynamic_cast<Player *>(objects.back().get());
    if (player->isPicking()) return;
    for(auto &object : objects) {
        if (object->getType() == ObjectType::CUTTINGBOARD) {
            CuttingBoard *cuttingBoard = dynamic_cast<CuttingBoard *>(object.get());
            if (CheckCollisionPointRec(player->pointInteract(), cuttingBoard->getCollisionBox())) {
                if (cuttingBoard->isPlaceObjectOn()) {
                    cuttingBoard->cut();
                }
                break;
            }
        }
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
        do_cut_cook();
    }
}