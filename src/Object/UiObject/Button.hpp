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
    enum BoxState { DEFAULT, TOUCHED, CLICKED, RELEASED };
    Button();
    void setBox(float x, float y, float width, float height, Color colorDefault, Color colorTouched, Color colorClicked);
    void setBox(float x, float y, float width, float height);
    //For Button Text
    void setText(Font _font, std::string _Text, Vector2 _coordText, float _fontSize, float _spacing, Color colorDefault, Color colorTouched, Color colorClicked);
    void setTextCenter(Font _font, std::string _Text, float _fontSize, float _spacing, Color colorDefault, Color colorTouched, Color colorClicked);
    void draw(int& mouseCursor);
    void draw() override;
    int getState();
    void setState(BoxState _state);
    void setConer(bool _drawCorner);
    bool isTouch();
    std::string getText();
};