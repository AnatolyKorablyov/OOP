#include "stdafx.h"
#include "Triangle.h"


CTriangle::CTriangle(const CPoint & posTop, const CPoint & posLeft
	, const CPoint & posRight, const ColorInfo & colorLine
	, const ColorInfo & colorFill)
	: m_firstDot(posTop)
	, m_secondDot(posLeft)
	, m_thirdDot(posRight)
{
	m_colorLine = colorLine;
	m_colorFill = colorFill;
}

std::map<std::string, CPoint > CTriangle::GetPoints() const
{
	return std::map<std::string, CPoint > { {"A", m_firstDot}
	, {"B", m_secondDot }
	, {"C", m_thirdDot } };
}

std::map<std::string, float> CTriangle::GetSidesLenght() const
{
	std::map<std::string, CPoint> points = GetPoints();
	std::map<std::string, float> lenghtSide;
	lenghtSide.emplace("c", sqrtf(std::pow((points["B"].GetPos().x - points["A"].GetPos().x), 2) + std::pow((points["B"].GetPos().y - points["A"].GetPos().y), 2)));
	lenghtSide.emplace("a", sqrtf(std::pow((points["C"].GetPos().x - points["B"].GetPos().x), 2) + std::pow((points["C"].GetPos().y - points["B"].GetPos().y), 2)));
	lenghtSide.emplace("b", sqrtf(std::pow((points["A"].GetPos().x - points["C"].GetPos().x), 2) + std::pow((points["A"].GetPos().y - points["C"].GetPos().y), 2)));
	return lenghtSide;
}



float CTriangle::GetArea() const
{
	float semiperimeter = GetPerimeter() / 2.f;
	std::map<std::string, float> lenghtSides = GetSidesLenght();
	
	return sqrtf(semiperimeter * (semiperimeter - lenghtSides["a"]) * (semiperimeter - lenghtSides["b"]) *
		(semiperimeter - lenghtSides["c"]));
}

float CTriangle::GetPerimeter() const
{
	std::map<std::string, float> lenghtSides = GetSidesLenght();
	return lenghtSides["a"] + lenghtSides["b"] + lenghtSides["c"];
}

std::string CTriangle::ToString() const
{
	std::stringstream ss;
	ss << "triangle FirstVertex <" << m_firstDot.GetPos().x << ", " 
		<< m_firstDot.GetPos().y << ">, SecondVertex <"
		<< m_secondDot.GetPos().x << ", " << m_secondDot.GetPos().y 
		<< ">, ThirdVertex <" << m_thirdDot.GetPos().x << ", " << m_thirdDot.GetPos().y
		<< ">, S = " << GetArea() << ", P = " << GetPerimeter();
	return ss.str();
}