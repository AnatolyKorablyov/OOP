#pragma once
#include "stdafx.h"

struct IShape
{
	sf::Color m_colorLine;
	sf::ConvexShape shape;
	std::string m_shapeName;
	virtual unsigned GetArea() const = 0;
	virtual unsigned GetPerimetr() const = 0;
	virtual std::string ToString() const = 0;
};

