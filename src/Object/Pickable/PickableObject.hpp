#pragma once

#include "../Object/Object.hpp"

#include <unordered_map>

class PickableObject : public Object3D {
public:
    PickableObject();
    PickableObject(std::string name);
    ~PickableObject();
    void draw(Vector2 position);
};