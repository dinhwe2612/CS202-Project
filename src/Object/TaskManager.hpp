#pragma once 

#include "../object.hpp"
#include "../Object/UiObject/Task.hpp"

#include <vector>
#include <memory>
#include <iostream>

class TaskManager : public Object3D {
private:
    std::vector<std::shared_ptr<Task>> tasks;
    int maxTasks;
    int numTasks;
    float distanceBetweenTasks;
    float timeLimit;
    float remaining;
    float timeAddNewTask;
    float curTimeAddNewTask;
    float durationTask;
    float totalPoints;
    float remainingTimeAddNewTask();
public:
    TaskManager();
    ~TaskManager();
    void draw() override;
    void update();
    bool addTask();
    void addPoints(float points);
    bool submitTask(std::string name);
    float remainingTime();
    void pause();
};