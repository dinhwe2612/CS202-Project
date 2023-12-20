#include "InputBox.hpp"

void InputBox::construct(float x, float y, float width, float height, Font _font, Vector2 _coordText, int _szText, float _spacing, int _MAX_SIZE) {
	inputShape = { x, y, width, height };
	font = _font;
	coordText = _coordText;
	szText = _szText;
	spacing = _spacing;
	MAX_SIZE = _MAX_SIZE;
	lengthText = inputShape.width;
}

void InputBox::setColorBox(Color colorDefault, Color colorTouched, Color colorTyping) {
	colorBoxDefault = colorDefault;
	colorBoxTouched = colorTouched;
	colorBoxTyping = colorTyping;
}

void InputBox::setColorText(Color colorDefault, Color colorTouched, Color colorTyping) {
	colorTextDefault = colorDefault;
	colorTextTouched = colorTouched;
	colorTextTyping = colorTyping;
}

void InputBox::drawText(Color color) {
	float curx = coordText.x;
	int l = prePosCursor - (add && prePosCursor < posCursor);
	int r = posCursor;
	if (!add) --l, --r;
	if (l > r) std::swap(l, r);
	++l;
	for (int i = posL; i <= posR; i++) {
		if (i < l || r < i) DrawTextEx(font, currentInput.substr(i, 1).c_str(), {curx, coordText.y}, szText, spacing, color);
		else {
			DrawTextEx(font, currentInput.substr(i, 1).c_str(), {curx, coordText.y}, szText, spacing, colorSelected);
		}
		curx += MeasureTextEx(font, currentInput.substr(i, 1).c_str(), szText, spacing).x + spacing;
	}
}

void InputBox::draw() {
	if (!noTyping) manipulate();

	if (getState() == DEFAULT) {
		//DrawRectangleRec(inputShape, colorBoxDefault);
		DrawRectangleRounded(inputShape, roundness, segments, colorBoxDefault);
		//DrawTextEx(font, currentInput.substr(posL, posR - posL + 1).c_str(), {coordText.x, coordText.y}, szText, spacing, colorTextDefault);
		drawText(colorTextDefault);
		if (drawCorner) {
			//DrawRectangleLinesEx(inputShape, 2, colorCornerDefault);
			DrawRectangleRoundedLines(inputShape, roundness, segments, 2, colorCornerDefault);
		}
	} else if (getState() == TOUCHED) {
		//DrawRectangleRec(inputShape, colorBoxTouched);
		DrawRectangleRounded(inputShape, roundness, segments, colorBoxTouched);
		//DrawTextEx(font, currentInput.substr(posL, posR - posL + 1).c_str(), {coordText.x, coordText.y}, szText, spacing, colorTextTouched);
		drawText(colorTextTouched);
		if (drawCorner) {
			//DrawRectangleLinesEx(inputShape, 2, colorCornerDefault);
			DrawRectangleRoundedLines(inputShape, roundness, segments, 2, colorCornerDefault);
		}
	} else if (getState() == TYPING) {
		//DrawRectangleRec(inputShape, colorBoxTyping);
		DrawRectangleRounded(inputShape, roundness, segments, colorBoxTyping);
		//DrawTextEx(font, currentInput.substr(posL, posR - posL + 1).c_str(), {coordText.x, coordText.y}, szText, spacing, colorTextTyping);
		drawText(colorTextTyping);
		if (drawCorner) {
			//DrawRectangleLinesEx(inputShape, 2, colorCornerDefault);
			DrawRectangleRoundedLines(inputShape, roundness, segments, 2, colorCornerDefault);
		}
	}
}

bool InputBox::isClicked() {
	if (CheckCollisionPointRec(GetMousePosition(), inputShape)) {
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			return true;
		}
	}
	return false;
}

void InputBox::reset() {
	currentInput = "";
	isTyping = false;
}

int InputBox::getState() {
	if (CheckCollisionPointRec(GetMousePosition(), inputShape)) {
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
			return TYPING;
		}
		else {
			return TOUCHED;
		}
	}
	return DEFAULT;
}

