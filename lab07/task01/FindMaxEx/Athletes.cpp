#include "stdafx.h"
#include "Athletes.h"

CAthlete::CAthlete()
{
}

CAthlete::CAthlete(const std::string & fName, const std::string & sName, double weight, double growth)
	: m_firstName(fName)
	, m_secondName(sName)
	, m_weight(weight)
	, m_growth(growth)
{}

void CAthlete::PrintInfo() const
{
	std::cout << "Name " << m_firstName << " " << m_secondName << std::endl;
	std::cout << "Weight " << m_weight << std::endl;
	std::cout << "Growth " << m_growth << std::endl;
}

void CAthlete::SetParametersAthlete(const std::string &	fName, const std::string & sName, double weight, double growth)
{
	m_firstName = fName;
	m_secondName = sName;
	m_weight = weight;
	m_growth = growth;
}
