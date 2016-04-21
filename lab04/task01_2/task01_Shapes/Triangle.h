#pragma once
#include "stdafx.h"
#include "SolidShape.h"
#include "Point.h"

class CTriangle : public ISolidShape
{
public:
	CTriangle(const CPoint & posTop, const CPoint & posLeft
		, const CPoint & posRight, const ColorInfo & colorLine
		, const ColorInfo & colorFill);
	std::map<std::string, CPoint > GetPoints() const;
	std::map<std::string, float> GetSidesLenght() const;

	virtual float GetArea() const override;
	virtual float GetPerimeter() const override;
	virtual std::string ToString() const override;
private:
	CPoint m_firstDot;
	CPoint m_secondDot;
	CPoint m_thirdDot;
};

