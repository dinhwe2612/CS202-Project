#pragma once
#include "raylib-cpp.hpp"

class Object {
protected:
    bool isActivate = false;
    bool isSelected = false;
public:
    explicit Object();
    ~Object();
    virtual void draw() = 0;
};

class Object2D : public Object {
protected:
    Vector2 position;
public:
    explicit Object2D();
    ~Object2D();
    virtual void draw();
    virtual Vector2 getPosition() const;
    virtual void setPosition(const Vector2 &position);
};

class Mediator;

class Object3D : public Object {
protected:
    Vector3 position;
    Model model;
    Mediator *mediator;

    unsigned int animCurFrame = 0;
    unsigned int animMaxFrame = 0;
    ModelAnimation *anim = nullptr;

    float scale;
    int curDirection = 0;
    Vector3 ownOx = {1, 0, 0}, ownOy = {0, 1, 0}, ownOz = {0, 0, 1};
    void rotate(Vector3 axis, float angle);
public:
    enum Direction { UP = 180, DOWN = 0, LEFT  = 270, RIGHT = 90 };
    enum Axis { X, Y, Z };
    
    explicit Object3D();
    ~Object3D();
    
    void draw() override;
    void rotate(const Axis axis, float angle);
    void move(const Vector3 offset);
    void setMediator(Mediator *mediator);
    void setModel(const Model &model);
    void setModel(const std::string path);
    void setScale(float scale);
    Vector3 getPosition() const;
    void setPosition(const Vector3 &position);
    void setCurrentDirection(int curDirection);
};
