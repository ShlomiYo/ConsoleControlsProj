#include "Label.h"

Label::Label(int width) : Control(TEXT_HEIGHT, width)
{
	setCanGetFocus(false);
}

void Label::setText(string value)
{
	_text = value.substr(0, getWidth());
}

string Label::getText() const
{
	return _text;
}

void Label::draw(Graphics & g, int left, int top, size_t layer) const
{
	if (layer == getLayer() && isVisible())
	{
		Control::draw(g, left, top, layer);
		g.write(getLeft() + left, getTop() + top, _text + string(getWidth() - _text.size(), ' '));
	}
}