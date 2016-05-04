#include "TriangleView.h"


CTriangleView::CTriangleView(const CTriangle & shapeModel)
{
	m_shape.setPointCount(3);
	auto points = shapeModel.GetPoints();
	m_shape.setPoint(0, points["A"].GetPos());
	m_shape.setPoint(1, points["B"].GetPos());
	m_shape.setPoint(2, points["C"].GetPos());

	ColorInfo m_fillColor = shapeModel.GetColorFill();
	ColorInfo m_lineColor = shapeModel.GetColorLine();
	
	m_shape.setFillColor(sf::Color(m_fillColor.r, m_fillColor.g, m_fillColor.b, m_fillColor.Transparent));
	m_shape.setOutlineColor(sf::Color(m_lineColor.r, m_lineColor.g, m_lineColor.b, m_lineColor.Transparent));
	m_shape.setOutlineThickness(1.f);
}

void CTriangleView::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_shape, states);
}
