#pragma once
#include "LineSegment.h"
#include "ShapesView.h"


class CLineView : public CShapesView
{
public:
	CLineView(const CLineSegment & shapeModel);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::Vertex m_shape[2];
};