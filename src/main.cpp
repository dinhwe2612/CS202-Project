#include "raylib.h"
#include "raylib-cpp.hpp"

#include <object.hpp>
#include <Player.hpp>
#include "../src/Scene/SceneGame.hpp"
#include "../src/Other/InputObject.hpp"
#include "../src/Application/Application.hpp"

#include <iostream>

using namespace std;

int main(void)
{
    // Initialize Raylib
    // InitWindow(3000, 1800, "Cooking");

    // SceneGame *sceneGame = new SceneGame();
    Application app;
    app.run();
    
    // Main game loop
    // Scenes state = GAME;
    // while (state != Scenes::QUIT)
    // {
        // BeginDrawing();
        // ClearBackground({0, 0, 0, 0});

            // state = sceneGame->run();

        // EndDrawing();
    // }

    // Unload model and close Raylib
    // UnloadModel(model);
    CloseWindow();

    return 0;
}
// y
//   x
// z
