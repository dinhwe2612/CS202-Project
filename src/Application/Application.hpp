#pragma once
#include "raylib-cpp.hpp"

#include "object.hpp"
#include "../Scene/SceneGame.hpp"
#include "../Scene/UiScene/UiSceneMenu.hpp"
#include "../Scene/UiScene/UiSceneNewGame.hpp"
#include "../Scene/UiScene/UiScenePauseGame.hpp"
#include "../Scene/UiScene/UiSceneSettingGame.hpp"
#include "../Scene/UiScene/UiSceneEndGame.hpp"

#include <unordered_map>
#include <memory>

static const std::unordered_map<Scenes, std::function<std::unique_ptr<IScene>()>> enumToConstructor = {
    {Scenes::MENU, [](){return std::unique_ptr<IScene>(new UiSceneMenu());}},
    {Scenes::NEWGAME, [](){return std::unique_ptr<IScene>(new UiSceneNewGame());}},
    {Scenes::GAME, [](){return std::unique_ptr<IScene>(new SceneGame());}},
    {Scenes::PAUSE, [](){return std::unique_ptr<IScene>(new UiScenePauseGame());}},
    {Scenes::SETTING, [](){return std::unique_ptr<IScene>(new UiSceneSettingGame());}},
    {Scenes::ENDGAME, [](){return std::unique_ptr<IScene>(new UiSceneEndGame());}},
};

class Application {
private:
    Scenes state;
    std::unique_ptr<IScene> prevScene = NULL;
    std::unique_ptr<IScene> curScene;
public:
    Application();
    ~Application();
    void run();
};