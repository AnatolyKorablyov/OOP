#include "stdafx.h"
#include "Rectangle.h"

CRectangle::CRectangle(const CPoint & pos, const float & width, const float & height
	, const ColorInfo & colorLine, const ColorInfo & colorFill)
	: m_dotTopLeft(pos)
	, m_height(height)
	, m_width(width)
{
	m_colorLine = colorLine;
	m_colorFill = colorFill;
}

CPoint CRectangle::GetTopLeftPoint() const
{
	return m_dotTopLeft;
}

float CRectangle::GetHeight() const
{
	return m_height;
}

float CRectangle::GetWidth() const
{
	return m_width;
}

float CRectangle::GetArea() const
{
	return (m_height * m_width);
}

float CRectangle::GetPerimeter() const
{
	return 	2 * (m_height + m_width);
}

std::string CRectangle::ToString() const
{
	std::stringstream ss;
	ss << "rectangle <" << m_dotTopLeft.GetPos().x << ", " 
		<< m_dotTopLeft.GetPos().y << ">, height = "
		<< m_height << ", width = " << m_width << ", S = " 
		<< GetArea() << ", P = " << GetPerimeter();
	return ss.str();
}