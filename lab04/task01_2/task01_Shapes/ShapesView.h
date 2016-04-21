#pragma once
#include "stdafx.h"

class CShapesView : public sf::Drawable
{
public:public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};

