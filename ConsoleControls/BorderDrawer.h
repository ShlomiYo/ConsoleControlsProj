#pragma once

#include "Graphics.h"

struct BorderDrawer
{
	virtual void draw(Graphics &g, int left, int top, int width, int height) const = 0;
};
