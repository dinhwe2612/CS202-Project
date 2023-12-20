#include "ObjectManager.hpp"

ObjectManager::ObjectManager(std::string path) {
    resourcesManager = ResourcesManager::getInstance();
    InputObject::input(path, objects);
}

void ObjectManager::update() {
    for(auto &object : objects) {
        if (object->getType() == ObjectType::TASKMANAGER) {
            TaskManager *taskManager = dynamic_cast<TaskManager *>(object.get());
            taskManager->update();
        }
    }
    movePlayer();
}

void ObjectManager::pick() {
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
        if (object->getType() == ObjectType::GASSTOVE) {
            GasStove *gasStove = dynamic_cast<GasStove *>(object.get());
            if (!gasStove->isPlaceObjectOn()) continue;
            if (CheckCollisionPointRec(player->pointInteract(), gasStove->getCollisionBox())) {
                if (player->pickUpObject(gasStove->getName())) {
                    gasStove->removeObject();
                }
                break;
            }
        }
    }
}

void ObjectManager::drop() {
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
        if (object->getType() == ObjectType::GASSTOVE) {
            GasStove *gasStove = dynamic_cast<GasStove *>(object.get());
            if (CheckCollisionPointRec(player->pointInteract(), gasStove->getCollisionBox())) {
                if (gasStove->placeObjectOn(player->pickableObject)) {
                    player->dropObject();
                }
                break;
            }
        }
    }
}

void ObjectManager::cut_cook() {
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
        if (object->getType() == ObjectType::GASSTOVE) {
            GasStove *gasStove = dynamic_cast<GasStove *>(object.get());
            if (CheckCollisionPointRec(player->pointInteract(), gasStove->getCollisionBox())) {
                if (gasStove->isPlaceObjectOn()) {
                    gasStove->cook();
                }
                break;
            }
        }
    }
}

void ObjectManager::movePlayer(Direction direction) {
    if (direction == Direction::UP) {
        directionPlayer.push_back('U');
    } else if (direction == Direction::DOWN) {
        directionPlayer.push_back('D');
    } else if (direction == Direction::LEFT) {
        directionPlayer.push_back('L');
    } else if (direction == Direction::RIGHT) {
        directionPlayer.push_back('R');
    }
}

void ObjectManager::movePlayer() {
    if (directionPlayer.empty()) return;
    sort(directionPlayer.begin(), directionPlayer.end());
    Direction curDirection;
    int sz = directionPlayer.size();
    if (std::find(directionPlayer.begin(), directionPlayer.end(), 'U') != directionPlayer.end() && 
        std::find(directionPlayer.begin(), directionPlayer.end(), 'D') != directionPlayer.end()) {
        directionPlayer.erase(std::remove(directionPlayer.begin(), directionPlayer.end(), 'U'), directionPlayer.end());
        directionPlayer.erase(std::remove(directionPlayer.begin(), directionPlayer.end(), 'D'), directionPlayer.end());
    }
    if (std::find(directionPlayer.begin(), directionPlayer.end(), 'L') != directionPlayer.end() && 
        std::find(directionPlayer.begin(), directionPlayer.end(), 'R') != directionPlayer.end()) {
        directionPlayer.erase(std::remove(directionPlayer.begin(), directionPlayer.end(), 'L'), directionPlayer.end());
        directionPlayer.erase(std::remove(directionPlayer.begin(), directionPlayer.end(), 'R'), directionPlayer.end());
    }
    if (directionPlayer.empty()) {
        return;
    }
    std::string directionStr(directionPlayer.begin(), directionPlayer.end());
    if (directionStr == "LU") {
        curDirection = Direction::UL;
    } else if (directionStr == "RU") {
        curDirection = Direction::UR;
    } else if (directionStr == "DL") {
        curDirection = Direction::DL;
    } else if (directionStr == "DR") {
        curDirection = Direction::DR;
    } else if (directionStr == "U") {
        curDirection = Direction::UP;
    } else if (directionStr == "D") {
        curDirection = Direction::DOWN;
    } else if (directionStr == "L") {
        curDirection = Direction::LEFT;
    } else if (directionStr == "R") {
        curDirection = Direction::RIGHT;
    } else {
        curDirection = Direction::DOWN;
    }
    
    Player *player = dynamic_cast<Player *>(objects.back().get());
    if (player->isColliding(curDirection, objects) == false) {
        player->moveDirection(curDirection); 
    } else {
        player->rotate(Y, (curDirection - player->getCurDirection()) * DEG2RAD);
        player->setCurrentDirection(curDirection);
    }
    directionPlayer.clear();
}

bool ObjectManager::submitTask() {
    Player *player = dynamic_cast<Player *>(objects.back().get());
    if (!player->isPicking()) return false;
    for(auto &object : objects) {
        if (object->getType() == ObjectType::TASKMANAGER) {
            TaskManager *taskManager = dynamic_cast<TaskManager *>(object.get());
            if (!CheckCollisionPointRec(player->pointInteract(), taskManager->getCollisionBox())) continue;
            if (taskManager->submitTask("task_" + player->pickableObject->getName())) {
                player->dropObject();
                return true;
            }
        }
    }
    return false;
}

void ObjectManager::draw_tasks() {
    for(auto &object : objects) {
        if (object->getType() == ObjectType::TASKMANAGER) {
            TaskManager *taskManager = dynamic_cast<TaskManager *>(object.get());
            taskManager->draw();
            return;
        }
    }
}

void ObjectManager::draw() {
    for (auto &object : objects) {
        if (object->isActivate()) object->draw();
        if (object->getType() == ObjectType::Type::OBJECT3D || object->getType() == ObjectType::CONTAINER || object->getType() == ObjectType::TASKMANAGER) {
            Object3D *object3d = dynamic_cast<Object3D*>(object.get());
            if (object3d->isCollisionable() && !object3d->isActivate()) {
                Rectangle rec = object3d->getCollisionBox();
                DrawCube((Vector3){ rec.x + rec.width/2, 1, rec.y + rec.height/2 }, rec.width, 2, rec.height, { 255, 0, 0, 100 });
            }
        }
    }
}