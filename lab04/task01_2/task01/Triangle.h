#pragma once
#include "SolidShape.h"

class CTriangle : public ISolidShape
{
public:
	virtual unsigned GetPerimetr() const override;
	virtual unsigned GetArea() const override;
	virtual std::string ToString() const override;
	CTriangle();
	~CTriangle();
};

