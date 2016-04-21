#pragma once
#include "SolidShape.h"
#include "Point.h"

class CRectangle : public ISolidShape
{
public:
	CRectangle(const CPoint & pos, const float & width
		, const float & height, const ColorInfo & colorLine
		, const ColorInfo & colorFill);

	CPoint GetTopLeftPoint() const;
	float GetHeight() const;
	float GetWidth() const;

	virtual float GetArea() const override;
	virtual float GetPerimeter() const override;
	virtual std::string ToString() const override;
private:
	CPoint m_dotTopLeft;
	float m_height = 0.f;
	float m_width = 0.f;
};

