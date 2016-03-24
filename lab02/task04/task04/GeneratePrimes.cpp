#include "GeneratePrimes.h"

set<int> GeneratePrimes(const int & upperBound)
{
	set<int> primeNumbers;
	if (upperBound < 2)
	{
		return primeNumbers;
	}
	vector<bool> numbers(upperBound + 1, true);

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

	for (int i = 2; i < int(numbers.size()); ++i)
	{
		if (numbers[i])
		{
			primeNumbers.insert(i);
		}
	}
	return primeNumbers;
}