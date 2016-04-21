#include "stdafx.h"
#include "Point.h"

CPoint::CPoint(float x, float y)
	: m_pos(x, y)
{

}

sf::Vector2f CPoint::GetCoord() const
{
	return m_pos;
}
float CPoint::GetShapeArea() const
{
	return 0.f;
}

float CPoint::GetShapePerimetr() const
{
	return 0.f;
}

std::string CPoint::ToString() const
{
	std::stringstream ss;
	ss << "point <" << m_pos.x << ", " << m_pos.y << ">, S = " << GetShapeArea()
		<< ", P = " << GetShapePerimetr();
	return ss.str();
}

ColorInfo CPoint::GetColorLine() const
{
	return ColorInfo();
}