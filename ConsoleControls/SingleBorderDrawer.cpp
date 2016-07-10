#include "SingleBorderDrawer.h"

SingleBorderDrawer::SingleBorderDrawer()
{
	_borders[0] = 218;
	_borders[1] = 191;
	_borders[2] = 196;
	_borders[3] = 179;
	_borders[4] = 192;
	_borders[5] = 217;
}

void SingleBorderDrawer::draw(Graphics & g, int left, int top, int width, int height) const
{
	if (top > 0)
	{
		if (left > 0)
		{
			g.write(left - 1, top - 1, string("") + _borders[0]);
		}

		g.write(left, top - 1, string(width, _borders[2]) + _borders[1]);
	}

	for (int h = 0; h < height; h++)
	{
		if (left > 0)
		{
			g.write(left - 1, top + h, string(1, _borders[3]));
		}
		g.write(left + width, top + h, string(1, _borders[3]));
	}

	if (left > 0)
	{
		g.write(left - 1, top + height, string("") + _borders[4]);
	}

	g.write(left, top + height, string(width, _borders[2]) + _borders[5]);
}
