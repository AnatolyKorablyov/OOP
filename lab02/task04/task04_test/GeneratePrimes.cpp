#include "GeneratePrimes.h"
#include "stdafx.h"

set<int> GeneratePrimes(const int & upperBound)
{
	vector<bool> numbers(upperBound, true);

	for (int i = 2; i*i <= upperBound; ++i)
	{
		if (numbers[i])
		{
			for (int j = i*i; j <= upperBound; j += i)
			{
				numbers[j] = false;
			}
		}
	}
	set<int> primeNumbers;

	for (int i = 2; i < int(numbers.size()); ++i)
	{
		if (numbers[i])
		{
			primeNumbers.insert(i);
		}
	}
	return primeNumbers;
}