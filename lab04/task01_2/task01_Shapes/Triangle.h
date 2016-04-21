#pragma once
#include "stdafx.h"
#include "SolidShape.h"

class CTriangle : public ISolidShape
{
public:
	CTriangle(const sf::Vector2f & posTop, const sf::Vector2f & posLeft, const sf::Vector2f & posRight
		, const ColorInfo & colorLine, const ColorInfo & colorFill);
	std::map<std::string, sf::Vector2f> GetPoints() const;
	std::map<std::string, float> GetSidesLenght() const;

	virtual float GetShapeArea() const override;
	virtual float GetShapePerimetr() const override;
	virtual std::string ToString() const override;
private:


	sf::Vector2f m_posFirstPoint = { 0, 0 };
	sf::Vector2f m_posSecondPoint = { 0, 0 };
	sf::Vector2f m_posThirdPoint = { 0, 0 };
};

