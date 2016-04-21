#pragma once

#include "stdafx.h"
#include "Shape.h"

class CPoint final : public IShape
{
public:
	CPoint(float x, float y);
	sf::Vector2f GetCoord() const;
	float GetShapeArea() const override;
	float GetShapePerimetr() const override;
	std::string ToString() const override;
	ColorInfo GetColorLine() const override;
	sf::Vector2f m_pos = {0, 0};
};