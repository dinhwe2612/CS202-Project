#pragma once
#include "IScene.hpp"
#include "Object.hpp"
#include "../Application/InputSupport.hpp"
#include "ResourcesManager/ResourcesManager.hpp"

#include <unordered_map> 
#include <functional>
#include <vector>
#include <iostream>
#include <memory>

struct PairHash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        auto h1 = std::hash<T1>{}(pair.first);
        auto h2 = std::hash<T2>{}(pair.second);
        return h1 * 1000 + h2;
    }
};

class AScene : public IScene {
protected:
    ResourcesManager *resourcesManager;
    Camera3D camera = { 0 };
    std::vector<std::shared_ptr<Object>> objects;
    InputSupport inputSp;
    Scenes state;
public:
    AScene();
    ~AScene();
    virtual void draw() = 0;
    void triggerInputActions();
    void setInputFunction(InputSupport::Key key, InputSupport::InputType type, std::function<void()> func);
protected:
    std::unordered_map<std::pair<int, int>,std::function<void()>,PairHash> listOfkeys = {
        {{InputSupport::ENTER, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::SPACE, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::ESCAPE, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::TAB, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::UP_ARROW, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::DOWN_ARROW, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::RIGHT_ARROW, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::LEFT_ARROW, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::A, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::B, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::C, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::D, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::E, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::E, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::F, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::G, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::H, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::I, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::J, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::K, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::L, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::M, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::N, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::O, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::P, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::Q, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::R, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::S, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::T, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::U, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::V, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::W, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::X, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::Y, InputSupport::PRESSED}, {[](){}}},
        {{InputSupport::Z, InputSupport::PRESSED}, {[](){}}},
        
        {{InputSupport::ENTER, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::SPACE, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::ESCAPE, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::TAB, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::UP_ARROW, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::DOWN_ARROW, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::RIGHT_ARROW, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::LEFT_ARROW, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::A, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::B, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::C, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::D, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::E, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::E, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::F, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::G, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::H, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::I, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::J, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::K, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::L, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::M, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::N, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::O, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::P, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::Q, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::R, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::S, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::T, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::U, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::V, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::W, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::X, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::Y, InputSupport::DOWN}, {[](){}}},
        {{InputSupport::Z, InputSupport::DOWN}, {[](){}}},

        {{InputSupport::ENTER, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::SPACE, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::ESCAPE, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::TAB, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::UP_ARROW, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::DOWN_ARROW, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::RIGHT_ARROW, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::LEFT_ARROW, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::A, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::B, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::C, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::D, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::E, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::E, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::F, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::G, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::H, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::I, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::J, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::K, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::L, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::M, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::N, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::O, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::P, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::Q, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::R, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::S, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::T, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::U, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::V, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::W, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::X, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::Y, InputSupport::RELEASED}, {[](){}}},
        {{InputSupport::Z, InputSupport::RELEASED}, {[](){}}},
    };
};