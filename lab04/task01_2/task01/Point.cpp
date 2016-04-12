#include "stdafx.h"
#include "Point.h"


CPoint::CPoint()
{
	m_shapeName = "point";
}


CPoint::~CPoint()
{
}

unsigned CPoint::GetPerimetr() const
{
	return 0;
}

unsigned CPoint::GetArea() const
{
	return 0;
}

std::string CPoint::ToString() const
{
	return m_shapeName;
}