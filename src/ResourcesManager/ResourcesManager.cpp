#include "ResourcesManager.hpp"

// Initialize static member
ResourcesManager* ResourcesManager::instance = nullptr;

bool ResourcesManager::hasModel(const std::string& name) {
    return listOfModels.find(name) != listOfModels.end();
}

Model ResourcesManager::getModel(const std::string& name) {
    return listOfModels[name];
}

bool ResourcesManager::sliceable(const std::string& name) {
    return listOfSlices.find(name) != listOfSlices.end();
}

std::string ResourcesManager::slice(const std::string name) {
    return listOfSlices[name];
}

std::string ResourcesManager::pathPickableObject(const std::string& name) {
    return listOfPickableObjects[name];
}

bool ResourcesManager::cookable(std::vector<std::string> ingredients) {
    std::sort(ingredients.begin(), ingredients.end());
    return std::find(listOfRecipes.begin(), listOfRecipes.end(), ingredients) != listOfRecipes.end();
}

std::string ResourcesManager::cook(std::vector<std::string> ingredients) {
    std::sort(ingredients.begin(), ingredients.end());
    for(int i = 0; i < listOfRecipes.size(); i++) {
        if (listOfRecipes[i] == ingredients) return listOfFoods[i];
    }
    return "";
}

bool ResourcesManager::isIngredient(const std::string name) {
    return std::find(listOfIngredients.begin(), listOfIngredients.end(), name) != listOfIngredients.end();
}

std::vector<std::string> ResourcesManager::getRecipe(std::string name) {
    for(int i = 0; i < listOfFoods.size(); i++) {
        if (listOfFoods[i] == name) return listOfRecipes[i];
    }
    return {};
}