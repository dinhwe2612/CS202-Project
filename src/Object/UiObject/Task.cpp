#include "Task.hpp"

Task::Task(std::string name, float duration) {
    setName(name);
    this->duration = duration;
    setActivate(true);
    setScale(0.25);
    color = { 255, 255, 255, 10 };
    isCreated = true;
    isRemoved = false;
    posPointPlus = { 170, 1300 };
    recTimeLine = { 181.5, 93, 457.4, 15 };
    curTimeLine = 0;
    remaining = duration;
}

Task::~Task() {

}

void Task::draw() {
    DrawRectangle(recTimeLine.x + getPosition().x, recTimeLine.y + getPosition().y, curTimeLine, recTimeLine.height, timeLineColorCurrent);
    DrawTextureEx(resourcesManager->getTexture(getName()), getPosition(), 0, getScale(), color);
}

void Task::draw(Vector2 position) {
    setPosition(position);
    draw();
}

float Task::remainingTime() {
    return remaining -= GetFrameTime();
}

void Task::update() {
    curTimeLine = remainingTime() / duration * recTimeLine.width;
    if (isCreated) {
        if (color.a < 255) {
            color.a += 1;
        }
        else {
            isCreated = false;
        }
    }
    if (isRemoved) {
        isCreated = false;
        if (color.a > 0) {
            color.a -= 1;
        }
    }
    else {
        if (remaining <= 0) {
            isRemoved = true;
        }
    }
    // convert color from green to red
    timeLineColorCurrent.r = timeLineColorFrom.r + (timeLineColorTo.r - timeLineColorFrom.r) * (1 - remaining / duration);
    timeLineColorCurrent.g = timeLineColorFrom.g + (timeLineColorTo.g - timeLineColorFrom.g) * (1 - remaining / duration);
    timeLineColorCurrent.b = timeLineColorFrom.b + (timeLineColorTo.b - timeLineColorFrom.b) * (1 - remaining / duration);
}

bool Task::finishedRemoval() {
    return color.a <= 5;
}

void Task::submit() {
    isRemoved = true;
}

float Task::getPoints() {
    return remainingTime();
}