#include "InputSupport.hpp"

InputSupport::InputSupport() {
    
}

InputSupport::~InputSupport() {
    
}

std::vector<int> InputSupport::getKeyPressed() {
    std::vector<int> inputs;
    for(int i = 0; i < listOfkeys.size(); ++i) if (IsKeyPressed(listOfkeys[i])) {
        inputs.push_back(i);
    }
    return inputs;
}

std::vector<int> InputSupport::getKeysDown() {
    std::vector<int> inputs;
    for(int i = 0; i < listOfkeys.size(); ++i) if (IsKeyDown(listOfkeys[i])) {
        inputs.push_back(i);
    }
    return inputs;
}

bool InputSupport::isMouseDown() {
    return IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

bool InputSupport::isMouseReleased() {
    return IsMouseButtonReleased(MOUSE_LEFT_BUTTON);
}