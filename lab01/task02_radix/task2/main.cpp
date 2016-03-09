#include <iostream>
#include <string>
#include <cmath>

using namespace std;

static const int MIN_RADIX = 2;
static const int MAX_RADIX = 36;

int LetterToNumber(const char & letter)
{
	if (letter >= 'A' && letter <= 'Z')
	{
		return (letter - 'A' + 10);
	}
	else if (letter >= 'a' && letter <= 'z')
	{
		return (letter - 'a' + 10);
	}
	else if (letter >= '0' && letter <= '9')
	{
		return (letter - '0');
	}
	return -1;
}

_int64 InitialRadixToDec(string numConvers, const int & sourceNotation, bool & wasError)
{
	bool minus = false;

	if (numConvers.front() == '-')
	{
		minus = true;
		numConvers.erase(numConvers.begin());
	}
	int count = numConvers.length() - 1;
	_int64 result = 0;
	while (numConvers.length() > 0)
	{
		int num = LetterToNumber(numConvers.front());
		if (num > 0)
		{
			result += num * int(pow(sourceNotation, count));
		}
		else
		{
			wasError = true;
			return 0;
		}
		numConvers.erase(numConvers.begin());
		count--;
		if (result < 0)
		{
			cout << "I get great number" << endl;
			return 0;
		}
	}
	if (minus)
	{
		result *= -1;
	}
	return result;
}

string DecToFinRadix(_int64 decNumber, const int & finRadix)
{
	bool minus = false;
	string result = "";
	if (decNumber < 0)
	{
		minus = true;
		decNumber *= -1;
	}
	else if (decNumber == 0)
	{
		result = "0";
	}
	
	while (decNumber > 0)
	{
		int num = decNumber % finRadix;
		decNumber = decNumber / finRadix;
		if (num - 10 >= 0)
		{
			result = (char)('A' + (num - 10)) + result;
		}
		else
		{
			result = to_string(num) + result;
		}
	}
	if (minus && result != "0")
	{
		result = "-" + result;
	}
	return result;
}


bool CheckRadix(const int & notation)
{
	return (notation >= MIN_RADIX && notation <= MAX_RADIX);
}


int TransferRadix(const string & sourceStr, const string & destStr, const string & valueStr)
{
	int source = atoi(sourceStr.c_str());
	int destination = atoi(destStr.c_str());

	bool wasError = false;

	if (CheckRadix(source) && CheckRadix(destination))
	{
		_int64 decNumber = InitialRadixToDec(valueStr, source, wasError);
		if (!wasError)
		{
			string result = DecToFinRadix(decNumber, destination);
			cout << result << endl;
		}
		else
		{
			cout << "incorrect value. value = 0-9 and A-Z and should be in the source notation" << endl;
			cout << "Example: task2.exe \"36\" \"10\" \"27WZ\"" << endl;
			return 1;
		}
	}
	else
	{
		cout << "incorrect input bit. Bit should be from 2 to 36" << endl;
		return 1;
	}
	return 0;
}

void PrintHelp()
{
	cout << "radix.exe <source notation> <destination notation> <value>" << endl;
	cout << "EXAMPLE: radix.exe \"16\" \"10\" \"1F\"\n";
}

int main(int argc, char * argv[])
{
	if (argc > 4)
	{
		cout << "you have many arguments\n";
		PrintHelp();
	}
	else if (argc < 4)
	{
		cout << "you have too few arguments\n";
		PrintHelp();
	}
	else
	{
		return TransferRadix(argv[1], argv[2], argv[3]);
	}
	return 1;
}
