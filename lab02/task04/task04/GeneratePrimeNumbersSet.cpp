#include "stdafx.h"
#include "GeneratePrimeNumbersSet.h"


std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
	std::set<int> primeSet;
	std::vector<bool> prime(upperBound + 1, true);
	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i*i <= upperBound; ++i)
	{
		if (prime[i])
		{
			for (int j = i*i; j <= upperBound; j += i)
			{
				prime[j] = false;
			}
		}
	}
	int count = 0;
	for (auto y : prime)
	{
		if (y)
		{
			primeSet.insert(count);
		}
		++count;
	}
	return primeSet;
}