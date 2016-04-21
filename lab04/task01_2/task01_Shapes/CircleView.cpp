#include "CircleView.h"


CCircleView::CCircleView(const CCircle & circleModel)
{
	ColorInfo m_fillColor = circleModel.GetColorFill();
	ColorInfo m_lineColor = circleModel.GetColorLine();
	
	m_circle.setFillColor(sf::Color(m_fillColor.R, m_fillColor.G, m_fillColor.B, m_fillColor.Transparent));
	m_circle.setRadius(circleModel.GetRadius());
	m_circle.setOrigin(circleModel.GetRadius(), circleModel.GetRadius());
	m_circle.setPosition(circleModel.GetPosCenter().GetPos().x, circleModel.GetPosCenter().GetPos().y);
	m_circle.setOutlineColor(sf::Color(m_lineColor.R, m_lineColor.G, m_lineColor.B, m_lineColor.Transparent));
	m_circle.setOutlineThickness(1.f);
}

void CCircleView::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_circle, states);
}
