#include "GasStove.hpp"

GasStove::GasStove() :Container() {

}

void GasStove::cook() {
    if (resourcesManager->fryable(name)) {
        std::string newName = resourcesManager->fry(name);
        std::cout << newName << '\n';
        std::string path = resourcesManager->pathPickableObject(newName);
        if (path == "") {
            setScale(1);
            setPosition({ 0, 0.6, 0 });
            setName(newName);
            if (Setting::getInstance()->getCurMap() == 2) {
                setScale(0.15);
                setPosition({ 0, 0.26, 0 });
            }
            return;
        }
        std::ifstream fin(resourcesManager->pathPickableObject(newName));
        std::string inst;
        while(fin >> inst) {
            if (inst == "NAME") {
                std::string name; fin >> name;
                setName(name);
            } else if (inst == "SCALE") {
                float scale; fin >> scale;
                setScale(scale);
            } else if (inst == "POSITION") {
                float x, y, z; fin >> x >> y >> z;
                setPosition({ x, y, z });
            } else if (inst == "ROTATE") {
                char axis; fin >> axis;
                float angle; fin >> angle;
                switch (axis) {
                case 'X':
                    rotate(Axis::X, angle);
                    break;
                case 'Y':
                    rotate(Axis::Y, angle);
                    break;
                case 'Z':
                    rotate(Axis::Z, angle);
                    break;
                }
            }
        }
        fin.close();
        if (Setting::getInstance()->getCurMap() == 2) {
            setScale(0.15);
            setPosition({ 0, 0.26, 0 });
        }
    }
}

bool GasStove::placeObjectOn(PickableObject *object) {
    if (resourcesManager->fryable(object->getName()) && isPlaceObjectOn() == false) {
        Container::placeObjectOn(object);
        return true;
    }
    return false;
}