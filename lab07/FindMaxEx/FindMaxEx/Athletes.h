#pragma once
#include "stdafx.h"

class CAthlete
{
public:
	CAthlete();
	CAthlete(const std::string & fName, const std::string & sName, double weight, double growth);
	void PrintInfo() const;
	void SetParametersAthlete(const std::string & fName, const std::string & sName, double w, double g);

	std::string m_firstName = "";
	std::string m_secondName = "";
	double m_weight = NAN;
	double m_growth = NAN;
};
