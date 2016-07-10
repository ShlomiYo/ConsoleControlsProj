#include "RadioList.h"

RadioList::RadioList(int height, int width, vector<string> options) :
	CheckList(height, width, options)
{}

size_t RadioList::getSelectedIndex() const
{
	if (_selectedIndices.empty())
	{
		return -1;
	}

	return _selectedIndices[0];
}

void RadioList::setSelectedIndex(size_t index)
{
	selectIndex(index);
}

void RadioList::clearSelection()
{
	for (size_t oldSelect : getSelectedIndices())
	{
		deselectIndex(oldSelect);
	}
}

vector<size_t> RadioList::getSelectedIndices() const
{
	return CheckList::getSelectedIndices();
}

void RadioList::selectIndex(size_t index)
{
	for (size_t oldSelect : getSelectedIndices())
	{
		deselectIndex(oldSelect);
	}
	
	CheckList::selectIndex(index);
}

void RadioList::deselectIndex(size_t index)
{
	CheckList::deselectIndex(index);
}

void RadioList::setLayer(size_t layer)
{
	for (auto c : _controls)
	{
		c->setLayer(layer);
	}
	Panel::setLayer(layer);
}