#pragma once
#include "stdafx.h"

class CCar
{
private:
	int	m_speed;
	int m_gear;
	bool m_engineLaunched;
	Direction m_direction;
	void SetDirection();
	bool CheckBound(const int & value, const Border & rangeValues);
public:
	InfoAboutCar GetInfo();
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(const int & gear);
	bool SetSpeed(const int & speed);
	CCar();
	~CCar();

};

