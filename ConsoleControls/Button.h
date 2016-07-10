#pragma once

#include <string>

#include "Label.h"

using namespace std;

class Button : public Label
{
public:
	Button(int width);
	virtual ~Button() = default;

	virtual void mousePressed(int x, int y, bool isLeft);
	void addListener(struct MouseListener &listener);

private:
	vector<struct MouseListener*> _listeners;
};

struct MouseListener
{
	virtual void mousePressed(Button &b, int x, int y, bool isLeft) = 0;
};