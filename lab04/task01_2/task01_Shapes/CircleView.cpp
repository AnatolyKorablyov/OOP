#include "CircleView.h"


CCircleView::CCircleView(const CCircle & circleModel)
{
	ColorInfo m_fillColor = circleModel.GetColorFill();
	ColorInfo m_lineColor = circleModel.GetColorLine();
	
	m_circle.setFillColor(sf::Color(m_fillColor.r, m_fillColor.g, m_fillColor.b, m_fillColor.Transparent));
	m_circle.setRadius(circleModel.GetRadius());
	m_circle.setOrigin(circleModel.GetRadius(), circleModel.GetRadius());
	m_circle.setPosition(circleModel.GetPosCenter().GetPos().x, circleModel.GetPosCenter().GetPos().y);
	m_circle.setOutlineColor(sf::Color(m_lineColor.r, m_lineColor.g, m_lineColor.b, m_lineColor.Transparent));
	m_circle.setOutlineThickness(1.f);
}

void CCircleView::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_circle, states);
}
