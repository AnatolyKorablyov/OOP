// task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int _tmain()
{

	vector<double> numbers(istream_iterator<double>(cin), (istream_iterator<double>()));
	copy(numbers.begin(), numbers.end(), ostream_iterator<double>(cout, ", "));
	system("pause");
	return 0;
}

