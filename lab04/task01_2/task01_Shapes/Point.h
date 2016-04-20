#pragma once
#include "Shape.h"
#include "Definition.h"

class CPoint : public IShape
{
public:
	DotPos m_pos;
	virtual unsigned GetPerimetr() const override;
	virtual unsigned GetArea() const override;
	virtual std::string ToString() const override;
	CPoint();
};

