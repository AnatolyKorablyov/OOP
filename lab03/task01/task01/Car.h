#pragma once
#include "stdafx.h"
#include "Definition.h"

class CCar
{
public:
	CCar();

	InfoAboutCar GetInfo() const;
	ReturnCodeEngineOn TurnOnEngine();
	ReturnCodeEngineOff TurnOffEngine();
	ReturnCodeSetGear SetGear(const int & gear);
	ReturnCodeSetSpeed SetSpeed(const int & speed);


private:
	int	m_speed;
	int m_gear;
	bool m_engineLaunched;
	Direction m_direction;
	void SetDirection();
	bool CheckBound(const int & value, const Border & rangeValues);
};

