#include "UiSceneHighScore.hpp"

UiSceneHighScore::UiSceneHighScore() : UiScene() {
    buttons.push_back(std::unique_ptr<Button>(new Button()));
    buttons.back()->setBox(44.9, 52.8, 175.9, 175.9, 
                            { 0, 0, 0, 0 }, 
                            { 0, 0, 0, 0 }, 
                            { 255, 255, 255, 100 });
    freopen("highscore.txt", "r", stdin);
    box = {
        (Rectangle){ 1032.9, 549.4, 640.7, 164.1 },
        (Rectangle){ 1032.9, 747.2, 640.7, 164.1 },
        (Rectangle){ 1032.9, 945, 640.7, 164.1 },
        (Rectangle){ 1032.9, 1148.6, 640.7, 164.1 }
    };
    std::ifstream fin("../resources/data/highscore.txt");
    int point;
    while(fin >> point) {
        highScore.push_back(point);
    }
    fin.close();
    setInputFunction(InputSupport::MOUSE_LEFT, InputSupport::RELEASED, [this]() {
        if (buttons[0]->isTouch()) {
            state = Scenes::MENU;
        }
    });
    
}

void UiSceneHighScore::eventScene() {

}

void UiSceneHighScore::draw() {
    for(auto& button : buttons) {
        button->draw();
    }
    DrawTextureEx(resourcesManager->getTexture("SceneHighScore"), { 0, 0 }, 0, 1, WHITE);
    for(int i = 0; i < highScore.size(); ++i) {
        // center text
        int x = box[i].x + box[i].width / 2 - MeasureTextEx(resourcesManager->getFont("cocktail_italic_shadow"), std::to_string(highScore[i]).c_str(), 200, 1).x / 2;
        int y = box[i].y + box[i].height / 2 - MeasureTextEx(resourcesManager->getFont("cocktail_italic_shadow"), std::to_string(highScore[i]).c_str(), 200, 1).y / 2 - 30;
        DrawTextEx(resourcesManager->getFont("cocktail_italic_shadow"), std::to_string(highScore[i]).c_str(), { x, y }, 200, 1, BLACK);
    }
}