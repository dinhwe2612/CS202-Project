#pragma once

#include <raylib-cpp.hpp>

#include <unordered_map>
#include <algorithm>
#include <chrono>
#include <random>

class Gif;

class ResourcesManager {
private:
    std::mt19937 rng;
    std::unordered_map<std::string, std::chrono::time_point<std::chrono::high_resolution_clock>> start;
    std::unordered_map<std::string, Model> listOfModels;
    std::unordered_map<std::string, Texture> listOfTextures;
    std::unordered_map<std::string, Font> listOfFonts;
    std::unordered_map<std::string, std::string> listOfSlices;
    std::unordered_map<std::string, std::string> listOfFries;
    std::unordered_map<std::string, std::string> listOfPickableObjects;
    std::unordered_map<std::string, float> listOfScales;
    std::unordered_map<std::string, Vector2> listOfPosition;
    std::vector<std::string> listOfIngredients;
    std::vector<std::vector<std::string>> listOfRecipes;
    std::vector<std::string> listOfFoods;
    std::vector<std::string> listOfTasks;
    static ResourcesManager* instance;
    int totalPoints = 0;

    ResourcesManager();

public:
    static ResourcesManager* getInstance() {
        if (!instance)
            instance = new ResourcesManager();
        return instance;
    }
    void resetTimer(const std::string name);
    double getElapsedSeconds(const std::string name);
    bool hasModel(const std::string& name);
    Model getModel(const std::string& name);
    Texture getTexture(const std::string name);
    Font getFont(const std::string name);
    bool sliceable(const std::string& name);
    std::string slice(const std::string name);
    std::string pathPickableObject(const std::string& name);
    bool cookable(std::vector<std::string> ingredients);
    std::string cook(std::vector<std::string> ingredients);
    bool isIngredient(const std::string name);
    std::vector<std::string> getRecipe(std::string name);
    bool fryable(std::string name);
    std::string fry(std::string name);
    int getRandomInt(int min, int max);
    std::string getRandomTask();
    Vector2 centerText(Font font, Vector2 position, std::string text, float fontSize, float spacing);
    float getScale(const std::string name);
    int getTotalPoints();
    void setTotalPoints(int points);
};
