#include "TaskManager.hpp"

TaskManager::TaskManager() {
    resourcesManager = ResourcesManager::getInstance();
    timeLimit = 60;
    timeAddNewTask = 1;
    durationTask = 20;
    totalPoints = 0;
    distanceBetweenTasks = 500;
    maxTasks = 3;
    numTasks = 0;
    remaining = timeLimit;
    curTimeAddNewTask = 0;
}

TaskManager::~TaskManager() {

}

bool TaskManager::addTask() {
    if (numTasks >= maxTasks || remainingTimeAddNewTask() < timeAddNewTask) return false;
    tasks.push_back(std::make_shared<Task>(resourcesManager->getRandomTask(), durationTask));
    resourcesManager->resetTimer(getName());
    curTimeAddNewTask = 0;
    ++numTasks;
    return true;
}

bool TaskManager::submitTask(std::string name) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if ((*it)->getName() == name) {
            addPoints((*it)->getPoints());
            (*it)->submit();
            return true;
        }
    }
    return false;
}

void TaskManager::addPoints(float points) {
    totalPoints += points;
}

void TaskManager::update() {
    addTask();
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        (*it)->update();
        if ((*it)->finishedRemoval()) {
            tasks.erase(it);
            --it;
            --numTasks;
            break;
        }
    }
}


void TaskManager::draw() {
    Vector2 position = { -50, 0 };
    for (auto& task : tasks) {
        task->draw(position);
        position.x += distanceBetweenTasks;
    }
    DrawTextureEx(resourcesManager->getTexture("timer"), { 2500, 1350 }, 0, 0.8, WHITE);
    float curRemainingTime = remainingTime();
    int minutes = curRemainingTime / 60;
    int seconds = curRemainingTime - minutes * 60;
    std::string time = std::to_string(minutes) + ":" + std::to_string(seconds);
    Vector2 posTime = resourcesManager->centerText(resourcesManager->getFont("cocktail_italic"), { 2800, 1700 }, time, 200, 0);
    DrawTextEx(resourcesManager->getFont("cocktail_italic"), time.c_str(), posTime, 200, 0, WHITE);

    DrawTextureEx(resourcesManager->getTexture("coin"), { 0, 1350 }, 0, 1, { 230, 230, 230, 245 });
    std::string points = std::to_string((int)totalPoints);
    Vector2 posPoint = resourcesManager->centerText(resourcesManager->getFont("cocktail_italic_shadow"), { 180, 1500 }, points, 180, 0);
    DrawTextEx(resourcesManager->getFont("cocktail_italic_shadow"), points.c_str(), posPoint, 180, 0, RAYWHITE);
}

float TaskManager::remainingTime() {
    return remaining -= GetFrameTime();
}

float TaskManager::remainingTimeAddNewTask() {
    return curTimeAddNewTask += GetFrameTime();
}

void TaskManager::pause() {
    
}
