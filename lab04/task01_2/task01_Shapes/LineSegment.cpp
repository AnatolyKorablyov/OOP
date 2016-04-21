#include "stdafx.h"
#include "LineSegment.h"


CLineSegment::CLineSegment(const sf::Vector2f & posStart, const sf::Vector2f & posEnd, const ColorInfo & colorLine)
	: m_posStart(posStart)
	, m_posEnd(posEnd)
	, m_colorLine(colorLine)
{
}

sf::Vector2f CLineSegment::GetCoordStartDot()
{
	return m_posStart;
}

sf::Vector2f CLineSegment::GetCoordEndDot()
{
	return m_posEnd;
}

float CLineSegment::GetShapeArea() const
{
	return 0.f;
}

float CLineSegment::GetShapePerimetr() const
{												
	sf::Vector2f length = { (m_posEnd.x - m_posStart.x), (m_posEnd.y - m_posStart.y) };
	return sqrt(length.x * length.x + length.y * length.y);
}

std::string CLineSegment::ToString() const
{
	std::stringstream ss;
	ss << "line <" << m_posStart.x << ", " << m_posStart.y << " <" << m_posEnd.x << ", " << m_posEnd.y
		<< ">, S = " << GetShapeArea() << ", P = " << GetShapePerimetr();
	return ss.str();
}

ColorInfo CLineSegment::GetColorLine() const
{
	return ColorInfo();
}