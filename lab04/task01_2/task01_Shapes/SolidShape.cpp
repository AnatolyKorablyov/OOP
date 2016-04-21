#include "stdafx.h"
#include "SolidShape.h"

ColorInfo ISolidShape::GetColorLine() const
{
	return m_colorLine;
}

ColorInfo ISolidShape::GetColorFill()
{
	return m_colorFill;
}