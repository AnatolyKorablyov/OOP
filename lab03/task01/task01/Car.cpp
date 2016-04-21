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

ReturnCodeEngineOn CCar::TurnOnEngine()
{
	ReturnCodeEngineOn wasError = ReturnCodeEngineOn::EngineOn;
	if (m_engineLaunched)
	{
		wasError = ReturnCodeEngineOn::EngineWasOn;
	}
	else if (m_gear != 0)
	{
		wasError = ReturnCodeEngineOn::EngineNotOnWithGear;
	}
	else
	{
		m_engineLaunched = true;
	}

	return wasError;
}

ReturnCodeEngineOff CCar::TurnOffEngine()
{
	ReturnCodeEngineOff wasError = ReturnCodeEngineOff::EngineOff;
	if (!m_engineLaunched)
	{
		wasError = ReturnCodeEngineOff::EngineWasOff;
	}
	else if (m_gear != 0)
	{
		wasError = ReturnCodeEngineOff::EngineNotOffWithGear;
	}
	else if (m_direction != Direction::Stand)
	{
		wasError = ReturnCodeEngineOff::EngineNotOffWithSpeed;
	}
	else
	{
		m_engineLaunched = false;
	}
	return wasError;
}

ReturnCodeSetGear CCar::SetGear(const int & gear)
{
	ReturnCodeSetGear wasError = ReturnCodeSetGear::GearOn;
	if (gear < 0 && m_direction == Direction::Forward)
	{
		wasError = ReturnCodeSetGear::GearNotOnReverse;
	}
	else if (gear < 0 && m_direction == Direction::Backward)
	{
		wasError = ReturnCodeSetGear::GearNotOnWithReverseSpeed;
	}
	else if (!CheckBound(gear, GEAR_RANGE))
	{
		wasError = ReturnCodeSetGear::GearNot;
	}
	else if (!CheckBound(m_speed, SPEED_RANGE.find(gear)->second))
	{
		wasError = ReturnCodeSetGear::GearNotOnWithSpeed;
	}
	else
	{
		m_gear = gear;
	}
	return wasError;
}

ReturnCodeSetSpeed CCar::SetSpeed(const int & speed)
{
	ReturnCodeSetSpeed wasError = ReturnCodeSetSpeed::SpeedOn;
	auto it = SPEED_RANGE.find(m_gear);
	if (!m_engineLaunched)
	{
		wasError = ReturnCodeSetSpeed::SpeedNotWithEngine;
	}
	else if (m_gear == 0 && speed > m_speed)
	{
		wasError = ReturnCodeSetSpeed::SpeedNotAddWithNeutralGear;
	}
	else if (!CheckBound(speed, it->second))
	{
		wasError = ReturnCodeSetSpeed::SpeedNotRange;
	}
	else
	{
		m_speed = speed;
		SetDirection();
	}
	return wasError;
}