#include "stdafx.h"
#include "LineSegment.h"


CLineSegment::CLineSegment()
{
}


CLineSegment::~CLineSegment()
{
}

unsigned CLineSegment::GetPerimetr() const
{
	return m_lengthLine;
}

unsigned CLineSegment::GetArea() const
{
	return 0;
}

std::string CLineSegment::ToString() const
{
	return m_shapeName;
}