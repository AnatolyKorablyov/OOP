#pragma once
#include "Rectangle.h"
#include "ShapesView.h"


class CRectangleView : public CShapesView
{
public:
	CRectangleView(const CRectangle & shapeModel);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::RectangleShape m_shape;
};