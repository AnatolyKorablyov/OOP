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

int CCar::TurnOnEngine()
{
	int wasError = 0;
	if (m_engineLaunched)
	{
		wasError = 1;
	}
	else if (m_gear != 0)
	{
		wasError = 2;
	}
	else
	{
		m_engineLaunched = true;
	}

	return wasError;
}

int CCar::TurnOffEngine()
{
	int wasError = 0;
	if (!m_engineLaunched)
	{
		wasError = 1;
	}
	else if (m_gear != 0)
	{
		wasError = 2;
	}
	else if (m_direction != Direction::Stand)
	{
		wasError = 3;
	}
	else
	{
		m_engineLaunched = false;
	}
	return wasError;
}

int CCar::SetGear(const int & gear)
{
	int wasError = 0;
	if (gear < 0 && m_direction == Direction::Forward)
	{
		wasError = 1;
	}
	else if (gear < 0 && m_direction == Direction::Backward)
	{
		wasError = 2;
	}
	else if (!CheckBound(gear, GEAR_RANGE))
	{
		wasError = 3;
	}
	else if (!CheckBound(m_speed, SPEED_RANGE.find(gear)->second))
	{
		wasError = 4;
	}
	else
	{
		m_gear = gear;
	}
	return wasError;
}

int CCar::SetSpeed(const int & speed)
{
	int wasError = 0;
	auto it = SPEED_RANGE.find(m_gear);
	if (!m_engineLaunched)
	{
		wasError = 1;
	}
	else if (m_gear == 0 && speed > m_speed)
	{
		wasError = 2;
	}
	else if (!CheckBound(speed, it->second))
	{
		wasError = 3;
	}
	else
	{
		m_speed = speed;
		SetDirection();
	}
	return wasError;
}