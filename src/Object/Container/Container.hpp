#pragma once

#include "../Object.hpp"
#include "../Pickable/PickableObject.hpp"

#include <iostream>

class Container : public Object3D {
private:
    bool placeObject = false;
public:
    Container();
    ~Container();
    virtual bool placeObjectOn(PickableObject *object);
    virtual bool removeObject();
    bool isPlaceObjectOn();
    virtual void draw() override;
};