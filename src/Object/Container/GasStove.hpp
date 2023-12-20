#pragma once

#include "Container.hpp"

#include <fstream>

class GasStove : public Container {
public:
    GasStove();
    void cook();
    bool placeObjectOn(PickableObject *object) override;
};