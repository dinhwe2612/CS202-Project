#include <raylib-cpp.hpp>

#include "object.hpp"
#include "InputBox.hpp"
#include "Button.hpp"

#include <fstream>
#include <iostream>

class AdjustObject3D {
private:
    Object3D *object;
    float speedPos = 0.01;
    float speedScale = 0.00001;
    InputBox posX, posY, posZ;
    InputBox scale, rotateX, rotateY, rotateZ;
    Button save;
    
    float stringToFloat(std::string str);
public:
    AdjustObject3D();
    AdjustObject3D(Object3D *object);
    ~AdjustObject3D();
    void setModel(Object3D *object);
    void printToFile(std::string path);
    void modify();
    friend class Object3D;
};