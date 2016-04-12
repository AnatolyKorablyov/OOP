#pragma once
#include "SolidShape.h"
#include "Point.h"

class CCircle : public ISolidShape
{
public:
	CPoint m_center;
	virtual unsigned GetPerimetr() const override;
	virtual unsigned GetArea() const override;
	virtual std::string ToString() const override;
	CCircle();
	~CCircle();
};