bool InputBox::checkCollisionText(int l, int r) {
	if (l > r || l < 0 || r >= currentInput.size()) return false;
	return coordText.x + MeasureTextEx(font, currentInput.substr(l, r - l + 1).c_str(), szText, spacing).x <= inputShape.x + lengthText;
}

void InputBox::manipulate() {
	if (add) {
		currentInput.erase(posCursor, 1);
	}

	timeline += 60;
	if (timeline > 5000) timeline = 0;

	add = false;

	// check if the input box is clicked
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		if (CheckCollisionPointRec(GetMousePosition(), inputShape)) {
			isTyping = true;
			add = true;
			timeline = 0;
		}
		else {
			isTyping = false;
		}
	}

	if (isTyping) {
		// ctrl + c
		if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_C)) {
			if (selected) {
				int l = prePosCursor - (add && prePosCursor < posCursor);
				int r = posCursor;
				if (!add) --l, --r;
				if (l > r) std::swap(l, r);
				if (l + 1 <= r) {
					std::string s = currentInput.substr(l + 1, r - l);
					if (s.back() == '|') s.pop_back();
					else if (s.front() == '|') s.erase(0, 1);
					SetClipboardText(s.c_str());
				}
				selected = false;
			}
		}
		// for ctrl + v
		if (IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL)) {
			if (IsKeyPressed(KEY_V)) {
				removeSelected();
				std::string clipboard = GetClipboardText();
				for(int i = 0; i < clipboard.size(); ++i) {
					if (clipboard[i] < 32 || clipboard[i] > 126) {
						clipboard.erase(i, 1);
						--i;
					}
				}
				if (clipboard.length() + currentInput.length() <= MAX_SIZE) {
					currentInput.insert(posCursor, clipboard);
					posCursor += clipboard.length();
					posR += clipboard.length();
					while (posL < posR && !checkCollisionText(posL, posR)) {
						--posR;
					}
					add = true;
					timeline = 0;
				}
			}
		}
		// for typing
		int key = GetCharPressed();
		if (key >= 32 && key <= 126 && currentInput.length() < MAX_SIZE) {
			removeSelected();
			currentInput.insert(posCursor++, 1, key);
			++posR;
			while (posL < posR && !checkCollisionText(posL, posR)) {
				--posR;
			}
			add = true;
			timeline = 0;
		}
		int key2 = GetKeyPressed();
		if (!IsKeyDown(lastKey)) countConsecutiveKey = 0;
		// for arrow keys
		key2 = (key2 == KEY_LEFT && (timeline == 540 || (timeline % 60 == 0 && countConsecutiveKey >= 4)) ? KEY_LEFT : key2);
		if (key2 == KEY_LEFT && posCursor > 0) {
			selected = false;
			if (lastKey != key2) {
				lastKey = key2;
				countConsecutiveKey = 0;
			}
			++countConsecutiveKey;
			posCursor--;
			add = true;
			timeline = 0;
		}
		key2 = (key2 == KEY_RIGHT && (timeline % 540 == 0 || (timeline % 60 == 0 && countConsecutiveKey >= 4)) ? KEY_RIGHT : key2);
		if (key2 == KEY_RIGHT && posCursor < currentInput.length()) {
			selected = false;
			if (lastKey != key2) {
				lastKey = key2;
				countConsecutiveKey = 0;
			}
			++countConsecutiveKey;
			posCursor++;
			add = true;
			timeline = 0;
		}
		bool skip = false;
		if (selected) {
			if (IsKeyPressed(KEY_BACKSPACE) || IsKeyPressed(KEY_DELETE)) {
				removeSelected();
				add = true;
				timeline = 0;
				skip = true;
			}
			selected = false;
		}

		// for backspace
		key2 = (key2 == KEY_BACKSPACE && (timeline % 540 == 0 || (timeline % 60 == 0 && countConsecutiveKey >= 4)) ? KEY_BACKSPACE : key2);
		if (!skip && key2 == KEY_BACKSPACE && currentInput.length() > 0 && posCursor) {
			if (lastKey != key2) {
				lastKey = key2;
				countConsecutiveKey = 0;
			}
			++countConsecutiveKey;
			currentInput.erase(--posCursor, 1);
			if (posCursor < 0) posCursor = 0;
			add = true;
			timeline = 0;
		}
		// for delete
		key2 = (key2 == KEY_DELETE && (timeline % 540 == 0 || (timeline % 60 == 0 && countConsecutiveKey >= 4)) ? KEY_DELETE : key2);
		if (!skip && key2 == KEY_DELETE && currentInput.length() > 0 && posCursor < currentInput.length()) {
			if (lastKey != key2) {
				lastKey = key2;
				countConsecutiveKey = 0;
			}
			++countConsecutiveKey;
			currentInput.erase(posCursor, 1);
			add = true;
			timeline = 0;
		}
	}
	balance();
	mouseOperation();
	// for cursor
	if (isTyping && (add || timeline <= 2500)) {
		currentInput.insert(posCursor, "|");
		add = true;
	}
	balance();
}

