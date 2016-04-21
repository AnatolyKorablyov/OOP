#pragma once
#include "Circle.h"
#include "ShapesView.h"


class CCircleView : public CShapesView
{
public:
	CCircleView(const CCircle & circleModel);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::CircleShape m_circle;
};

