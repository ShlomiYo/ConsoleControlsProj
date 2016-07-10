#pragma once

#include "BorderDrawer.h"
#include "NullBorderDrawer.h"
#include "SingleBorderDrawer.h"
#include "DoubleBorderDrawer.h"

enum class BorderType
{
	Single, Double, None
};

class SimpleBorderFactory
{
private:
	SimpleBorderFactory() = default;

public:
	const BorderDrawer& getNull()
	{
		return _null;
	}

	const BorderDrawer& getSingle()
	{
		return _single;
	}

	const BorderDrawer& getDouble()
	{
		return _double;
	}

	const BorderDrawer& getBorderDrawer(BorderType border)
	{
		switch (border)
		{
		case BorderType::Single:
			return _single;
		case BorderType::Double:
			return _double;
		case BorderType::None:
			return _null;
		default:
			throw "Invalid border type";
		}
	}

	static SimpleBorderFactory& instance()
	{
		static SimpleBorderFactory instance;
		return instance;
	}

	SimpleBorderFactory(SimpleBorderFactory const&) = delete;
	void operator=(SimpleBorderFactory const&) = delete;

	const NullBorderDrawer _null;
	const SingleBorderDrawer _single;
	const DoubleBorderDrawer _double;
};
