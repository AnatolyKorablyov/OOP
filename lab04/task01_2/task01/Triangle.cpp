#include "stdafx.h"
#include "Triangle.h"


CTriangle::CTriangle()
{
	m_shapeName = "triangle";
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
