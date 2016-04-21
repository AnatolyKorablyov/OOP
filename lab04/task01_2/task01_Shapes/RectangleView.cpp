#include "RectangleView.h"


CRectangleView::CRectangleView(const CRectangle & shapeModel)
{
	ColorInfo m_fillColor = shapeModel.GetColorFill();
	ColorInfo m_lineColor = shapeModel.GetColorLine();
	m_shape.setPosition(shapeModel.GetTopLeftPoint().GetPos().x, shapeModel.GetTopLeftPoint().GetPos().y);
	m_shape.setSize(sf::Vector2f(shapeModel.GetHeight(), shapeModel.GetWidth()));

	m_shape.setFillColor(sf::Color(m_fillColor.R, m_fillColor.G, m_fillColor.B, m_fillColor.Transparent));
	m_shape.setOutlineColor(sf::Color(m_lineColor.R, m_lineColor.G, m_lineColor.B, m_lineColor.Transparent));
	m_shape.setOutlineThickness(1.f);
}

void CRectangleView::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_shape, states);
}
