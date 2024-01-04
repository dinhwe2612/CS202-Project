#include "Setting.hpp"

Setting* Setting::instanceSetting = nullptr;

Setting::Setting() {
    cameras = {
    (Camera3D) { 
        (Vector3){ -10.0f, 13.0f, 18.0f }, 
        (Vector3){ 0.0f, 0.0f, 0.0f }, 
        (Vector3){ 0.0f, 90.0f, 0.0f }, 
        40.0f, 
        CAMERA_PERSPECTIVE
    },
    (Camera3D) {
        (Vector3){ 6.0f, 18.0f, 15.0f }, 
        (Vector3){ 1.0f, 0.0f, 0.0f }, 
        (Vector3){ 0.0f, 90.0f, 0.0f }, 
        40.0f,
        CAMERA_PERSPECTIVE
    },
    (Camera3D) {
        (Vector3){ -1.0f, 6.0f, 10.0f },// position
        (Vector3){ -1.0f, 0.8f, -0.4f },// target
        (Vector3){ 0.0f, 1.0f, 0.0f },// up
        14.0f,// fovy
        CAMERA_PERSPECTIVE// projection
    }
    };
    setMoveUp(InputSupport::Key::W);
    setMoveDown(InputSupport::Key::S);
    setMoveLeft(InputSupport::Key::A);
    setMoveRight(InputSupport::Key::D);
    setPickUp(InputSupport::Key::E);
    setDrop(InputSupport::Key::Q);
    setCutCook(InputSupport::Key::SPACE);
    curMap = 2;
}

bool Setting::set(int id, int _key) {
    InputSupport::Key key = (InputSupport::Key)_key;
    if (cantUse[key]) {
        return false;
    }
    cantUse[key] = true;
    switch(id) {
        case 2:
            cantUse[cut_cook] = false;
            cut_cook = key;
            break;
        case 3:
            cantUse[pickUp] = false;
            pickUp = key;
            break;
        case 4:
            cantUse[drop] = false;
            drop = key;
            break;
        case 5:
            cantUse[moveUp] = false;
            moveUp = key;
            break;
        case 6:
            cantUse[moveDown] = false;
            moveDown = key;
            break;
        case 7:
            cantUse[moveLeft] = false;
            moveLeft = key;
            break;
        case 8:
            cantUse[moveRight] = false;
            moveRight = key;
            break;
    }
    return true;
}

InputSupport::Key Setting::getMoveUp() {
    return moveUp;
}

InputSupport::Key Setting::getMoveDown() {
    return moveDown;
}

InputSupport::Key Setting::getMoveLeft() {
    return moveLeft;
}

InputSupport::Key Setting::getMoveRight() {
    return moveRight;
}

InputSupport::Key Setting::getPickUp() {
    return pickUp;
}

InputSupport::Key Setting::getDrop() {
    return drop;
}

InputSupport::Key Setting::getCutCook() {
    return cut_cook;
}

bool Setting::IsMute() {
    return isMute;
}

bool Setting::set(InputSupport::Key &key1, InputSupport::Key key2) {
    if (cantUse[key2]) {
        return false;
    }
    cantUse[key1] = false;
    cantUse[key2] = true;
    key1 = key2;
    return true;
}

bool Setting::setMoveUp(InputSupport::Key key) {
    return set(moveUp, key);
}

bool Setting::setMoveDown(InputSupport::Key key) {
    return set(moveDown, key);
}

bool Setting::setMoveLeft(InputSupport::Key key) {
    return set(moveLeft, key);
}

bool Setting::setMoveRight(InputSupport::Key key) {
    return set(moveRight, key);
}

bool Setting::setPickUp(InputSupport::Key key) {
    return set(pickUp, key);
}

bool Setting::setDrop(InputSupport::Key key) {
    return set(drop, key);
}

bool Setting::setCutCook(InputSupport::Key key) {
    return set(cut_cook, key);
}

void Setting::setMute(bool isMute) {
    this->isMute = isMute;
}

void Setting::toggleMute() {
    isMute = !isMute;
}

Camera3D *Setting::getCamera() {
    return &cameras[curMap];
}

void Setting::setCurMap(int curMap) {
    this->curMap = curMap;
}

std::string Setting::getPathMap() {
    return "../resources/map" + std::to_string(curMap + 1);
}