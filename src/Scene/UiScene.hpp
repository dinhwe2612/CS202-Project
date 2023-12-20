#pragma once
#include "Object.hpp"
#include "AScene.hpp"

#include <memory>

class UiScene : public AScene {
private:
    std::vector<std::unique_ptr<Object>> objects;
public:
    UiScene();
    ~UiScene();
    virtual void eventScene() = 0;
    Scenes run() override;
    virtual Scenes endScene() = 0;
};