#include "Application.hpp"

namespace app {
    Application::Application(int width, int height, const std::string &title) {
        window = new raylib::Window(width, height, title);

        camera->position = (Vector3){ 0.0f, 10.0f, 10.0f };
        camera->target = (Vector3){ 0.0f, 1.8f, 0.0f };
        camera->up = (Vector3){ 0.0f, 20.0f, 0.0f };
        camera->fovy = 45.0f;
        camera->projection = CAMERA_PERSPECTIVE;
    }

    Application::~Application() {
        
    }

    void Application::run() {
        while (!window->ShouldClose()) {
            window->BeginDrawing();
                window->ClearBackground(RAYWHITE);
                BeginMode3D(*camera);
                    
                EndMode3D();
            window->EndDrawing();
        }
    }
};