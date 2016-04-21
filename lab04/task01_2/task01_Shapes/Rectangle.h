#pragma once
#include "SolidShape.h"

class CRectangle final : public ISolidShape
{
public:
	CRectangle(const sf::Vector2f & pos, const float & width, const float & height
		, const ColorInfo & colorLine, const ColorInfo & colorFill);

	sf::Vector2f GetTopLeftPoint() const;
	float GetHeight() const;
	float GetWidth() const;

	virtual float GetShapeArea() const override;
	virtual float GetShapePerimetr() const override;
	virtual std::string ToString() const override;
private:
	sf::Vector2f m_posTopLeft = { 0, 0 };
	float m_height = 0.f;
	float m_width = 0.f;
};

