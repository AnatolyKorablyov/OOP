#pragma once
#include "Shape.h"
#include "Point.h"

class CLineSegment	: public IShape
{
public:
	CPoint m_posStart;
	CPoint m_posEnd;
	unsigned m_lengthLine;
	virtual unsigned GetPerimetr() const override;
	virtual unsigned GetArea() const override;
	virtual std::string ToString() const override;
	CLineSegment();
	~CLineSegment();
};

