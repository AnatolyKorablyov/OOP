#pragma once
#include "SolidShape.h"
#include "Point.h"

class CRectangle : public ISolidShape
{
public:			 
	unsigned m_width;
	unsigned m_height;
	sf::Vector2f m_point;
	virtual unsigned GetPerimetr() const override;
	virtual unsigned GetArea() const override;
	virtual std::string ToString() const override;
	CRectangle();
	~CRectangle();
};

