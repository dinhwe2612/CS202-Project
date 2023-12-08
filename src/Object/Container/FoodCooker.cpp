#include "FoodCooker.hpp"

FoodCooker::FoodCooker() : Container() {
    this->isCooking = false;
}

bool FoodCooker::placeObjectOn(PickableObject *object) {
    std::cout << getName() << '\n';
    if (isPlaceObjectOn() == false) {
        std::string name = object->getName();
        ingredients = resourcesManager->getRecipe(name);
        Container::placeObjectOn(object);
        return true;
    } else {
        std::string curName = getName();
        if (curName.size() >= 5 && curName.substr(0, 5) == "plate") {
            ingredients.push_back(object->getName());
            if (resourcesManager->cookable(ingredients)) {
                std::string newName = resourcesManager->cook(ingredients);
                Container::placeObjectOn(new PickableObject(newName));
                return true;
            } else {
                ingredients.pop_back();
            }
        }
    }
    return false;
}

bool FoodCooker::removeObject() {
    if (!isPlaceObjectOn() || !Container::removeObject()) {
        return false;
    }
    ingredients.clear();
    return true;
}