#include "raylib-cpp.hpp"

#include <object.hpp>

enum CrateType {
    LID,
    ONIONS,
    POTATOES,
    STEAK,
    TOMATOES,
    LETTUCE,
    HAM,
    CHEESE,
    CARROTS,
    BUNS,
    EMPTY
};
static std::map<std::string, CrateType> listOfCrates {
    {"LID", LID},
    {"ONIONS", ONIONS},
    {"POTATOES", POTATOES},
    {"STEAK", STEAK},
    {"TOMATOES", TOMATOES},
    {"LETTUCE", LETTUCE},
    {"HAM", HAM},
    {"CHEESE", CHEESE},
    {"CARROTS", CARROTS},
    {"BUNS", BUNS},
    {"EMPTY", EMPTY}
};

class Crate : public Object3D {
private:
    CrateType type;
public:
};