void InputBox::mouseOperation() {
	// for clicking on the input box 
	coordDisplay.clear();
	for (int i = posL; i <= posR; ++i) {
		if (i < 0 || i >= currentInput.size()) continue;
		std::string c = currentInput.substr(i, 1);
		float x = MeasureTextEx(font, c.c_str(), szText, spacing).x;
		if (coordDisplay.empty()) coordDisplay.push_back(coordText.x + x);
		else coordDisplay.push_back(coordDisplay.back() + x + spacing);
	}
	coordDisplay.push_back(99999);
	selected &= !IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
	if (isMouseDown <= 1 && !selected) prePosCursor = posCursor;
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
		Vector2 mouse = GetMousePosition();
		if (isTyping) {
			for (int i = 0; i < coordDisplay.size(); ++i) {
				if (mouse.x < coordDisplay[i]) {
					posCursor = posL + i;
					if (isMouseDown >= 6) {
						selected = true;
						if (mouse.x < coordText.x && posCursor > 0) {
							--posCursor;
						}
						else if (mouse.x > coordText.x + lengthText && posCursor < currentInput.size()) {
							++posCursor;
						}
					}
					add = true;
					break;
				}
			}
		}
		++isMouseDown;
	} else isMouseDown = 0;
}

void InputBox::removeSelected() {
	if (selected) {
		selected = false;
		int l = prePosCursor - (add && prePosCursor < posCursor);
		int r = posCursor;
		if (!add) --l, --r;
		if (l > r) std::swap(l, r);
		if (l + 1 <= r) {
			currentInput.erase(l + 1, r - l);
			posCursor = l + 1;
			posR = posCursor;
			while (posL < posR && !checkCollisionText(posL, posR)) {
				--posR;
			}
		}
	}
}

void InputBox::balance() {
	// for text drawing
	if (posL > posCursor) {
		posL = posCursor;
		while (posL < posR && !checkCollisionText(posL, posR)) {
			--posR;
		}
	}
	else if (posR < posCursor) {
		posR = posCursor;
		while (posL < posR && !checkCollisionText(posL, posR)) {
			++posL;
		}
	}
	posR = std::min(posR, (int)currentInput.size() - 1);
	while (checkCollisionText(posL - 1, posR)) {
		--posL;
	}
	while (checkCollisionText(posL, posR + 1)) {
		++posR;
	}
}

std::string InputBox::getInput() {
	std::string ans;
	for (char &i : currentInput) {
		if (i != '|') ans.push_back(i);
	}
	return ans;
}

void InputBox::setContent(std::string content) {
	currentInput = content;
	posCursor = content.size();
	posL = 0;
	posR = content.size() - 1;
	while (posL < posR && !checkCollisionText(posL, posR)) {
		++posL;
	}
}

bool InputBox::isEntered() {
	if (IsKeyPressed(KEY_ENTER) && isTyping) {
		isTyping = false;
		return true;
	}
	return false;
}