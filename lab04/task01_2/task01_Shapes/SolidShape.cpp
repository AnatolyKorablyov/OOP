#include "stdafx.h"
#include "SolidShape.h"

ColorInfo ISolidShape::GetColorLine() const
{
	return m_colorLine;
}

ColorInfo ISolidShape::GetColorFill() const
{
	return m_colorFill;
}