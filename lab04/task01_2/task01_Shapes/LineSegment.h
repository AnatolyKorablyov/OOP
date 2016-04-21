#pragma once
#include "Shape.h"
#include "Point.h"

class CLineSegment : public IShape
{
public:
	CLineSegment(const CPoint & posStart, const CPoint & posEnd, const ColorInfo & colorLine);
	CPoint  GetCoordStartDot() const;
	CPoint GetCoordEndDot() const;
	float GetArea() const override;
	float GetPerimeter() const override;
	std::string ToString() const override;
	ColorInfo GetColorLine() const override;
private:
	CPoint m_dotStart;
	CPoint m_dotEnd;
	ColorInfo m_colorLine;
};
