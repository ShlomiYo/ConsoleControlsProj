#pragma once

#include <vector>

#include "Control.h"

using namespace std;

class Panel : public Control
{
public:
	Panel(int height = 50, int width=50);
	virtual ~Panel() = default;

	virtual void getAllControls(vector<Control*>* controls);

	// Callbacks
	virtual void draw(Graphics &g, int left, int top, size_t layer) const;
	virtual void mousePressed(int x, int y, bool isLeft);
	virtual void keyDown(int keyCode, char character);

	virtual void addControl(Control& control, int left, int top);

	virtual void setForeground(Color color);

	virtual void setBackground(Color color);

protected:
	vector<Control*> _controls;
};