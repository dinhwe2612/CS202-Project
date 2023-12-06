#pragma once

#include "Container.hpp"

#include <unordered_map>

static std::unordered_map<std::string, std::string> cuttedFood = {
    {"ingredient_carrot", "ingredient_carrot_chopped"},
    {"ingredient_carrot_chopped", "ingredient_carrot_pieces"},
    {"ingredient_cheese", "ingredient_cheese_chopped"},
    {"ingredient_cheese_chopped", "ingredient_cheese_pieces"},
};

class CuttingBoard : public Container {
private:
    bool isCuttable(std::string name);
public:
    void cut();
    bool placeObjectOn(PickableObject *object) override;
};