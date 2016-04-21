#include "stdafx.h"
#include "Circle.h"

#define _USE_MATH_DEFINES // for C++
#include <math.h>

CCircle::CCircle(const sf::Vector2f & posCenter, const float & radius, const ColorInfo & colorLine
	, const ColorInfo & colorFill)
	: m_pos(posCenter)
	, m_radius(radius)
{
	m_colorLine = colorLine;
	m_colorFill = colorFill;
}

sf::Vector2f CCircle::GetPosCenter() const
{
	return m_pos;
}

float CCircle::GetRadius() const
{
	return m_radius;
}

float CCircle::GetShapeArea() const
{
	return float(M_PI * m_radius * m_radius);
}
float CCircle::GetShapePerimetr() const
{
	return float(2 * M_PI * m_radius);
}
std::string CCircle::ToString() const
{
	std::stringstream ss;
	ss << "circle <" << m_pos.x << ", " << m_pos.y << ">, radius = " << m_radius
		<< ", S = " << GetShapeArea() << ", P = " << GetShapePerimetr();
	return ss.str();
}