#include "stdafx.h"
#include "Rectangle.h"

CRectangle::CRectangle(const sf::Vector2f & pos, const float & width, const float & height
	, const ColorInfo & colorLine, const ColorInfo & colorFill)
	: m_posTopLeft(pos)
	, m_height(height)
	, m_width(width)
{
	m_colorLine = colorLine;
	m_colorFill = colorFill;
}

sf::Vector2f CRectangle::GetTopLeftPoint() const
{
	return m_posTopLeft;
}

float CRectangle::GetHeight() const
{
	return m_height;
}

float CRectangle::GetWidth() const
{
	return m_width;
}

float CRectangle::GetShapeArea() const
{
	return (m_height * m_width);
}

float CRectangle::GetShapePerimetr() const
{
	return 	2 * (m_height + m_width);
}

std::string CRectangle::ToString() const
{
	std::stringstream ss;
	ss << "rectangle <" << m_posTopLeft.x << ", " << m_posTopLeft.y << ">, height = "
		<< m_height << ", width = " << m_width << ", S = " << GetShapeArea() << ", P = "
		<< GetShapePerimetr();
	return ss.str();
}