#pragma once
#include "Shape.h"

struct ISolidShape  : public IShape
{
	sf::Color m_fillColor;
};