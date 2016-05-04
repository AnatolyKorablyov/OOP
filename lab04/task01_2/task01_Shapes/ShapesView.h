#pragma once
#include "stdafx.h"

class IShapeView : public sf::Drawable
{
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};

