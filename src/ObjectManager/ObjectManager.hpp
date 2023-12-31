#pragma once
#include "raylib-cpp.hpp"

#include "../Object/object.hpp"
#include "../Object/Movable/Player.hpp"
#include "../Object/Container/Container.hpp"
#include "../Object/Container/CuttingBoard.hpp"
#include "../Object/Container/FoodCooker.hpp"
#include "../Object/Container/GasStove.hpp"
#include "../Object/UiObject/Task.hpp"
#include "../Other/InputObject.hpp"
#include "../ResourcesManager/ResourcesManager.hpp"

class ObjectManager {
private:
    ResourcesManager *resourcesManager;
    std::vector<std::shared_ptr<Object>> objects;
    std::vector<char> directionPlayer;
public:
    ObjectManager(std::string path);
    void addTask();
    void pick();
    void drop();
    bool submitTask();
    void draw_tasks();
    void cut_cook();
    void movePlayer(Direction direction);
    void movePlayer();
    bool isEndGame();
    void update();
    void draw();
};