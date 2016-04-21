#include "stdafx.h"
#include "Point.h"

CPoint::CPoint()
{
}

CPoint::CPoint(float x, float y)
	: m_pos(x, y)
{
}

sf::Vector2f CPoint::GetPos() const
{
	return m_pos;
}
float CPoint::GetArea() const
{
	return 0.f;
}

float CPoint::GetPerimeter() const
{
	return 0.f;
}

std::string CPoint::ToString() const
{
	std::stringstream ss;
	ss << "point <" << m_pos.x << ", " << m_pos.y << ">, S = " << GetArea()
		<< ", P = " << GetPerimeter();
	return ss.str();
}

ColorInfo CPoint::GetColorLine() const
{
	return ColorInfo();
}