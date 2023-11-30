#include "raylib.h"
#include "raylib-cpp.hpp"

#include <object.hpp>
#include <Player.hpp>
#include "../src/Scene/SceneGame.hpp"
#include "../src/Other/InputObject.hpp"

#include <iostream>

using namespace std;

int main(void)
{
    // Initialize Raylib
    InitWindow(3000, 1800, "Cooking");

    SceneGame sceneGame;


    // Main game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground({0, 0, 0, 0});

            sceneGame.draw();

        EndDrawing();
    }

    // Unload model and close Raylib
    // UnloadModel(model);
    CloseWindow();

    return 0;
}
// y
//   x
// z
