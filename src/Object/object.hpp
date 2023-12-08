#pragma once
#include "raylib-cpp.hpp"
#include "../ResourcesManager/ResourcesManager.hpp"

#include <map>
namespace ObjectType {
    enum Type {
        BUTTON,
        INPUTBOX,
        PLAYER,
        OBJECT3D,
        PICKABLEOBJECT,
        CONTAINER,
        CUTTINGBOARD,
        GASSTOVE,
        FOODCOOKER,
    }; 
    static std::map<std::string, Type> listOfTypes = {
        {"BUTTON", BUTTON},
        {"INPUTBOX", INPUTBOX},
        {"PLAYER", PLAYER},
        {"OBJECT3D", OBJECT3D},
        {"PICKABLEOBJECT", PICKABLEOBJECT},
        {"CONTAINER", CONTAINER},
        {"CUTTINGBOARD", CUTTINGBOARD},
        {"GASSTOVE", GASSTOVE},
        {"FOODCOOKER", FOODCOOKER},
    };
}

class IMediator;

class Object {
protected:
    std::string name;
    IMediator *mediator = nullptr;
    ResourcesManager *resourcesManager;
private:
    bool activate = false;
    bool hovered = false;
    bool pressed = false;
    ObjectType::Type type;
public:
    explicit Object();
    ~Object();
    virtual void draw() = 0;
    void setType(std::string string_type);
    void setActivate(bool activate);
    void setHovered(bool hovered);
    void setPressed(bool pressed);
    bool isActivate() const;
    bool isHovered() const;
    bool isPressed() const;
    ObjectType::Type getType() const;
    void setMediator(IMediator *mediator);
    void setName(std::string name);
    std::string getName() const;
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

enum Direction { UP = 180, DOWN = 0, LEFT  = 270, RIGHT = 90, UL = 225, UR = 135, DL = 315, DR = 45 };
enum Axis { X, Y, Z };

class Object3D : public Object {
protected:
    Model model;
    unsigned int animCurFrame = 0;
    unsigned int animMaxFrame = 0;
    ModelAnimation *anim = nullptr;
private:
    Vector3 position;
    Rectangle collisionBox;

    float scale;
    Color color = WHITE;
    Direction curDirection = DOWN;
    Vector3 ownOx = {1, 0, 0}, ownOy = {0, 1, 0}, ownOz = {0, 0, 1};

    bool modelLoaded = false;
    bool collisionable = false;

    void rotate(Vector3 axis, float angle);
public:
    
    Object3D();
    Object3D(const std::string path);
    ~Object3D();
    
    virtual void draw() override;
    virtual void update() {}
    
    void setModel(const Model &model);
    void setModel(const std::string path);
    Model getModel() const;
    bool isModelLoaded() const;
    
    void rotate(const Axis axis, float angle);
    
    void setScale(float scale);
    float getScale() const;
    
    void setPosition(const Vector3 &position);
    Vector3 getPosition() const;
    void move(const Vector3 offset);
    
    void setCurrentDirection(Direction curDirection);
    Direction getCurDirection() const;
    
    void setColor(Color color);
    
    void incScale(float add);

    void setCollisionable(Rectangle collisionBox);
    Rectangle getCollisionBox() const;
    bool isCollisionable() const;
};
