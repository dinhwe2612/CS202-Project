#pragma once

#include "Container.hpp"

class FoodCooker : public Container {
private:
    bool isCooking;
    std::vector<std::string> ingredients;
public:
    FoodCooker();
    bool placeObjectOn(PickableObject *object) override;
    bool removeObject() override;
};