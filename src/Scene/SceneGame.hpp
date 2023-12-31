#pragma once
#include "AScene.hpp"
#include "../Object/object.hpp"
#include "../Object/Movable/Player.hpp"
#include "../Other/AdjustObject.hpp"
#include "../ObjectManager/ObjectManager.hpp"
#include "../ResourcesManager/ResourcesManager.hpp"
#include "../Application/Setting.hpp"

#include <vector>

class SceneGame : public AScene {
private:
    ObjectManager *objectManager;
    Camera3D *camera;
public:
    SceneGame();
    ~SceneGame();
    void draw() override;
    Scenes run() override;
};