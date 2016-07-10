#include "Button.h"

Button::Button(int width) : Label(width)
{}

void Button::mousePressed(int x, int y, bool isLeft)
{
	if (!isVisible())
	{
		return;
	}

	if (isInside(x, y, getLeft(), getTop(), getWidth(), getHeight()))
	{
		if (canGetFocus())
		{
			Control::setFocus(*this);
		}

		for (auto listener : _listeners)
		{
			listener->mousePressed(*this, x, y, isLeft);
		}
	}
}

void Button::addListener(MouseListener & listener)
{
	_listeners.push_back(&listener);
}
