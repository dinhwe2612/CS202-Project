#pragma once
#include "../Object/object.hpp"

#include <string>

class Button : public Object2D {
private:
    Rectangle buttonShape;
    Color colorBoxDefault = RAYWHITE, colorBoxTouched = RAYWHITE, colorBoxClicked = RAYWHITE, colorText = BLACK;
    bool drawCorner = false;

    //Box
    float roundness = 0.1, segments = 10;
    enum BoxState { DEFAULT, TOUCHED, CLICKED, RELEASED };
    int state = DEFAULT;
    bool setMouse = true;
    bool isZoom = false;

    //Text
    Font font;
    std::string Text;
    Vector2 coordText;
    float fontSize;
    float spacing;
    Color colorTextDefault = BLACK, colorTextTouched = BLACK, colorTextClicked = BLACK;
    Color colorCornerDefault = { 113, 201, 206, 255 }, colorCornerTouched = BLACK, colorCornerClicked = BLACK;
public:
    void SetBox(float x, float y, float width, float height, Color colorDefault, Color colorTouched, Color colorClicked);
    //For Button Text
    void SetText(Font _font, std::string _Text, Vector2 _coordText, float _fontSize, float _spacing, Color colorDefault, Color colorTouched, Color colorClicked);
    void DrawText(int& mouseCursor);
    void DrawText();
    int getState();
};