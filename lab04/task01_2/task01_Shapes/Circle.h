#pragma once
#include "SolidShape.h"
#include "Point.h"

class CCircle : public ISolidShape
{
public:
	CPoint m_center;
	unsigned m_radius;
	virtual unsigned GetPerimetr() const override;
	virtual unsigned GetArea() const override;
	virtual std::string ToString() const override;
	sf::CircleShape shape;
	CCircle(const sf::Vector2f & pos, unsigned radius
		, const sf::Color & lineColor, const sf::Color & fillColor);
};

