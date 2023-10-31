#include "raylib.h"
#include "raylib-cpp.hpp"

#include <object.hpp>
#include <Player.hpp>
#include "../src/Scence/ScenceGame.hpp"

#include <iostream>

using namespace std;

enum Direction { UP = 180, DOWN = 0, LEFT = 270, RIGHT = 90 };

int getDirection() {
    int keyPressed = 0;
    if (IsKeyDown(KEY_W)) keyPressed = KEY_W;
    else if (IsKeyDown(KEY_S)) keyPressed = KEY_S;
    else if (IsKeyDown(KEY_A)) keyPressed = KEY_A;
    else if (IsKeyDown(KEY_D)) keyPressed = KEY_D;
    return keyPressed;
}

void draw() {
    for(int i = -10; i <= 10; ++i) {
        for(int j = -10; j <= 10; ++j) {
            DrawCube((Vector3){i, -1, j}, 1, 1, 1, (i + j) % 2 ? BLACK : RAYWHITE);
        }
    }
}

int main(void)
{
    // Initialize Raylib
    InitWindow(1400, 800, "Cooking");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 1.8f, 0.0f };
    camera.up = (Vector3){ 0.0f, 20.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    ScenceGame scenceGame;

    // Main game loop
    while (!WindowShouldClose())
    {
        // Vector3 oldModelPos = modelPos;
        // camera.target = modelPos;
        // camera.position = Vector3Add(camera.position, Vector3Subtract(modelPos, oldModelPos));
        
        // UpdateModelAnimation(model, animChef[animsIdx], animCurrentFrame);
        // player.rotate(Object3D::Y, 0.01f);
        BeginDrawing();
        ClearBackground(BLACK);

        
        // switch (getDirection()) {
        //     case KEY_W:
        //         player.moveDirection(Player::UP);
        //         break;
        //     case KEY_A:
        //         player.moveDirection(Player::LEFT);
        //         break;
        //     case KEY_S:
        //         player.moveDirection(Player::DOWN);
        //         break;
        //     case KEY_D:
        //         player.moveDirection(Player::RIGHT);
        //         break;
        // }

        BeginMode3D(camera);

            // Draw the model with the updated transformation matrix
            draw();
            // Draw the wall around the map
            Color wallColor = { 228, 112, 37, 255 };
            DrawCube((Vector3){-11, 0, 0}, 1, 10, 21, wallColor);
            DrawCube((Vector3){11, 0, 0}, 1, 10, 21, wallColor);
            DrawCube((Vector3){0, 0, -11}, 21, 10, 1, wallColor);
            DrawCube((Vector3){0, 0, 11}, 21, 10, 1, wallColor);

            scenceGame.draw();
        EndMode3D();

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
