#include "stdafx.h"
#include "Triangle.h"


CTriangle::CTriangle(const sf::Vector2f & posTop, const sf::Vector2f & posLeft, const sf::Vector2f & posRight
	, const ColorInfo & colorLine, const ColorInfo & colorFill)
	: m_posFirstPoint(posTop)
	, m_posSecondPoint(posLeft)
	, m_posThirdPoint(posRight)
{
	m_colorLine = colorLine;
	m_colorFill = colorFill;
}

std::map<std::string, sf::Vector2f> CTriangle::GetPoints() const
{
	return std::map<std::string, sf::Vector2f> { {"A", m_posFirstPoint}
	, {"B", m_posSecondPoint }
	, {"C", m_posThirdPoint } };
}

std::map<std::string, float> CTriangle::GetSidesLenght() const
{
	std::map<std::string, sf::Vector2f> points = GetPoints();
	std::map<std::string, float> lenghtSide;
	lenghtSide.emplace("c", sqrtf(std::pow((points["B"].x - points["A"].x), 2) + std::pow((points["B"].y - points["A"].y), 2)));
	lenghtSide.emplace("a", sqrtf(std::pow((points["C"].x - points["B"].x), 2) + std::pow((points["C"].y - points["B"].y), 2)));
	lenghtSide.emplace("b", sqrtf(std::pow((points["A"].x - points["C"].x), 2) + std::pow((points["A"].y - points["C"].y), 2)));
	return lenghtSide;
}



float CTriangle::GetShapeArea() const
{
	float semiperimeter = GetShapePerimetr() / 2.f;
	std::map<std::string, float> lenghtSides = GetSidesLenght();
	
	return sqrtf(semiperimeter * (semiperimeter - lenghtSides["a"]) * (semiperimeter - lenghtSides["b"]) *
		(semiperimeter - lenghtSides["c"]));
}

float CTriangle::GetShapePerimetr() const
{
	std::map<std::string, float> lenghtSides = GetSidesLenght();
	return lenghtSides["a"] + lenghtSides["b"] + lenghtSides["c"];
}

std::string CTriangle::ToString() const
{
	std::stringstream ss;
	ss << "triangle FirstVertex <" << m_posFirstPoint.x << ", " << m_posFirstPoint.y << ">, SecondVertex <"
		<< m_posSecondPoint.x << ", " << m_posSecondPoint.y << ">, ThirdVertex <"
		<< m_posThirdPoint.x << ", " << m_posThirdPoint.y << ">, S = " << GetShapeArea()
		<< ", P = " << GetShapePerimetr();
	return ss.str();
}