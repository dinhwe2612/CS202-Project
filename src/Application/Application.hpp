#pragma once
#include "raylib-cpp.hpp"

#include "object.hpp"
#include "../Scence/IScence.hpp"

namespace app {
    class Application {
    private:
        raylib::Window *window;
        raylib::Camera3D *camera;
        

        IScence *curScence;
    public:
        Application(int width, int height, const std::string &title);
        ~Application();
        void run();
    };
};