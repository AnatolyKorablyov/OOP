// Lab2Task4Var4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GeneratePrimeNumbersSet.h"


int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong amount of arguments was proposed\nEnter a correct arguments amount please, for example:\n'upperBound < 0 or upperBound > 10000000'";
		return 1;
	}
	int upperBound = atoi(argv[1]);
	if (upperBound < 0 || upperBound > 100000000)
	{
		std::cout << "Wrong number\n";
		return 1;
	}
	
	std::set<int> primeSet = GeneratePrimeNumbersSet(upperBound);
	for (int x : primeSet)
	{
		std::cout << x << " ";
	}
	return 0;
}

