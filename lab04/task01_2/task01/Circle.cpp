#include "stdafx.h"
#include "Circle.h"


CCircle::CCircle()
{
	m_shapeName = "circle";
}


CCircle::~CCircle()
{
}

unsigned CCircle::GetPerimetr() const
{
	return 0;
}

unsigned CCircle::GetArea() const
{
	return 0;
}

std::string CCircle::ToString() const
{
	return m_shapeName;
}
