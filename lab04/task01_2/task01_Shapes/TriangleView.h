#pragma once
#include "Triangle.h"
#include "ShapesView.h"


class CTriangleView : public CShapesView
{
public:
	CTriangleView(const CTriangle & shapeModel);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::ConvexShape m_shape;
};