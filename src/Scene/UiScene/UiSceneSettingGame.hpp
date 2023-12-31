#pragma once

#include "UiScene.hpp"
#include "../Object/UiObject/BoolButton.hpp"
#include "../Application/Setting.hpp"

static const std::unordered_map<int, std::string> keyToText = {
    { InputSupport::Key::Q, "Q" },
    { InputSupport::Key::W, "W" },
    { InputSupport::Key::E, "E" },
    { InputSupport::Key::R, "R" },
    { InputSupport::Key::T, "T" },
    { InputSupport::Key::Y, "Y" },
    { InputSupport::Key::U, "U" },
    { InputSupport::Key::I, "I" },
    { InputSupport::Key::O, "O" },
    { InputSupport::Key::P, "P" },
    { InputSupport::Key::A, "A" },
    { InputSupport::Key::S, "S" },
    { InputSupport::Key::D, "D" },
    { InputSupport::Key::F, "F" },
    { InputSupport::Key::G, "G" },
    { InputSupport::Key::H, "H" },
    { InputSupport::Key::J, "J" },
    { InputSupport::Key::K, "K" },
    { InputSupport::Key::L, "L" },
    { InputSupport::Key::Z, "Z" },
    { InputSupport::Key::X, "X" },
    { InputSupport::Key::C, "C" },
    { InputSupport::Key::V, "V" },
    { InputSupport::Key::B, "B" },
    { InputSupport::Key::N, "N" },
    { InputSupport::Key::M, "M" },
    { InputSupport::Key::UP_ARROW, "AU" },
    { InputSupport::Key::DOWN_ARROW, "AD" },
    { InputSupport::Key::LEFT_ARROW, "AL" },
    { InputSupport::Key::RIGHT_ARROW, "AR" },
    { InputSupport::Key::ESCAPE, "ESCAPE" },
    { InputSupport::Key::SPACE, "SPACE" },
    { InputSupport::Key::ENTER, "ENTER" },
    { InputSupport::Key::SPACE, "SPACE" },
};

class UiSceneSettingGame : public UiScene {
private:
public:
    UiSceneSettingGame();
    void eventScene() override;
    void draw() override;
};