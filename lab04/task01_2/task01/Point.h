#pragma once
#include "Shape.h"

class CPoint : public IShape
{
public:
	sf::Vector2f m_pos;
	virtual unsigned GetPerimetr() const override;
	virtual unsigned GetArea() const override;
	virtual std::string ToString() const override;
	CPoint();
	~CPoint();
};

