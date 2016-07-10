#pragma once

#include <string>

#include "Panel.h"

using namespace std;

class MessageBoxPanel : public Panel
{
public:
	MessageBoxPanel(int height, int width);
	virtual ~MessageBoxPanel() = default;

	virtual string getText();
	virtual void setText(string text);

	virtual string getTitle();
	virtual void setTitle(string title);

	virtual string getResult();

	virtual void show();

	virtual void setLayer(size_t layer);

protected:
	virtual void addControl(Control& control, int left, int top);

protected:
	struct AnswerListener : public MouseListener
	{
		AnswerListener(MessageBoxPanel &box) : _box(box)
		{}

		void mousePressed(Button &b, int x, int y, bool isLeft)
		{
			_box.hide();
			_box._result = b.getText();
		}

	private:
		MessageBoxPanel &_box;
		size_t _index;
	};

protected:
	Label _lblText;
	Label _lblTitle;
	string _result;
};

