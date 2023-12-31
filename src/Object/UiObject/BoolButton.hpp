#pragma once

#include "Button.hpp"

class BoolButton : public Button {
private:
    bool isOn;
public:
    BoolButton();
    bool getIsOn();
    void toggle();
    void draw() override;
};