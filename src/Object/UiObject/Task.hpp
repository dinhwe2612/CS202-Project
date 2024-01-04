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
    Color timeLineColorFrom = { 0, 128, 0, 255 };
    Color timeLineColorTo = { 255, 0, 0, 255 };
    Color timeLineColorCurrent = timeLineColorFrom;
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