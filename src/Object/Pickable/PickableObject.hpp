#pragma once

#include <raylib-cpp.hpp>

#include <Object/object.hpp>

#include <unordered_map>

static std::unordered_map<std::string, std::string> ingredient = {
    {"bun", "../resources/map/pickable/ingredient_bun.txt"},
    {"cheese", "../resources/map/pickable/ingredient_cheese.txt"},
    {"lettuce", "../resources/map/pickable/ingredient_lettuce.txt"},
    {"ham", "../resources/map/pickable/ingredient_ham.txt"},
    {"tomato", "../resources/map/pickable/ingredient_tomato.txt"},
    {"onion", "../resources/map/pickable/ingredient_onion.txt"},
    {"carrot", "../resources/map/pickable/ingredient_carrot.txt"},
    {"steak", "../resources/map/pickable/ingredient_steak.txt"},
    {"plate_small", "../resources/map/pickable/plate_small.txt"},
};

class PickableObject : public Object3D {
private:
    std::vector<Rectangle> dropDownArea = { { -9, -3.6, 2, 1.8} };
public:
    PickableObject();
    ~PickableObject();
    void draw(Vector2 position);
};