#include "TriangleView.h"


CTriangleView::CTriangleView(const CTriangle & shapeModel)
{
	m_shape.setPointCount(3);
	auto points = shapeModel.GetPoints();
	m_shape.setPoint(0, sf::Vector2f(points["A"].GetPos().x, points["A"].GetPos().y));
	m_shape.setPoint(1, sf::Vector2f(points["B"].GetPos().x, points["B"].GetPos().y));
	m_shape.setPoint(2, sf::Vector2f(points["C"].GetPos().x, points["C"].GetPos().y));

	ColorInfo m_fillColor = shapeModel.GetColorFill();
	ColorInfo m_lineColor = shapeModel.GetColorLine();
	
	m_shape.setFillColor(sf::Color(m_fillColor.R, m_fillColor.G, m_fillColor.B, m_fillColor.Transparent));
	m_shape.setOutlineColor(sf::Color(m_lineColor.R, m_lineColor.G, m_lineColor.B, m_lineColor.Transparent));
	m_shape.setOutlineThickness(1.f);
}

void CTriangleView::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_shape, states);
}
