#pragma once
#include "raylib-cpp.hpp"

#include "../Object/object.hpp"
#include "../Object/Player.hpp"


// Mediator interface
class IMediator {
public:
    virtual void notify(std::string event) = 0;
};

// Mediator between 3D objects in the game
class ObjectMediator : public IMediator {
private:
    std::vector<Object3D*> objects;
    std::vector<Object3D*> players;
public:
    ObjectMediator(std::vector<Object3D*> objects, std::vector<Object3D*> players);
    virtual void notify(std::string event) override;
};