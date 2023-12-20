#include "InputObject.hpp"

namespace InputObject {
    void input(std::string path, Object3D *&object) {
        std::ifstream fin;
        fin.open(path);
            std::string inst;
            while(fin >> inst) {
                if (inst == "POSITION") {
                    Object3D *object3d = dynamic_cast<Object3D *>(object);
                    float x, y, z;
                    fin >> x >> y >> z;
                    object3d->setPosition({ x, y, z });
                } else if (inst == "SPEED") {
                    MovableObject *object3d = dynamic_cast<MovableObject *>(object);
                    float speed;
                    fin >> speed;
                    object3d->setSpeed(speed);
                } else if (inst == "SCALE") {
                    Object3D *object3d = dynamic_cast<Object3D *>(object);
                    float scale;
                    fin >> scale;
                    object3d->setScale(scale);
                } else if (inst == "COLLISION") {
                    Object3D *object = dynamic_cast<Object3D *>(object);
                    Rectangle collisionBox;
                    fin >> collisionBox.x >> collisionBox.y >> collisionBox.width >> collisionBox.height;
                    object->setCollisionable(collisionBox);
                } else if (inst == "ACTIVATE") {
                    Object3D *object3d = dynamic_cast<Object3D *>(object);
                    bool activate;
                    fin >> activate;
                    object3d->setActivate(activate);
                } else if (inst == "TYPE") {
                    std::string type; fin >> type;
                    if (type == "PLAYER") {
                        object = new Player();
                    } else if (type == "OBJECT3D") {
                        object = new Object3D();
                    } else if (type == "PICKABLEOBJECT") {
                        object = new PickableObject();
                    }
                } else if (inst == "ROTATE") {
                    Object3D *object3d = dynamic_cast<Object3D *>(object);
                    std::string axis; fin >> axis;
                    float angle; fin >> angle;
                    angle *= DEG2RAD;
                    if (axis == "X") {
                        object3d->rotate(Axis::X, angle);
                    } else if (axis == "Y") {
                        object3d->rotate(Axis::Y, angle);
                    } else if (axis == "Z") {
                        object3d->rotate(Axis::Z, angle);
                    }
                } else if (inst == "NAME") {
                    std::string name; fin >> name;
                    object->setName(name);
                }
            }
            fin.close();
    }
    void input(std::string pathToDirectory, std::vector<std::shared_ptr<Object>> &objects) {
        // 
        std::ifstream fin;
        DIR *dir = opendir(pathToDirectory.c_str());
        if (dir == NULL) return;
        dirent *entry;
        int cnt = 0;
        while((entry = readdir(dir)) != NULL) {
            if (entry->d_name[0] == '.') {
                continue;
            } else {
                fin.open(pathToDirectory + "/" + entry->d_name);
                std::string inst;
                while(fin >> inst) {
                    if (inst == "POSITION") {
                        Object3D *object = dynamic_cast<Object3D *>(objects.back().get());
                        float x, y, z;
                        fin >> x >> y >> z;
                        object->setPosition({ x, y, z });
                    } else if (inst == "SPEED") {
                        MovableObject *object = dynamic_cast<MovableObject *>(objects.back().get());
                        float speed;
                        fin >> speed;
                        object->setSpeed(speed);
                    } else if (inst == "SCALE") {
                        Object3D *object = dynamic_cast<Object3D *>(objects.back().get());
                        float scale;
                        fin >> scale;
                        object->setScale(scale);
                    } else if (inst == "COLLISION") {
                        Object3D *object = dynamic_cast<Object3D *>(objects.back().get());
                        Rectangle collisionBox;
                        fin >> collisionBox.x >> collisionBox.y >> collisionBox.width >> collisionBox.height;
                        object->setCollisionable(collisionBox);
                    } else if (inst == "ACTIVATE") {
                        Object3D *object = dynamic_cast<Object3D *>(objects.back().get());
                        bool activate;
                        fin >> activate;
                        object->setActivate(activate);
                    } else if (inst == "TYPE") {
                        std::string type; fin >> type;
                        if (type == "PLAYER") {
                            objects.push_back(std::make_shared<Player>());
                        } else if (type == "OBJECT3D") {
                            objects.push_back(std::make_shared<Object3D>());
                        } else if (type == "CONTAINER") {
                            objects.push_back(std::make_shared<Container>());
                        } else if (type == "CUTTINGBOARD") {
                            objects.push_back(std::make_shared<CuttingBoard>());
                        } else if (type == "FOODCOOKER") {
                            objects.push_back(std::make_shared<FoodCooker>());
                        } else if (type == "GASSTOVE") {
                            objects.push_back(std::make_shared<GasStove>());
                        } else if (type == "TASKMANAGER") {
                            objects.push_back(std::make_shared<TaskManager>());
                        }
                        objects.back()->setType(type);
                    } else if (inst == "ROTATE") {
                        Object3D *object = dynamic_cast<Object3D *>(objects.back().get());
                        std::string axis; fin >> axis;
                        float angle; fin >> angle;
                        angle *= DEG2RAD;
                        if (axis == "X") {
                            object->rotate(Axis::X, angle);
                        } else if (axis == "Y") {
                            object->rotate(Axis::Y, angle);
                        } else if (axis == "Z") {
                            object->rotate(Axis::Z, angle);
                        }
                    } else if (inst == "NAME") {
                        std::string name; fin >> name;
                        objects.back()->setName(name);
                    }
                }
                fin.close();
            }
        }
    }
}