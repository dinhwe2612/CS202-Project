#include "BoolButton.hpp"

BoolButton::BoolButton() : Button() {
    isOn = false;
}

void BoolButton::toggle() {
    isOn = !isOn;
}

void BoolButton::draw() {
    if (isOn && getState() == DEFAULT) {
        setState(TOUCHED);
    }
    Button::draw();
}

bool BoolButton::getIsOn() {
    return isOn;
}