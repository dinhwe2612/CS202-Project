#pragma once
#include "IScence.hpp"
#include "Object.hpp"
#include "../Application/Application.hpp"
#include "../Application/InputSupport.hpp"

#include <unordered_map> 
#include <functional>
#include <vector>
#include <iostream>

enum Scence {
    GAME,
};

class AScence : public IScence {
private:
    std::vector<Object*> objectPtrs;
    InputSupport inputSp;
public:
    AScence();
    ~AScence();
    virtual void draw() = 0;
    void triggerInputActions();
    void setInputFunction(InputSupport::Key key, std::function<void()> func);
protected:
    std::unordered_map<int,std::vector<std::function<void()>>> listOfkeys = {
        {InputSupport::ENTER, {[](){}}},
        {InputSupport::SPACE, {[](){}}},
        {InputSupport::ESCAPE, {[](){}}},
        {InputSupport::TAB, {[](){}}},
        {InputSupport::UP, {[](){}}},
        {InputSupport::DOWN, {[](){}}},
        {InputSupport::RIGHT, {[](){}}},
        {InputSupport::LEFT, {[](){}}},
        {InputSupport::A, {[](){}}},
        {InputSupport::B, {[](){}}},
        {InputSupport::C, {[](){}}},
        {InputSupport::D, {[](){}}},
        {InputSupport::E, {[](){}}},
        {InputSupport::E, {[](){}}},
        {InputSupport::F, {[](){}}},
        {InputSupport::G, {[](){}}},
        {InputSupport::H, {[](){}}},
        {InputSupport::I, {[](){}}},
        {InputSupport::J, {[](){}}},
        {InputSupport::K, {[](){}}},
        {InputSupport::L, {[](){}}},
        {InputSupport::M, {[](){}}},
        {InputSupport::N, {[](){}}},
        {InputSupport::O, {[](){}}},
        {InputSupport::P, {[](){}}},
        {InputSupport::Q, {[](){}}},
        {InputSupport::R, {[](){}}},
        {InputSupport::S, {[](){}}},
        {InputSupport::T, {[](){}}},
        {InputSupport::U, {[](){}}},
        {InputSupport::V, {[](){}}},
        {InputSupport::W, {[](){}}},
        {InputSupport::X, {[](){}}},
        {InputSupport::Y, {[](){}}},
        {InputSupport::Z, {[](){}}},
    };
};