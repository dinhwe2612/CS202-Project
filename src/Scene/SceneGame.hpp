#pragma once
#include "AScene.hpp"

#include "../Object/object.hpp"
#include "../Object/Movable/Player.hpp"
#include "../Other/AdjustObject.hpp"
#include "../Other/InputObject.hpp"
#include "../Mediator/Mediator.hpp"
#include "../ResourcesManager/ResourcesManager.hpp"

#include <vector>

class SceneGame : public AScene {
private:
    IMediator *objectMediator;
    AdjustObject3D adjust;
public:
    SceneGame();
    ~SceneGame();
    void draw() override;
};