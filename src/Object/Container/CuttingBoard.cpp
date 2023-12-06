#include "CuttingBoard.hpp"

bool CuttingBoard::isCuttable(std::string name) {
    if (cuttedFood.find(name) != cuttedFood.end()) return true;
    return false;
}

bool CuttingBoard::placeObjectOn(PickableObject *object) {
    if (isCuttable(object->getName())) {
        Container::placeObjectOn(object);
        return true;
    }
    return false;
}

void CuttingBoard::cut() {
    if (isCuttable(name)) {
        setModel("../resources/gltf/food_" + cuttedFood[name] + ".gltf");
    }
}