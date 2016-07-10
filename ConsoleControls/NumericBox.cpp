#include "Button.h"

#include "NumericBox.h"

struct NumericBoxUpdateListener : public MouseListener
{
	NumericBoxUpdateListener(NumericBox &box) : _box(box)
	{}

	void mousePressed(Button &b, int x, int y, bool isLeft)
	{
		if (b.getText() == "+")
		{
			_box.setValue(_box.getValue() + 1);
		}
		if (b.getText() == "-")
		{
			_box.setValue(_box.getValue() - 1);
		}
	}
private:
	NumericBox &_box;
};

NumericBox::NumericBox(int width, int min, int max) :
	Panel(TEXT_HEIGHT, width),
	_btnMinus(1), _lblValue(width - 2), _btnPlus(1),
	_value(min), _min(min), _max(max)
{
	if (width < 3)
	{
		throw "NumericBox width must be at least 3";
	}
	
	auto updateListener = new NumericBoxUpdateListener(*this);

	_btnMinus.setText("-");
	_btnMinus.addListener(*updateListener);
	_btnPlus.setText("+");
	_btnPlus.addListener(*updateListener);

	addControl(_btnMinus, 0, 0);
	addControl(_lblValue, 1, 0);
	addControl(_btnPlus, width-1, 0);
}

void NumericBox::setValue(int value)
{
	if (value > _max)
	{
		_value = _max;
	}
	else if (value < _min)
	{ 
		_value = _min;
	}
	else
	{
		_value = value;
	}

	_lblValue.setText(to_string(_value));
}

int NumericBox::getValue() const
{
	return _value;
}

int NumericBox::getMin() const
{
	return _min;
}

int NumericBox::getMax() const
{
	return _max;
}

void NumericBox::addControl(Control & control, int left, int top)
{
	Panel::addControl(control, left, top);
}

void NumericBox::setLayer(size_t layer)
{
	for (auto c : _controls)
	{
		c->setLayer(layer);
	}
	Panel::setLayer(layer);
}