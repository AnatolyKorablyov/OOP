#include "stdafx.h"
#include "Circle.h"
#include <math.h>


CCircle::CCircle(const sf::Vector2f & pos, unsigned radius
	, const sf::Color & lineColor, const sf::Color & fillColor)
	: m_radius(radius)
	, m_colorLine(lineColor)
	, 
{
	m_shapeName = "circle";
	m_colorLine = lineColor;
	
	m_center.m_pos = { 100, 100 };
	shape.setRadius(radius);
	shape.setPointCount(40);
	for (unsigned i = 0; i < 10; ++i)
	{
		shape.setPoint(20 + i, sf::Vector2f(i - 10, 0 - i));
	}
	for (unsigned i = 0; i < 10; ++i)
	{
		shape.setPoint(30 + i, sf::Vector2f(i, i - 10));
	}
	for (unsigned i = 0; i < 10; ++i)
	{
		shape.setPoint( i, sf::Vector2f(100 - i, i));
	}
	for (unsigned i = 0; i < 10; ++i)
	{
		shape.setPoint(10 + i, sf::Vector2f(0-i, 10 - i));
	}
	

	shape.setPosition(100, 100);
}

unsigned CCircle::GetPerimetr() const
{
	return (2 * m_radius);
}

unsigned CCircle::GetArea() const
{
	return (m_radius * m_radius);
}

std::string CCircle::ToString() const
{
	return m_shapeName;
}
