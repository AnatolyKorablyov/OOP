#include "stdafx.h"
#include "Circle.h"
#include <math.h>


CCircle::CCircle()
{
	m_shapeName = "circle";
	m_colorLine = sf::Color(134, 134, 134, 255);
	m_center.m_pos = { 100, 100 };
	shape.setPointCount(4);
	shape.setPoint(0, sf::Vector2f(m_point.m_pos.x, m_point.m_pos.y));
	shape.setPoint(1, sf::Vector2f(m_point.m_pos.x + 10, m_point.m_pos.y));
	shape.setPoint(2, sf::Vector2f(m_point.m_pos.x + 10, m_point.m_pos.y + 10));
	shape.setPoint(3, sf::Vector2f(m_point.m_pos.x, m_point.m_pos.y + 10));

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
