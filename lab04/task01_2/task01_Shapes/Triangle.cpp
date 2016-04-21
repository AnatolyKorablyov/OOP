#include "stdafx.h"
#include "Triangle.h"


CTriangle::CTriangle()
{
	m_shapeName = "triangle";
	shape.setPointCount(3);
	shape.setPoint(0, { m_firstVertex.m_pos.x, m_firstVertex.m_pos.y });
	shape.setPoint(1, { m_secondVertex.m_pos.x, m_secondVertex.m_pos.y });
	shape.setPoint(3, { m_thirdVertex.m_pos.x, m_thirdVertex.m_pos.y });
}


CTriangle::~CTriangle()
{
}


unsigned CTriangle::GetPerimetr() const
{
	return 0;
}

unsigned CTriangle::GetArea() const
{
	return 0;
}

std::string CTriangle::ToString() const
{
	return m_shapeName;
}
