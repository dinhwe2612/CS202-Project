#include "Button.hpp"

Button::Button() {
	Object::setType("BUTTON");
}

void Button::setBox(float x, float y, float width, float height, Color colorDefault, Color colorTouched, Color colorClicked) {
	buttonShape.x = x;
	buttonShape.y = y;
	buttonShape.width = width;
	buttonShape.height = height;
	colorBoxDefault = colorDefault;
	colorBoxTouched = colorTouched;
	colorBoxClicked = colorClicked;
}

void Button::setBox(float x, float y, float width, float height) {
	setBox(x, y, width, height, { 0, 0, 0, 100 }, { 0, 0, 0, 100 }, { 0, 0, 0, 100 });
}

void Button::setText(Font _font, std::string _Text, Vector2 _coordText, float _fontSize, float _spacing, Color colorDefault, Color colorTouched, Color colorClicked) {
	font = _font;
	Text = _Text;
	coordText = _coordText;
	fontSize = _fontSize;
	spacing = _spacing;
	colorTextDefault = colorDefault;
	colorTextTouched = colorTouched;
	colorTextClicked = colorClicked;
}

void Button::setTextCenter(Font _font, std::string _Text, float _fontSize, float _spacing, Color colorDefault, Color colorTouched, Color colorClicked) {
	Vector2 _szText = MeasureTextEx(_font, _Text.c_str(), _fontSize, _spacing);
	Vector2 _coordText = { buttonShape.x + buttonShape.width / 2 - _szText.x / 2, buttonShape.y + buttonShape.height / 2 - _szText.y / 2 };
	setText(_font, _Text, _coordText, _fontSize, _spacing, colorDefault, colorTouched, colorClicked);
}

void Button::draw(int &mouseCursor) {
	// int state = getState();
	Rectangle currentShape = buttonShape;
	if (isZoom) {
		if (state == DEFAULT) {

		}
		else if (state == TOUCHED) {
			currentShape.x -= 0.01 * buttonShape.width;
			currentShape.y -= 0.01 * buttonShape.height;
			currentShape.width *= 1.02;
			currentShape.height *= 1.02;
		}
		else if (state == CLICKED || state == RELEASED) {
			currentShape.x += 0.02 * buttonShape.width;
			currentShape.y += 0.02 * buttonShape.height;
			currentShape.width *= 0.96;
			currentShape.height *= 0.96;
		}
	}
	if (state == DEFAULT) {
		//DrawRectangleRec(buttonShape, colorBoxDefault);
		DrawRectangleRounded(currentShape, roundness, segments, colorBoxDefault);
		DrawTextEx(font, Text.c_str(), coordText, fontSize, spacing, colorTextDefault);
		if (drawCorner) {
			//DrawRectangleLinesEx(buttonShape, 4, colorCornerDefault);
			DrawRectangleRoundedLines(currentShape, roundness, segments, 4, colorCornerClicked);
		}
	}
	else if (state == TOUCHED) {
		//DrawRectangleRec(buttonShape, colorBoxTouched);
		DrawRectangleRounded(currentShape, roundness, segments, colorBoxTouched);
		DrawTextEx(font, Text.c_str(), coordText, fontSize, spacing, colorTextTouched);
		if (drawCorner) {
			//DrawRectangleLinesEx(buttonShape, 4, colorCornerTouched);
			DrawRectangleRoundedLines(currentShape, roundness, segments, 4, colorCornerClicked);
		}
		if (setMouse) {
			mouseCursor = MOUSE_CURSOR_POINTING_HAND;
		}
	}
	else if (state == CLICKED || state == RELEASED) {
		//DrawRectangleRec(buttonShape, colorBoxClicked);
		DrawRectangleRounded(currentShape, roundness, segments, colorBoxClicked);
		DrawTextEx(font, Text.c_str(), coordText, fontSize, spacing, colorTextClicked);
		if (drawCorner) {
			//DrawRectangleLinesEx(buttonShape, 4, colorCornerClicked);
			DrawRectangleRoundedLines(currentShape, roundness, segments, 4, colorCornerClicked);
		}
		if (setMouse) {
			mouseCursor = MOUSE_CURSOR_POINTING_HAND;
		}
	} 
	
}

void Button::draw() {
    int mouseCursor;
    draw(mouseCursor);
}

int Button::getState() {
	// if (isTouch()) {
	// 	if (state == CLICKED && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
	// 		return state = RELEASED;
	// 	} else if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
	// 		return state = CLICKED;
	// 	}
	// 	else {
	// 		return state = TOUCHED;
	// 	}
	// }
	// return state = DEFAULT;
	return state;
}

void Button::setConer(bool _drawCorner) {
	drawCorner = _drawCorner;
}

std::string Button::getText() {
	return Text;
}

void Button::setState(BoxState _state) {
	state = _state;
}

bool Button::isTouch() {
	return CheckCollisionPointRec(GetMousePosition(), buttonShape);
}