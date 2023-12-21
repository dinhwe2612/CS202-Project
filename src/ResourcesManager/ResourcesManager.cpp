#include "ResourcesManager.hpp"

// Initialize static member
ResourcesManager* ResourcesManager::instance = nullptr;

bool ResourcesManager::hasModel(const std::string& name) {
    return listOfModels.find(name) != listOfModels.end();
}

Model ResourcesManager::getModel(const std::string& name) {
    return listOfModels[name];
}

Font ResourcesManager::getFont(const std::string name) {
    return listOfFonts[name];
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

bool ResourcesManager::fryable(std::string name) {
    return listOfFries.find(name) != listOfFries.end();
}

std::string ResourcesManager::fry(std::string name) {
    return listOfFries[name];
}

void ResourcesManager::resetTimer(const std::string name) {
    start[name] = std::chrono::high_resolution_clock::now();
}

double ResourcesManager::getElapsedSeconds(const std::string name) {
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start[name];
    return elapsed.count();
}

Texture ResourcesManager::getTexture(const std::string name) {
    return listOfTextures[name];
}

int ResourcesManager::getRandomInt(int min, int max) {
    return rng() % (max - min + 1) + min;
}

std::string ResourcesManager::getRandomTask() {
    return listOfTasks[getRandomInt(0, listOfTasks.size() - 1)];
}

Vector2 ResourcesManager::centerText(Font font, Vector2 position, std::string text, float fontSize, float spacing) {
    Vector2 size = MeasureTextEx(font, text.c_str(), fontSize, spacing);
    Vector2 res;
    res.x = position.x - size.x / 2;
    res.y = position.y - size.y / 2;
    return res;
}

float ResourcesManager::getScale(const std::string name) {
    return listOfScales[name];
}

int ResourcesManager::getAnimFramesBurger() {
    return animFrames;
}

Image ResourcesManager::getBurgerImage() {
    return burgerImage;
}