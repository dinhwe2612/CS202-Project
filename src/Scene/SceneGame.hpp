#pragma once
#include "AScene.hpp"
#include "../Object/object.hpp"
#include "../Object/Movable/Player.hpp"
#include "../Other/AdjustObject.hpp"
#include "../ObjectManager/ObjectManager.hpp"
#include "../ResourcesManager/ResourcesManager.hpp"

#include <vector>

class SceneGame : public AScene {
private:
    ObjectManager *objectManager;
public:
    SceneGame();
    ~SceneGame();
    void draw() override;
    Scenes run() override;
};