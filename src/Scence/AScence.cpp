#include "AScence.hpp"

AScence::AScence() {
    
}

AScence::~AScence() {
    
}

void AScence::triggerInputActions() {
    std::unordered_map<int,std::vector<std::function<void()>>>::iterator itKey;

    for(auto const &key : inputSp.getKeysDown()) {
        itKey = listOfkeys.find(key);
        if (itKey != listOfkeys.end()) {
            for (auto const &func : itKey->second) {
                func();
            }
        }
    }

    if (inputSp.isMouseDown()) {
        itKey = listOfkeys.find(InputSupport::PRESSED);
        if (itKey != listOfkeys.end()) {
            for (auto const &func : itKey->second) {
                func();
            }
        }
    }
    if (inputSp.isMouseReleased()) {
        itKey = listOfkeys.find(InputSupport::RELEASED);
        if (itKey != listOfkeys.end()) {
            for (auto const &func : itKey->second) {
                func();
            }
        }
    }
}

void AScence::setInputFunction(InputSupport::Key key, std::function<void()> func) {
    std::unordered_map<int,std::vector<std::function<void()>>>::iterator itKey;

    itKey = listOfkeys.find(key);
    if (itKey != listOfkeys.end()) {
        itKey->second.push_back(func);
    }
}