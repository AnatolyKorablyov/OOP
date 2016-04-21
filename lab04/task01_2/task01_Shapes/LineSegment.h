#pragma once
#include "Shape.h"

class CLineSegment final : public IShape
{
public:
	CLineSegment(const sf::Vector2f & posStart, const sf::Vector2f & posEnd, const ColorInfo & colorLine);
	sf::Vector2f GetCoordStartDot();
	sf::Vector2f GetCoordEndDot();
	float GetShapeArea() const override;
	float GetShapePerimetr() const override;
	std::string ToString() const override;
	ColorInfo GetColorLine() const override;
private:
	sf::Vector2f m_posStart = { 0, 0 };
	sf::Vector2f m_posEnd = { 0, 0 };
	ColorInfo m_colorLine;
};

