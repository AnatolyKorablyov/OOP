#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle()
{
	m_shapeName = "rectangle";
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