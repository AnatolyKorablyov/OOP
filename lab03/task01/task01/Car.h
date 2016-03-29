#pragma once
#include "stdafx.h"
#include "Definition.h"

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
	int TurnOnEngine();
	int TurnOffEngine();
	int SetGear(const int & gear);
	int SetSpeed(const int & speed);
	CCar();
	~CCar();

};

