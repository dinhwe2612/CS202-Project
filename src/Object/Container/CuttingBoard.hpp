#pragma once

#include "Container.hpp"

#include <unordered_map>
#include <fstream>

class CuttingBoard : public Container {
private:
public:
    CuttingBoard();
    void cut();
    bool placeObjectOn(PickableObject *object) override;
};