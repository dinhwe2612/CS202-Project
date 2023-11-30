#include "AdjustObject.hpp"

AdjustObject3D::AdjustObject3D() {

}

AdjustObject3D::AdjustObject3D(Object3D *object) {
    this->object = object;
}

AdjustObject3D::~AdjustObject3D() {

}

void AdjustObject3D::setModel(Object3D *object) {
    this->object = object;
    posX.construct(10, 10, 100, 30, GetFontDefault(), { 10, 10 }, 20, 1, 10);
    posX.setContent(std::to_string(object->getPosition().x));
    posY.construct(10, 50, 100, 30, GetFontDefault(), { 10, 50 }, 20, 1, 10);
    posY.setContent(std::to_string(object->getPosition().y));
    posZ.construct(10, 90, 100, 30, GetFontDefault(), { 10, 90 }, 20, 1, 10);
    posZ.setContent(std::to_string(object->getPosition().z));
    scale.construct(10, 130, 100, 30, GetFontDefault(), { 10, 130 }, 20, 1, 10);
    scale.setContent(std::to_string(object->getScale()));
    rotateX.construct(10, 170, 100, 30, GetFontDefault(), { 10, 170 }, 20, 1, 10);
    rotateY.construct(10, 210, 100, 30, GetFontDefault(), { 10, 210 }, 20, 1, 10);
    rotateZ.construct(10, 250, 100, 30, GetFontDefault(), { 10, 250 }, 20, 1, 10);

}

void AdjustObject3D::printToFile(std::string path) {
    if (!object) return;
    std::ofstream file(path);
    
}

void AdjustObject3D::modify() {
    if (!object) return;
    posX.draw();
    posY.draw();
    posZ.draw();
    scale.draw();
    rotateX.draw();
    rotateY.draw();
    rotateZ.draw();
    if (posX.isEntered()) {
        object->setPosition({ stringToFloat(posX.getInput()), object->getPosition().y, object->getPosition().z });
    }
    if (posY.isEntered()) {
        object->setPosition({ object->getPosition().x, std::stof(posY.getInput()), object->getPosition().z });
    }
    if (posZ.isEntered()) {
        object->setPosition({ object->getPosition().x, object->getPosition().y, std::stof(posZ.getInput()) });
    }
    if (scale.isEntered()) {
        object->setScale(stringToFloat(scale.getInput()));
    }
    if (rotateX.isEntered()) {
        object->rotate(Axis::X, stringToFloat(rotateX.getInput()) * DEG2RAD);
        rotateX.setContent("");
    }
    if (rotateY.isEntered()) {
        object->rotate(Axis::Y, stringToFloat(rotateY.getInput()) * DEG2RAD);
        rotateY.setContent("");
    }
    if (rotateZ.isEntered()) {
        object->rotate(Axis::Z, stringToFloat(rotateZ.getInput()) * DEG2RAD);
        rotateZ.setContent("");
    }
    if (IsKeyDown(KEY_S)) {
        object->move({ 0, 0, speedPos });
        posZ.setContent(std::to_string(object->getPosition().z));
    }
    if (IsKeyDown(KEY_W)) {
        object->move({ 0, 0, -speedPos });
        posZ.setContent(std::to_string(object->getPosition().z));
    }
    if (IsKeyDown(KEY_A)) {
        object->move({ -speedPos, 0, 0 });
        posX.setContent(std::to_string(object->getPosition().x));
    }
    if (IsKeyDown(KEY_D)) {
        object->move({ speedPos, 0, 0 });
        posX.setContent(std::to_string(object->getPosition().x));
    }
    if (IsKeyDown(KEY_Q)) {
        object->move({ 0, -speedPos, 0 });
    }
    if (IsKeyDown(KEY_E)) {
        object->move({ 0, speedPos, 0 });
    }
    if (IsKeyDown(KEY_T)) {
        object->incScale(-speedScale);
    }
    if (IsKeyDown(KEY_Y)) {
        object->incScale(speedScale);
    }

}

float AdjustObject3D::stringToFloat(std::string str) {
    float res = 0;
    int i = 0;
    bool isNegative = false;
    if (str[0] == '-') {
        isNegative = true;
        i++;
    }
    while (i < str.length() && str[i] != '.') {
        res = res * 10 + str[i] - '0';
        i++;
    }
    if (i == str.length()) return res * (isNegative ? -1 : 1);
    i++;
    float tmp = 0.1;
    while (i < str.length()) {
        res += tmp * (str[i] - '0');
        tmp /= 10;
        i++;
    }
    return res * (isNegative ? -1 : 1);
}