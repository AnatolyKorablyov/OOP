#include "stdafx.h"
#include "Car.h"
#include <iostream>

CCar::CCar()
	: m_engineLaunched(false)
	, m_direction(Direction::Stand)
	, m_gear(0)
	, m_speed(0)
{
}


InfoAboutCar CCar::GetInfo() const
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

WasErrorEngineOn CCar::TurnOnEngine()
{
	WasErrorEngineOn wasError = WasErrorEngineOn::EngineOn;
	if (m_engineLaunched)
	{
		wasError = WasErrorEngineOn::EngineWasOn;
	}
	else if (m_gear != 0)
	{
		wasError = WasErrorEngineOn::EngineNotOnWithGear;
	}
	else
	{
		m_engineLaunched = true;
	}

	return wasError;
}

WasErrorEngineOff CCar::TurnOffEngine()
{
	WasErrorEngineOff wasError = WasErrorEngineOff::EngineOff;
	if (!m_engineLaunched)
	{
		wasError = WasErrorEngineOff::EngineWasOff;
	}
	else if (m_gear != 0)
	{
		wasError = WasErrorEngineOff::EngineNotOffWithGear;
	}
	else if (m_direction != Direction::Stand)
	{
		wasError = WasErrorEngineOff::EngineNotOffWithSpeed;
	}
	else
	{
		m_engineLaunched = false;
	}
	return wasError;
}

WasErrorSetGear CCar::SetGear(const int & gear)
{
	WasErrorSetGear wasError = WasErrorSetGear::GearOn;
	if (gear < 0 && m_direction == Direction::Forward)
	{
		wasError = WasErrorSetGear::GearNotOnReverse;
	}
	else if (gear < 0 && m_direction == Direction::Backward)
	{
		wasError = WasErrorSetGear::GearNotOnWithReverseSpeed;
	}
	else if (!CheckBound(gear, GEAR_RANGE))
	{
		wasError = WasErrorSetGear::GearNot;
	}
	else if (!CheckBound(m_speed, SPEED_RANGE.find(gear)->second))
	{
		wasError = WasErrorSetGear::GearNotOnWithSpeed;
	}
	else
	{
		m_gear = gear;
	}
	return wasError;
}

WasErrorSetSpeed CCar::SetSpeed(const int & speed)
{
	WasErrorSetSpeed wasError = WasErrorSetSpeed::SpeedOn;
	auto it = SPEED_RANGE.find(m_gear);
	if (!m_engineLaunched)
	{
		wasError = WasErrorSetSpeed::SpeedNotWithEngine;
	}
	else if (m_gear == 0 && speed > m_speed)
	{
		wasError = WasErrorSetSpeed::SpeedNotAddWithNeutralGear;
	}
	else if (!CheckBound(speed, it->second))
	{
		wasError = WasErrorSetSpeed::SpeedNotRange;
	}
	else
	{
		m_speed = speed;
		SetDirection();
	}
	return wasError;
}