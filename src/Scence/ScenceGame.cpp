#include "ScenceGame.hpp"

ScenceGame::ScenceGame() {
    // Create player
    player = new Player();
    player->setModel("../resources/models/little_chef_overcooked_like.glb");
    player->setPosition((Vector3){0, 1.0f, 0});
    player->setSpeed(0.02f);    
    player->setScale(5);
    player->rotate(Object3D::X, -PI/2);
    setInputFunction(InputSupport::UP, [this](){ player->moveDirection(Player::UP); });
    setInputFunction(InputSupport::DOWN, [this](){ player->moveDirection(Player::DOWN); });
    setInputFunction(InputSupport::LEFT, [this](){ player->moveDirection(Player::LEFT); });
    setInputFunction(InputSupport::RIGHT, [this](){ player->moveDirection(Player::RIGHT); });
    // Create wall
    Model wallModel = LoadModel("../resources/models/WallWindow.glb");
}

ScenceGame::~ScenceGame() {

}

void ScenceGame::draw() {
    triggerInputActions();
    player->draw();
}