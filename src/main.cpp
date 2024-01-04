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
    Application app;
    app.run();
    
    // InitWindow(3000, 1800, "Cooking");
    // Camera3D camera = {0};
    // camera.position = { 0.0f, 10.0f, 10.0f };  // Camera position
    // camera.target = { 0.0f, 0.0f, 0.0f };      // Camera looking at point
    // camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    // camera.fovy = 45.0f;                                // Camera field-of-view Y
    // camera.projection = CAMERA_PERSPECTIVE;                   // Camera mode type
    // Model map = LoadModel("../resources/models/DINH_map3_ex.glb");
    // while(!WindowShouldClose()) {
    //     // Update camera looking at movement point
    //     if (IsKeyDown(KEY_UP)) {
    //         camera.target.z += 0.1f;
    //         camera.position.z += 0.1f;
    //     }
    //     if (IsKeyDown(KEY_DOWN)) {
    //         camera.target.z -= 0.1f;
    //         camera.position.z -= 0.1f;
    //     }
    //     if (IsKeyDown(KEY_LEFT)) {
    //         camera.target.x -= 0.1f;
    //         camera.position.x -= 0.1f;
    //     }
    //     if (IsKeyDown(KEY_RIGHT)) {
    //         camera.target.x += 0.1f;
    //         camera.position.x += 0.1f;
    //     }
    //     BeginDrawing();
    //     ClearBackground(BLACK);
    //     BeginMode3D(camera);
    //     DrawModel(map, {0, 0, 0}, 1, WHITE);
    //     EndMode3D();
    //     EndDrawing();
    // }

    return 0;
}
// y
//   x
// z
