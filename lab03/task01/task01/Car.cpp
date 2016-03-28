#include "stdafx.h"
#include "Car.h"
#include <iostream>

CCar::CCar()
{
	m_engineLaunched = false;
	m_direction = Direction::Stand;
	m_gear = 0;
	m_speed = 0;
}


CCar::~CCar()
{
}

InfoAboutCar CCar::GetInfo()
{
	InfoAboutCar indicators;
	indicators.conditionEngine = m_engineLaunched;
	indicators.dir = m_direction;
	indicators.gear = m_gear;
	indicators.speed = m_speed;
	return indicators;
}

void CCar::SetDirection()
{
	if (m_gear >= 0 && m_speed > 0)
	{
		m_direction = Direction::Forward;
	}
	else if (m_gear < 0 && m_speed > 0)
	{
		m_direction = Direction::Backward;
	}
	else if (m_speed == 0)
	{
		m_direction = Direction::Stand;
	}
}

bool CCar::CheckBound(const int & value, const Border & rangeValues)
{
	return (value >= rangeValues.bottomBound && value <= rangeValues.upperBound);
}

bool CCar::TurnOnEngine()
{
	if (!m_engineLaunched)
	{ 
		m_engineLaunched = true;
		return true;
	}
	return false;
}

bool CCar::TurnOffEngine()
{
	if (m_engineLaunched && m_gear == 0 && m_direction == Direction::Stand)
	{
		m_engineLaunched = false;
		return true;
	}
	return false;
}

bool CCar::SetGear(const int & gear)
{
	if (((gear < 0 && m_gear >= 0) || (gear > 0 && m_gear < 0)) && m_speed > 0)
	{
		return false;
	}
	if (CheckBound(m_speed, SPEED_RANGE.find(gear)->second) && CheckBound(gear, GEAR_RANGE))
	{		   
		m_gear = gear;
		return true;
	}
	return false;
}

bool CCar::SetSpeed(const int & speed)
{
	if (m_gear == 0 && speed > m_speed)
	{
		return false;
	}
	auto it = SPEED_RANGE.find(m_gear);
	if (CheckBound(speed, it->second))
	{
		m_speed = speed;
		SetDirection();
		return true;
	}
	return false;
}