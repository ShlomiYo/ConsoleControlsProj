#pragma once

#include "BorderDrawer.h"

class SingleBorderDrawer : public BorderDrawer
{
public:
	SingleBorderDrawer();

	virtual void draw(Graphics &g, int left, int top, int width, int height) const;

protected:
	char _borders[6];
};
