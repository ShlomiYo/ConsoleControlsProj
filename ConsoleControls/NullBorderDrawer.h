#pragma once

#include "BorderDrawer.h"

class NullBorderDrawer : public BorderDrawer
{
public:
	virtual void draw(Graphics &g, int left, int top, int width, int height) const
	{}
};
