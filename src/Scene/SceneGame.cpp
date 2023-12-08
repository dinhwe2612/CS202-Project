#include "SceneGame.hpp"

SceneGame::SceneGame() {
    // Create camera
    camera.position = (Vector3){ -10.0f, 13.0f, 18.0f };//-10 13 18
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 90.0f, 0.0f };
    camera.fovy = 40.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    InputObject::input("../resources/map", objects);
    for(auto &object : objects) {
        object->setMediator(objectMediator);
    }
    // Set input functions
    Player *player = dynamic_cast<Player *>(objects.back().get());
    std::vector<InputSupport::Key> controllerPlayer = {InputSupport::UP_ARROW, InputSupport::DOWN_ARROW, InputSupport::LEFT_ARROW, InputSupport::RIGHT_ARROW};
    std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
    for(int i = 0; i < controllerPlayer.size(); ++i) {
        setInputFunction(controllerPlayer[i], InputSupport::DOWN, [this, player, i, directions](){ 
            if (player->isColliding(directions[i], objects) == false) {
                player->moveDirection(directions[i]); 
            } else {
                player->rotate(Y, (directions[i] - player->getCurDirection()) * DEG2RAD);
                player->setCurrentDirection(directions[i]);
            }
        });
    }
    objectMediator = new ObjectMediator(objects);
    setInputFunction(InputSupport::E, InputSupport::PRESSED, [this]() {
        objectMediator->notify({"pick"});
    });
    setInputFunction(InputSupport::Q, InputSupport::PRESSED, [this]() {
        objectMediator->notify({"drop"});
    });
    setInputFunction(InputSupport::SPACE, InputSupport::PRESSED, [this]() {
        objectMediator->notify({"cut_cook"});
    });
}

SceneGame::~SceneGame() {

}

void SceneGame::draw() {
    triggerInputActions();
    Rectangle rec = { -9, 0, 2, 2 };
    BeginMode3D(camera);
        for (auto &object : objects) {
            if (object->isActivate()) object->draw();
            if (object->getType() == ObjectType::Type::OBJECT3D || object->getType() == ObjectType::CONTAINER) {
                Object3D *object3d = dynamic_cast<Object3D*>(object.get());
                if (object3d->isCollisionable() && !object3d->isActivate()) {
                    Rectangle rec = object3d->getCollisionBox();
                    DrawCube((Vector3){ rec.x + rec.width/2, 1, rec.y + rec.height/2 }, rec.width, 2, rec.height, { 255, 0, 0, 100 });
                } 
            }
        }
    EndMode3D();
}