#include "ResourcesManager.hpp"

// Initialize static member
ResourcesManager* ResourcesManager::instance = nullptr;

ResourcesManager::ResourcesManager() : rng((std::chrono::steady_clock::now().time_since_epoch().count())) {
    BeginDrawing();
        ClearBackground(WHITE);
        DrawText("Loading...", 1093, 778.8, 152, BLACK);
    EndDrawing();
    listOfTextures = {
        {"coin", LoadTexture("../resources/texture/coin.png")},
        {"timer", LoadTexture("../resources/texture/timer.png")},
        {"plate_bun_burger", LoadTexture("../resources/texture/plate_bun_burger.png")},
        {"plate_bun_cheese_tomato", LoadTexture("../resources/texture/plate_bun_cheese_tomato.png")},
        {"plate_bun_burger", LoadTexture("../resources/texture/plate_bun_burger.png")},
        {"plate_bun_cheese", LoadTexture("../resources/texture/plate_bun_cheese.png")},
        {"plate_bun_lettuce", LoadTexture("../resources/texture/plate_bun_lettuce.png")},
        {"plate_bun_lettuce_cheese", LoadTexture("../resources/texture/plate_bun_lettuce_cheese.png")},
        {"plate_bun_lettuce_tomato", LoadTexture("../resources/texture/plate_bun_lettuce_tomato.png")},
        {"plate_bun_tomato", LoadTexture("../resources/texture/plate_bun_tomato.png")},
        // {"task_plate_bun", LoadTexture("../resources/texture/task_plate_bun.png")},
        {"task_plate_bun_burger", LoadTexture("../resources/texture/task_plate_bun_burger.png")},
        {"task_plate_bun_cheese", LoadTexture("../resources/texture/task_plate_bun_cheese.png")},
        {"task_plate_bun_lettuce", LoadTexture("../resources/texture/task_plate_bun_lettuce.png")},
        {"task_plate_bun_tomato", LoadTexture("../resources/texture/task_plate_bun_tomato.png")},
        {"task_plate_bun_cheese_tomato", LoadTexture("../resources/texture/task_plate_bun_cheese_tomato.png")},
        {"task_plate_bun_lettuce_cheese", LoadTexture("../resources/texture/task_plate_bun_lettuce_cheese.png")},
        {"task_plate_bun_lettuce_tomato", LoadTexture("../resources/texture/task_plate_bun_lettuce_tomato.png")},
        {"restaurant", LoadTexture("../resources/texture/Restaurant.png")},
        {"map1", LoadTexture("../resources/texture/map1.png")},
        {"map2", LoadTexture("../resources/texture/map2.png")},
        {"map3", LoadTexture("../resources/texture/map3.png")},
        {"arrowLeft", LoadTexture("../resources/texture/arrowLeft.png")},
        {"arrowRight", LoadTexture("../resources/texture/arrowRight.png")},
        {"arrowBack", LoadTexture("../resources/texture/arrowBack.png")},
        {"backgroundSceneNewGame", LoadTexture("../resources/texture/backgroundSceneNewGame.png")},
        {"Select", LoadTexture("../resources/texture/Select.png")},
        {"ScenePauseGame", LoadTexture("../resources/texture/ScenePauseGame.png")},
        {"SceneSettingGame", LoadTexture("../resources/texture/SceneSettingGame.png")},
        {"Apply", LoadTexture("../resources/texture/Apply.png")},
        {"tick", LoadTexture("../resources/texture/tick.png")},
        {"SceneEndGame", LoadTexture("../resources/texture/SceneEndGame.png")},
        {"SceneHighScore", LoadTexture("../resources/texture/SceneHighScore.png")},
        {"BurgerDrop", LoadTexture("../resources/texture/BurgerDrop.png")}
    };
    listOfModels = {
        {"bun", LoadModel("../resources/gltf/food_ingredient_bun.gltf")},
        {"cheese", LoadModel("../resources/gltf/food_ingredient_cheese.gltf")},
        {"cheese_chopped", LoadModel("../resources/gltf/food_ingredient_cheese_chopped.gltf")},
        {"cheese_slice", LoadModel("../resources/gltf/food_ingredient_cheese_slice.gltf")},
        {"lettuce", LoadModel("../resources/gltf/food_ingredient_lettuce.gltf")},
        {"lettuce_chopped", LoadModel("../resources/gltf/food_ingredient_lettuce_chopped.gltf")},
        {"lettuce_slice", LoadModel("../resources/gltf/food_ingredient_lettuce_slice.gltf")},
        {"ham", LoadModel("../resources/gltf/food_ingredient_ham.gltf")},
        {"potato", LoadModel("../resources/gltf/food_ingredient_potato.gltf")},
        {"potato_chopped", LoadModel("../resources/gltf/food_ingredient_potato_chopped.gltf")},
        {"potato_mashed", LoadModel("../resources/gltf/food_ingredient_potato_mashed.gltf")},
        {"tomato", LoadModel("../resources/gltf/food_ingredient_tomato.gltf")},
        {"tomato_slice", LoadModel("../resources/gltf/food_ingredient_tomato_slice.gltf")},
        {"onion", LoadModel("../resources/gltf/food_ingredient_onion.gltf")},
        {"onion_chopped", LoadModel("../resources/gltf/food_ingredient_onion_chopped.gltf")},
        {"onion_rings", LoadModel("../resources/gltf/food_ingredient_onion_rings.gltf")},
        {"carrot", LoadModel("../resources/gltf/food_ingredient_carrot.gltf")},
        {"carrot_chopped", LoadModel("../resources/gltf/food_ingredient_carrot_chopped.gltf")},
        {"carrot_pieces", LoadModel("../resources/gltf/food_ingredient_carrot_pieces.gltf")},
        {"steak", LoadModel("../resources/gltf/food_ingredient_steak.gltf")},
        {"steak_pieces", LoadModel("../resources/gltf/food_ingredient_steak_pieces.gltf")},
        {"burger_uncooked", LoadModel("../resources/gltf/food_ingredient_burger_uncooked.gltf")},
        {"burger_cooked", LoadModel("../resources/gltf/food_ingredient_burger_cooked.gltf")},
        {"plate_small", LoadModel("../resources/gltf/plate_small.gltf")},
        {"plate_bun", LoadModel("../resources/gltf/plate_bun.glb")},
        {"plate_bun_cheese", LoadModel("../resources/gltf/plate_bun_cheese.glb")},
        {"plate_bun_lettuce", LoadModel("../resources/gltf/plate_bun_lettuce.glb")},
        {"plate_bun_tomato", LoadModel("../resources/gltf/plate_bun_tomato.glb")},
        {"plate_bun_burger", LoadModel("../resources/gltf/plate_bun_burger.glb")},
        {"plate_bun_lettuce_cheese", LoadModel("../resources/gltf/plate_bun_lettuce_cheese.glb")},
        {"plate_bun_lettuce_tomato", LoadModel("../resources/gltf/plate_bun_lettuce_tomato.glb")},
        {"plate_bun_cheese_tomato", LoadModel("../resources/gltf/plate_bun_cheese_tomato.glb")},
        {"player", LoadModel("../resources/models/little_chef_overcooked_like.glb")},
        // {"map", LoadModel("../resources/models/map_basic_ex.glb")},
        {"food_stew", LoadModel("../resources/gltf/food_stew.gltf")},
    };
    listOfSlices = {
        {"cheese", "cheese_chopped"},
        {"cheese_chopped", "cheese_slice"},
        {"lettuce", "lettuce_chopped"},
        {"lettuce_chopped", "lettuce_slice"},
        {"tomato", "tomato_slice"},
        {"onion", "onion_chopped"},
        {"onion_chopped", "onion_rings"},
        {"carrot", "carrot_chopped"},
        {"carrot_chopped", "carrot_pieces"},
        {"steak", "steak_pieces"},
        {"steak_pieces", "burger_uncooked"},
        {"potato", "potato_chopped"},
        {"potato_chopped", "potato_mashed"},
    };
    listOfFries = {
        {"burger_uncooked", "burger_cooked"},
    };
    listOfPickableObjects = {
        {"cheese", "../resources/map1/pickable/ingredient_cheese.txt"},
        {"cheese_slice", "../resources/map1/pickable/ingredient_cheese_slice.txt"},
        {"cheese_chopped", "../resources/map1/pickable/ingredient_cheese_chopped.txt"},
        {"lettuce", "../resources/map1/pickable/ingredient_lettuce.txt"},
        {"lettuce_slice", "../resources/map1/pickable/ingredient_lettuce_slice.txt"},
        {"lettuce_chopped", "../resources/map1/pickable/ingredient_lettuce_chopped.txt"},
        {"tomato", "../resources/map1/pickable/ingredient_tomato.txt"},
        {"tomato_slice", "../resources/map1/pickable/ingredient_tomato_slice.txt"},
        {"onion", "../resources/map1/pickable/ingredient_onion.txt"},
        {"onion_chopped", "../resources/map1/pickable/ingredient_onion_chopped.txt"},
        {"onion_rings", "../resources/map1/pickable/ingredient_onion_rings.txt"},
        {"carrot", "../resources/map1/pickable/ingredient_carrot.txt"},
        {"carrot_chopped", "../resources/map1/pickable/ingredient_carrot_chopped.txt"},
        {"carrot_pieces", "../resources/map1/pickable/ingredient_carrot_pieces.txt"},
        {"steak", "../resources/map1/pickable/ingredient_steak.txt"},
        {"steak_pieces", "../resources/map1/pickable/ingredient_steak_pieces.txt"},
        {"burger_uncooked", "../resources/map1/pickable/ingredient_burger_uncooked.txt"},
        {"burger_cooked", "../resources/map1/pickable/ingredient_burger_cooked.txt"},
        {"ham", "../resources/map1/pickable/ingredient_ham.txt"},
        {"bun", "../resources/map1/pickable/ingredient_bun.txt"},
        {"plate_small", "../resources/map1/pickable/plate_small.txt"},
        {"food_stew", "../resources/map1/pickable/food_stew.txt"},
    };
    listOfFonts = {
        {"komyca_italic", LoadFontEx("../resources/font/Komyca3DItalic.ttf", 200, 0, 0)},
        {"cocktail_italic", LoadFontEx("../resources/font/HiddencocktailsItalic.ttf", 200, 0, 0)},
        {"cocktail_italic_shadow", LoadFontEx("../resources/font/HiddencocktailsItalicshadow.ttf", 180, 0, 0)},
        {"Scripto", LoadFontEx("../resources/font/Scripto.ttf", 190, 0, 0)},
    };
    listOfRecipes = {
        {"bun"},
        {"bun", "cheese_slice"},
        {"bun", "lettuce_slice"},
        {"bun", "tomato_slice"},
        {"bun", "burger_cooked"},
        {"bun", "cheese_slice", "lettuce_slice"},
        {"bun", "lettuce_slice", "tomato_slice"},
        {"bun", "tomato_slice", "cheese_slice"},
    };
    for(int i = 0; i < listOfRecipes.size(); i++) {
        std::sort(listOfRecipes[i].begin(), listOfRecipes[i].end());
        for(int j = 0; j < listOfRecipes[i].size(); j++) {
            listOfIngredients.push_back(listOfRecipes[i][j]);
        }
    }
    std::sort(listOfIngredients.begin(), listOfIngredients.end());
    listOfIngredients.erase(std::unique(listOfIngredients.begin(), listOfIngredients.end()), listOfIngredients.end());
    listOfFoods = {
        "plate_bun",
        "plate_bun_cheese",
        "plate_bun_lettuce",
        "plate_bun_tomato",
        "plate_bun_burger",
        "plate_bun_lettuce_cheese",
        "plate_bun_lettuce_tomato",
        "plate_bun_cheese_tomato",
    };
    listOfTasks = {
        // "task_plate_bun",
        "task_plate_bun_burger",
        "task_plate_bun_cheese",
        "task_plate_bun_lettuce",
        "task_plate_bun_tomato",
        "task_plate_bun_cheese_tomato",
        "task_plate_bun_lettuce_cheese",
        "task_plate_bun_lettuce_tomato",
    };
}

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

int ResourcesManager::getTotalPoints() {
    return totalPoints;
}

void ResourcesManager::setTotalPoints(int points) {
    totalPoints = points;
}