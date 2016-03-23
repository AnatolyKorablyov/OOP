// task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "VectorProcessor.h"
using namespace std;

int main()
{

	vector<double> numbers(istream_iterator<double>(cin), (istream_iterator<double>()));
	ProcessVector(numbers);
	copy(numbers.begin(), numbers.end(), ostream_iterator<double>(cout, ", "));
	system("pause");
	return 0;
}

