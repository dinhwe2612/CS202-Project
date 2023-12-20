#pragma once

#include "../Object.hpp"

#include <iostream>

class Task : public Object2D {
private:
    float startTime;
    float duration;
    float curTimeLine;
    float remaining;
    Color color;
    bool isCreated = false;
    bool isRemoved = false;
    float points;
    Vector2 posPointPlus;
    Rectangle recTimeLine;
public: 
    Task(std::string name, float duration);
    ~Task();
    void update();
    void draw() override;
    void draw(Vector2 position);
    float remainingTime();
    float getPoints();
    void submit();
    bool finishedRemoval();
};