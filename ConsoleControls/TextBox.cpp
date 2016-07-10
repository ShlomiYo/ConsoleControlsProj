#include "TextBox.h"



TextBox::TextBox(int width) : Label(width), _cursorPosition(0)
{
	setCanGetFocus(true);
}

void TextBox::draw(Graphics & g, int left, int top, size_t layer) const
{
	if (!isVisible())
	{
		return;
	}

	Label::draw(g, left, top, layer);

	if (layer == getLayer() + 1 && this == getFocus())
	{
		Control::draw(g, left, top, layer);
		g.setCursorVisibility(true);
		g.moveTo(getLeft() + left + _cursorPosition, getTop() + top);
	}
}

void TextBox::mousePressed(int x, int y, bool isLeft)
{
	if (!isLeft || !isVisible())
	{
		return;
	}

	if (isInside(x, y, getLeft(), getTop(), getWidth(), getHeight()))
	{
		//g.write(getLeft() + left, getTop() + top, _value + string(getWidth() - _value.size(), ' '));

		Control::setFocus(*this);

		_cursorPosition = ((x - getLeft()) >= getText().size()) ? getText().size() - 1 : x - getLeft();
	}
}

void TextBox::keyDown(int keyCode, char character)
{
	if ((this != Control::getFocus()) || !isVisible())
	{
		return;
	}

	bool deleteChar = false;
	int currentCursorPosition = _cursorPosition;

	switch (keyCode)
	{
	case VK_BACK:
		if (_cursorPosition > 0)
		{
			--_cursorPosition;
		}
		deleteChar = true;
		break;

	case VK_DELETE:
		deleteChar = true;
		break;

	case VK_RETURN:
		return;

	case VK_LEFT:
		if (_cursorPosition > 0)
		{
			--_cursorPosition;
		}
		return;

	case VK_RIGHT:
		if (_cursorPosition < getText().size() - 1)
		{
			++_cursorPosition;
		}
		return;

	default:
		break;
	}

	if (deleteChar)
	{
		if (currentCursorPosition < getText().size())
		{
			string newText = getText();
			newText = newText.substr(0, currentCursorPosition) + newText.substr(currentCursorPosition + 1, newText.size() - currentCursorPosition);
			setText(newText);
		}
	}
	else if (character != '\0')
	{
		string newText;
		if (currentCursorPosition < getText().size())
		{
			newText = getText().substr(0, currentCursorPosition) + character + getText().substr(currentCursorPosition+1, getText().size() - currentCursorPosition);
		}
		else
		{
			newText = getText() + character;
		}

		setText(newText);

		if (_cursorPosition < getWidth()-1)
		{
			++_cursorPosition;
		}
	}
}
