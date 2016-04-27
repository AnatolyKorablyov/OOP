#include "LineView.h"

CLineView::CLineView(const CLineSegment & shapeModel)
{
	m_shape[0].position = sf::Vector2f(shapeModel.GetCoordStartDot().GetPos().x, shapeModel.GetCoordStartDot().GetPos().y);
	m_shape[1].position = sf::Vector2f(shapeModel.GetCoordEndDot().GetPos().x, shapeModel.GetCoordEndDot().GetPos().y);
	
	ColorInfo m_lineColor = shapeModel.GetColorLine();
	m_shape[0].color = sf::Color(m_lineColor.r, m_lineColor.g, m_lineColor.b, m_lineColor.Transparent);
	m_shape[1].color = sf::Color(m_lineColor.r, m_lineColor.g, m_lineColor.b, m_lineColor.Transparent);
	
}

void CLineView::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_shape, 2, sf::Lines, states);
}
