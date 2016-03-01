#include <iostream>
#include <string>
#include <cmath>

int SourceNotationToDec(std::string numConvers, const int & sourceNotation, bool & wasError)
{
	bool minus = false;

	if (numConvers.front() == '-')
	{
		minus = true;
		numConvers.erase(numConvers.begin());
	}
	int count = numConvers.length() - 1;
	int result = 0;
	while (numConvers.length() > 0)
	{
		if (numConvers.front() >= 'A' && numConvers.front() <= 'Z')
		{
			result += (numConvers.front() - 'A' + 10) * int(pow(sourceNotation, count));
		}
		else if (numConvers.front() >= '0' && numConvers.front() <= '9')
		{
			result += (numConvers.front() - '0') * int(pow(sourceNotation, count));
		}
		else
		{
			if (numConvers.front() >= 'a' && numConvers.front() <= 'z')
			{
				result += (numConvers.front() - 'a' + 10) * int(pow(sourceNotation, count));
			}
			else
			{
				wasError = true;
			}
		}
		if (wasError)
		{
			return 0;
		}
		numConvers.erase(numConvers.begin());
		count--;
	}
	if (minus)
	{
		result *= -1;
	}
	return result;
}

std::string DecToDestinationNotation(int decNumber, const int & destinationNot)
{
	bool minus = false;
	std::string result = "";
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
		int num = 0;
		num = decNumber % destinationNot;
		decNumber = decNumber / destinationNot;
		if (num - 10 >= 0)
		{
			result = (char)('A' + (num - 10)) + result;
		}
		else
		{
			result = std::to_string(num) + result;
		}
	}
	if (minus && result != "0")
	{
		result = "-" + result;
	}
	return result;
}


void PrintHelp() 
{
	std::cout << "radix.exe <source notation> <destination notation> <value> \n";
	std::cout << "EXAMPLE: radix.exe \"16\" \"10\" \"1F\"\n";
}

bool checkNotation(int notation)
{
	return (notation >= 2 && notation <= 36);
}


int Application(std::string sourceStr, std::string destStr, std::string valueStr)
{
	int source = atoi(sourceStr.c_str());
	int destination = atoi(destStr.c_str());

	bool wasError = false;
	if (checkNotation(source) && checkNotation(destination))
	{
		int decNumber = SourceNotationToDec(valueStr, source, wasError);
		if (!wasError)
		{
			std::string result = DecToDestinationNotation(decNumber, destination);
			std::cout << result << "\n";
		}
		else
		{
			std::cout << "incorrect value. value = 0-9 and A-Z and should be in the source notation\n";
			std::cout << "Example: task2.exe \"36\" \"10\" \"27WZ\"\n";
			return 1;
		}
	}
	else
	{
		std::cout << "incorrect input bit. Bit should be from 2 to 36 \n";
		return 1;
	}
	return 0;
}

int main(int argc, char * argv[])
{
	if (argc > 4)
	{
		std::cout << "you have many arguments\n";
		PrintHelp();
	}
	else if (argc < 4)
	{
		std::cout << "you have too few arguments\n";
		PrintHelp();
	}
	else
	{
		return Application(argv[1], argv[2], argv[3]);
	}
	return 1;
}
