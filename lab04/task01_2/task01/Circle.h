#pragma once
#include "SolidShape.h"

class CCircle : public ISolidShape
{
public:
	virtual unsigned GetPerimetr() const override;
	virtual unsigned GetArea() const override;
	virtual std::string ToString() const override;
	CCircle();
	~CCircle();
};

