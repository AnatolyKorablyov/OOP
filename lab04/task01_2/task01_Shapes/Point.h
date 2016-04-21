#pragma once

#include "stdafx.h"
#include "Shape.h"


// perimeter

// GetPos, private m_pos

class CPoint : public IShape
{
public:
	CPoint();
	CPoint(float x, float y);
	sf::Vector2f GetPos() const;
	float GetArea() const override;
	float GetPerimeter() const override;
	std::string ToString() const override;
	ColorInfo GetColorLine() const override;
private:
	sf::Vector2f m_pos = {0, 0};
};