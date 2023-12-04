#include "Mediator.hpp"

ObjectMediator::ObjectMediator(std::vector<std::shared_ptr<Object>> &objects) {
    for(auto &object : objects) {
        this->objects.push_back(object);
    }
}

void ObjectMediator::E_Pressed() {
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

void ObjectMediator::notify(std::vector<std::string> messages) {
    if (messages[0] == "E_Pressed") {
        E_Pressed();
    }
}