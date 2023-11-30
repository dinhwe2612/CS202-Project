#pragma once
#include "raylib-cpp.hpp"

#include <string>
#include <vector>
#include <algorithm>

class InputBox {
private:
    std::string currentInput = "";// current input string
    Font font;
    Rectangle inputShape;
    Vector2 coordText;
    float szText, spacing;
    Color colorBoxDefault = RAYWHITE, colorBoxTouched = RAYWHITE, colorBoxTyping = RAYWHITE;
    Color colorTextDefault = BLACK, colorTextTouched = BLACK, colorTextTyping = BLACK;
    Color colorCornerDefault = { 113, 201, 206, 255 };
    Color colorSelected = { 119, 136, 153, 255 };
    int MAX_SIZE = 0;// max size of input
    float roundness = 0, segments = 0;// for drawing corner of input box
    bool isTyping = false;// check if the input box is ready to type
    bool drawCorner = true;// draw corner of input box
    bool add = false;// add | to the end of currentInput
    bool noTyping = false;// prevent from typing
    int timeline = 0;// for blinking cursor
    int posCursor = 0;// position of cursor
    int posL = 0;// first position in currentInput would be drawn
    int posR = 0;// last position in currentInput would be drawn
    int countConsecutiveKey = 0;// count consecutive key pressed
    int lastKey = 0;// last key pressed
    int prePosCursor = 0;// previous position of cursor
    long long isMouseDown = 0;// check if mouse is pressed
    bool selected = false;// selected text
    std::vector<float> coordDisplay;
    float lengthText = 0;// length of text limit
    enum State { DEFAULT, TOUCHED, TYPING };
public:
    void construct(float x, float y, float width, float height, Font _font, Vector2 _coordText, int _szText, float _spacing, int _MAX_SIZE);
    void setColorBox(Color colorDefault, Color colorTouched, Color colorTyping);
    void setColorText(Color colorDefault, Color colorTouched, Color colorTyping);
    void drawText(Color color);
    void draw();
    bool checkCollisionText(int l, int r);
    bool isClicked();
    bool isEntered();
    int getState();
    void reset();
    void manipulate();
    void balance();
    void mouseOperation();
    void removeSelected();
    void setContent(std::string content);
    std::string getInput();
};
