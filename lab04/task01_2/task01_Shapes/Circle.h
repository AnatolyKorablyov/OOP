#pragma once
#include "SolidShape.h"
#include "Point.h"

class CCircle : public ISolidShape
{
public:
	CCircle(const CPoint & posCenter, const float & radius, const ColorInfo & colorLine
		, const ColorInfo & colorFill);
	CPoint GetPosCenter() const;
	float GetRadius() const;

	virtual float GetArea() const override;
	virtual float GetPerimeter() const override;
	virtual std::string ToString() const override;
private:
	CPoint m_dotCenter;
	float m_radius = 0.f;
};

