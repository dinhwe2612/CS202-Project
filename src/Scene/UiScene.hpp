#pragma once
#include "Object.hpp"
#include "AScene.hpp"
#include "../src/Object/UiObject/Button.hpp"

#include <memory>

class UiScene : public AScene {
protected:
    std::vector<std::unique_ptr<Button>> buttons;
public:
    UiScene();
    ~UiScene();
    virtual void eventScene() = 0;
    Scenes run() override;
};