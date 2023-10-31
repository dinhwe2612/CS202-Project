#pragma once
#include "AScence.hpp"

#include "../Object/object.hpp"
#include "../Object/Player.hpp"

#include <vector>

class ScenceGame : public AScence {
private:
    Player *player;
    std::vector<Object3D*> wallPtrs;
    std::vector<Object3D*> flatPtrs;
public:
    ScenceGame();
    ~ScenceGame();
    void draw() override;
};