#pragma once

#include "InputSupport.hpp"

#include <unordered_map>
#include <iostream>

class Setting {
private:
    std::unordered_map<InputSupport::Key, bool> cantUse;
    std::unordered_map<std::string, Sound> listOfSounds;
    std::unordered_map<std::string, Music> listOfMusics;
    Music backgroundMusic;
    std::vector<Camera3D> cameras;
    InputSupport::Key moveUp;
    InputSupport::Key moveDown;
    InputSupport::Key moveLeft;
    InputSupport::Key moveRight;
    InputSupport::Key pickUp;
    InputSupport::Key drop;
    InputSupport::Key cut_cook;
    bool isMute;
    int curMap;
    Setting();
    static Setting* instanceSetting;
public:
    static Setting* getInstance() {
        if (instanceSetting == nullptr) {
            instanceSetting = new Setting();
        }
        return instanceSetting;
    }
    InputSupport::Key getMoveUp();
    InputSupport::Key getMoveDown();
    InputSupport::Key getMoveLeft();
    InputSupport::Key getMoveRight();
    InputSupport::Key getPickUp();
    InputSupport::Key getDrop();
    InputSupport::Key getCutCook();
    bool IsMute();
    bool set(int id, int _key);
    bool set(InputSupport::Key &key1, InputSupport::Key key2);
    bool setMoveUp(InputSupport::Key);
    bool setMoveDown(InputSupport::Key);
    bool setMoveLeft(InputSupport::Key);
    bool setMoveRight(InputSupport::Key);
    bool setPickUp(InputSupport::Key);
    bool setDrop(InputSupport::Key);
    bool setCutCook(InputSupport::Key);
    void setMute(bool isMute);
    void toggleMute();
    Camera3D *getCamera();
    void setCurMap(int curMap);
    int getCurMap();
    std::string getPathMap();
    void playSound(std::string name);
    void updateMusic();
    Music getMusic(std::string name);
};