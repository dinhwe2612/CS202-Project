#pragma once
#include "raylib-cpp.hpp"

#include "../Object/object.hpp"
#include "../Object/Movable/Player.hpp"


// Mediator interface
class IMediator {
public:
    virtual void notify(std::vector<std::string> messages) = 0;
};

// Mediator between 3D objects in the game
class ObjectMediator : public IMediator {
private:
    std::vector<std::shared_ptr<Object>> objects;
public:
    ObjectMediator(std::vector<std::shared_ptr<Object>> &objects);
    void notify(std::vector<std::string> messages) override;
};