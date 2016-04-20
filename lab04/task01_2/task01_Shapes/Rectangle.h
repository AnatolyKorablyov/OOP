#pragma once
#include "SolidShape.h"
#include "Point.h"

class CRectangle : public ISolidShape
{
public:			 
	unsigned m_width = 0;
	unsigned m_height = 0;
	CPoint m_point;
	virtual unsigned GetPerimetr() const override;
	virtual unsigned GetArea() const override;
	virtual std::string ToString() const override;
	CRectangle();
};

