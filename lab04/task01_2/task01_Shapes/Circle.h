#pragma once
#include "SolidShape.h"

class CCircle final : public ISolidShape
{
public:
	CCircle(const sf::Vector2f & posCenter, const float & radius, const ColorInfo & colorLine
		, const ColorInfo & colorFill);
	sf::Vector2f GetPosCenter() const;
	float GetRadius() const;

	virtual float GetShapeArea() const override;
	virtual float GetShapePerimetr() const override;
	virtual std::string ToString() const override;
private:
	sf::Vector2f m_pos = { 0, 0 };
	float m_radius = 0.f;
};

