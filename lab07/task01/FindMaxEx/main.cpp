// FindMaxEx.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FindMax.h"
#include "Athletes.h"

void PrintExampleInput()
{
	std::cout << "input parameters of athlete (firstName SecondName weight growth)" << std::endl;
	std::cout << "Vasya Pupkin 70 170" << std::endl;
	std::cout << "For exit input \"0\"" << std::endl;
}

std::vector<CAthlete> InputAthletesData()
{
	std::string firstName;
	std::string secondName;
	double weight;
	double growth;

	PrintExampleInput();
	std::vector<CAthlete> athletesVector;
	std::string parameters;
	std::getline(std::cin, parameters);

	while (parameters != "0")
	{
		std::stringstream strm(parameters);
		strm >> firstName;
		strm >> secondName;
		strm >> weight;
		strm >> growth;
		CAthlete athlete(firstName, secondName, weight, growth);
		athletesVector.push_back(athlete);
		std::getline(std::cin, parameters);
	}
	return athletesVector;
}

CAthlete FindMaxWeightAthlete(const std::vector<CAthlete> & athletesVector)
{
	CAthlete maxWeightAthlete;
	FindMax(athletesVector, maxWeightAthlete, [](const CAthlete & left, const CAthlete & right){
			return (left.m_weight < right.m_weight);
		});
	return maxWeightAthlete;
}

CAthlete FindMaxGrowthAthlete(const std::vector<CAthlete> & athletesVector)
{
	CAthlete maxGrowthAthlete;
	FindMax(athletesVector, maxGrowthAthlete, [](const CAthlete & left, const CAthlete & right) {
		return (left.m_growth < right.m_growth);
	});
	return maxGrowthAthlete;
}

int main()
{
	std::vector<CAthlete> athletesVector = InputAthletesData();
	std::cout << "max weight: " << std::endl;
	FindMaxWeightAthlete(athletesVector).PrintInfo();
	std::cout << std::endl << "max growth: " << std::endl;
	FindMaxGrowthAthlete(athletesVector).PrintInfo();
	return 0;
}