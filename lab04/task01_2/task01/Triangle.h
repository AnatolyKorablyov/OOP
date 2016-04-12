#pragma once
#include "SolidShape.h"
#include "Point.h"

class CTriangle : public ISolidShape
{
public:
	CPoint m_firstVertex;
	CPoint m_secondVertex;
	CPoint m_thirdVertex;
	virtual unsigned GetPerimetr() const override;
	virtual unsigned GetArea() const override;
	virtual std::string ToString() const override;
	CTriangle();
	~CTriangle();
};

