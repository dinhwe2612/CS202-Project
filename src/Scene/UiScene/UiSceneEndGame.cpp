#include "UiSceneEndGame.hpp"

UiSceneEndGame::UiSceneEndGame() : UiScene() {
    congrats = new Gif("../resources/texture/congrats.gif", 10);
    congrats->setScale(2.5);
    congrats->setPosition({ 893, -150 });
    balloon = new Gif("../resources/texture/balloon.gif", 80);
    balloon->setScale(2.9);
    balloon->setPosition({ 0, 504.7 });
    firework = new Gif("../resources/texture/firework.gif", 50);
    firework->setScale(4.5);
    firework->setPosition({ 690, 180 });
    button = new Button();
    button->setBox(1016.3, 643, 967.3, 306.9);
    button->setTextCenter(resourcesManager->getFont("Scripto"), std::to_string(resourcesManager->getTotalPoints()), 190, 1, WHITE, { 0, 0, 0, 0 }, { 0, 0, 0, 0 });
    setInputFunction(InputSupport::MOUSE_LEFT, InputSupport::PRESSED, [this]() {
        state = Scenes::MENU;
    });
}

void UiSceneEndGame::eventScene() {
    congrats->update();
    balloon->update();
    firework->update();
}



void UiSceneEndGame::draw() {
    DrawTextureEx(resourcesManager->getTexture("SceneEndGame"), { 0, 0 }, 0, 1, WHITE);
    congrats->draw();
    balloon->draw();
    firework->draw();
    button->draw();
}