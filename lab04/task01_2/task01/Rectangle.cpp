#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle()
{
	m_shapeName = "rectangle";
	shape.setPointCount(4);
	shape.setPoint(0, m_point.m_pos);
	shape.setPoint(1, sf::Vector2f(m_point.m_pos.x + 10, m_point.m_pos.y));
	shape.setPoint(2, sf::Vector2f(m_point.m_pos.x + 10, m_point.m_pos.y + 10));
	shape.setPoint(3, sf::Vector2f(m_point.m_pos.x, m_point.m_pos.y + 10));
}


CRectangle::~CRectangle()
{
}

unsigned CRectangle::GetPerimetr() const
{
	return 0;
}

unsigned CRectangle::GetArea() const
{
	return 0;
}

std::string CRectangle::ToString() const
{
	return m_shapeName;
}