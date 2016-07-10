#pragma once

#include <string>

#include "Label.h"

using namespace std;

class TextBox : public Label
{
public:
	TextBox(int width);
	virtual ~TextBox() = default;

	// Callbacks
	virtual void draw(Graphics &g, int left, int top, size_t layer) const;
	virtual void mousePressed(int x, int y, bool isLeft);
	virtual void keyDown(int keyCode, char character);

private:
	int _cursorPosition;
};

