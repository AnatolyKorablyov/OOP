#include "stdafx.h"
#include "Circle.h"

#define _USE_MATH_DEFINES // for C++
#include <math.h>

CCircle::CCircle(const CPoint & posCenter, const float & radius, const ColorInfo & colorLine
	, const ColorInfo & colorFill)
	: m_dotCenter(posCenter)
	, m_radius(radius)
{
	m_colorLine = colorLine;
	m_colorFill = colorFill;
}

CPoint CCircle::GetPosCenter() const
{
	return m_dotCenter;
}

float CCircle::GetRadius() const
{
	return m_radius;
}

float CCircle::GetArea() const
{
	return float(M_PI * m_radius * m_radius);
}
float CCircle::GetPerimeter() const
{
	return float(2 * M_PI * m_radius);
}
std::string CCircle::ToString() const
{
	std::stringstream ss;
	ss << "circle <" << m_dotCenter.GetPos().x << ", " << m_dotCenter.GetPos().y 
		<< ">, radius = " << m_radius << ", S = " << GetArea()
		<< ", P = " << GetPerimeter();
	return ss.str();
}