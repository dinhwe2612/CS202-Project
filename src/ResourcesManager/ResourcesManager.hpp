#pragma once

#include <raylib-cpp.hpp>

#include <unordered_map>
#include <algorithm>

class ResourcesManager {
private:
    std::unordered_map<std::string, Model> listOfModels;
    std::unordered_map<std::string, std::string> listOfSlices;
    std::unordered_map<std::string, std::string> listOfCooks;
    std::unordered_map<std::string, std::string> listOfPickableObjects;
    std::vector<std::string> listOfIngredients;
    std::vector<std::vector<std::string>> listOfRecipes;
    std::vector<std::string> listOfFoods;
    static ResourcesManager* instance;

    ResourcesManager() {
        listOfModels = {
            {"bun", LoadModel("../resources/gltf/food_ingredient_bun.gltf")},
            {"cheese", LoadModel("../resources/gltf/food_ingredient_cheese.gltf")},
            {"cheese_chopped", LoadModel("../resources/gltf/food_ingredient_cheese_chopped.gltf")},
            {"cheese_slice", LoadModel("../resources/gltf/food_ingredient_cheese_slice.gltf")},
            {"lettuce", LoadModel("../resources/gltf/food_ingredient_lettuce.gltf")},
            {"lettuce_chopped", LoadModel("../resources/gltf/food_ingredient_lettuce_chopped.gltf")},
            {"lettuce_slice", LoadModel("../resources/gltf/food_ingredient_lettuce_slice.gltf")},
            {"ham", LoadModel("../resources/gltf/food_ingredient_ham.gltf")},
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
            {"map", LoadModel("../resources/models/map_basic_ex.glb")},
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
        };
        listOfCooks = {
            
        };
        listOfPickableObjects = {
            {"cheese", "../resources/map/pickable/ingredient_cheese.txt"},
            {"cheese_slice", "../resources/map/pickable/ingredient_cheese_slice.txt"},
            {"cheese_chopped", "../resources/map/pickable/ingredient_cheese_chopped.txt"},
            {"lettuce", "../resources/map/pickable/ingredient_lettuce.txt"},
            {"lettuce_slice", "../resources/map/pickable/ingredient_lettuce_slice.txt"},
            {"lettuce_chopped", "../resources/map/pickable/ingredient_lettuce_chopped.txt"},
            {"tomato", "../resources/map/pickable/ingredient_tomato.txt"},
            {"tomato_slice", "../resources/map/pickable/ingredient_tomato_slice.txt"},
            {"onion", "../resources/map/pickable/ingredient_onion.txt"},
            {"onion_chopped", "../resources/map/pickable/ingredient_onion_chopped.txt"},
            {"onion_rings", "../resources/map/pickable/ingredient_onion_rings.txt"},
            {"carrot", "../resources/map/pickable/ingredient_carrot.txt"},
            {"carrot_chopped", "../resources/map/pickable/ingredient_carrot_chopped.txt"},
            {"carrot_pieces", "../resources/map/pickable/ingredient_carrot_pieces.txt"},
            {"steak", "../resources/map/pickable/ingredient_steak.txt"},
            {"steak_pieces", "../resources/map/pickable/ingredient_steak_pieces.txt"},
            {"burger_uncooked", "../resources/map/pickable/ingredient_burger_uncooked.txt"},
            {"burger_cooked", "../resources/map/pickable/ingredient_burger_cooked.txt"},
            {"ham", "../resources/map/pickable/ingredient_ham.txt"},
            {"bun", "../resources/map/pickable/ingredient_bun.txt"},
            {"plate_small", "../resources/map/pickable/plate_small.txt"},
            {"food_stew", "../resources/map/pickable/food_stew.txt"},
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
    }

public:
    static ResourcesManager* getInstance() {
        if (!instance)
            instance = new ResourcesManager();
        return instance;
    }
    bool hasModel(const std::string& name);
    Model getModel(const std::string& name);
    bool sliceable(const std::string& name);
    std::string slice(const std::string name);
    std::string pathPickableObject(const std::string& name);
    bool cookable(std::vector<std::string> ingredients);
    std::string cook(std::vector<std::string> ingredients);
    bool isIngredient(const std::string name);
    std::vector<std::string> getRecipe(std::string name);
};

