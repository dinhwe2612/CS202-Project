#include "CuttingBoard.hpp"

CuttingBoard::CuttingBoard() : Container() {
    
}

bool CuttingBoard::placeObjectOn(PickableObject *object) {
    if (resourcesManager->sliceable(object->getName()) && isPlaceObjectOn() == false) {
        Container::placeObjectOn(object);
        return true;
    }
    return false;
}

void CuttingBoard::cut() {
    if (resourcesManager->sliceable(name)) {
        std::string newName = resourcesManager->slice(name);
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
    }
}