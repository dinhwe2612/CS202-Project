#include "AScene.hpp"

AScene::AScene() {
    resourcesManager = ResourcesManager::getInstance();
    state = DEFAULT;
}

AScene::~AScene() {
    
}

void AScene::triggerInputActions() {
    std::unordered_map<std::pair<int,int>,std::function<void()>>::iterator itKey;

    for(auto const &key : inputSp.getKeysPressed()) {
        itKey = listOfkeys.find({ key, InputSupport::PRESSED });
        if (itKey != listOfkeys.end()) {
            itKey->second();
        }
    }

    for(auto const &key : inputSp.getKeysDown()) {
        itKey = listOfkeys.find({ key, InputSupport::DOWN });
        if (itKey != listOfkeys.end()) {
            itKey->second();
        }
    }

    for(auto const &key : inputSp.getKeysReleased()) {
        itKey = listOfkeys.find({ key, InputSupport::RELEASED });
        if (itKey != listOfkeys.end()) {
            itKey->second();
        }
    }


    if (inputSp.isMousePressed()) {
        itKey = listOfkeys.find({ InputSupport::MOUSE_LEFT, InputSupport::PRESSED });
        if (itKey != listOfkeys.end()) {
            itKey->second();
        }
    }
    if (inputSp.isMouseDown()) {
        itKey = listOfkeys.find({ InputSupport::MOUSE_LEFT, InputSupport::DOWN });
        if (itKey != listOfkeys.end()) {
            itKey->second();
        }
    }
    if (inputSp.isMouseReleased()) {
        itKey = listOfkeys.find({ InputSupport::MOUSE_LEFT, InputSupport::RELEASED });
        if (itKey != listOfkeys.end()) {
            itKey->second();
        }
    }
}

void AScene::setInputFunction(InputSupport::Key key, InputSupport::InputType type, std::function<void()> func) {
    std::unordered_map<std::pair<int,int>,std::function<void()>>::iterator itKey;

    itKey = listOfkeys.find({ key, type });
    if (itKey != listOfkeys.end()) {
        itKey->second = func;
    }
}