#pragma once
#include "raylib-cpp.hpp"

#include "object.hpp"
#include "../Scene/IScene.hpp"

namespace app {
    class Application {
    private:
        raylib::Window *window;
        raylib::Camera3D *camera;
        

    IScene *curScene;
    public:
        Application(int width, int height, const std::string &title);
        ~Application();
        void run();
    };
};