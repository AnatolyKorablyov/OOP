#include "stdafx.h"
#include "LineSegment.h"

CLineSegment::CLineSegment(const CPoint & posStart, const CPoint & posEnd
	, const ColorInfo & colorLine)
	: m_dotStart(posStart)
	, m_dotEnd(posEnd)
	, m_colorLine(colorLine)
{
}

CPoint CLineSegment::GetCoordStartDot() const
{
	return m_dotStart;
}

CPoint CLineSegment::GetCoordEndDot() const
{
	return m_dotEnd;
}

float CLineSegment::GetArea() const
{
	return 0.f;
}

float CLineSegment::GetPerimeter() const
{												
	sf::Vector2f length = { (m_dotEnd.GetPos().x - m_dotStart.GetPos().x), (m_dotEnd.GetPos().y - m_dotStart.GetPos().y) };
	return sqrt(length.x * length.x + length.y * length.y);
}

std::string CLineSegment::ToString() const
{
	std::stringstream ss;
	ss << "line <" << m_dotStart.GetPos().x << ", " << m_dotStart.GetPos().y << ">, <" << m_dotEnd.GetPos().x << ", " << m_dotEnd.GetPos().y
		<< ">, S = " << GetArea() << ", P = " << GetPerimeter();
	return ss.str();
}

ColorInfo CLineSegment::GetColorLine() const
{
	return ColorInfo();
}