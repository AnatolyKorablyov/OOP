#include <iostream>
#include <string>
#include <cmath>

int SourceNotationToDec(std::string byte, const int & sourceNotation) 
{
	bool minus = false;
	if ((int)byte[0] == 45)
	{
		minus = true;
		byte = byte.substr(1);
	}
	int count = byte.length() - 1;
	int result = 0;
	while (byte.length() > 0)
	{
		if ((int)byte[0] < 91 && (int)byte[0] > 64)
		{
			result += ((int)byte[0] - 55) * pow(sourceNotation, count);
		}
		else if ((int)byte[0] > 47 && (int)byte[0] < 58)
		{
			result += ((int)byte[0] - 48) * pow(sourceNotation, count);
		}
		else
		{
			if ((int)byte[0] > 96 && (int)byte[0] < 123)
			{
				byte[0] = (char)((int)byte[0] - 31);
			}
			else
			{
				std::cout << "incorrect format\n";
			}
		}
		byte = byte.substr(1);
		count --;
	}
	if (minus)
	{
		result *= -1;
	}
	return result;
}

std::string DecToDestinationNotation(int decNumber, const int & desNot)
{
	bool minus = false;
	if (decNumber < 0)
	{
		minus = true;
		decNumber *= -1;
	}
	std::string binary = "";
	while (decNumber > 0)
	{
		int num = 0;
		num = decNumber - desNot * (decNumber / desNot);
		decNumber = decNumber / desNot;
		if (num - 10 >= 0)
		{
			int sasd = num - 10;
			binary = (char)(65 + sasd) + binary;
		}
		else
		{
			binary = std::to_string(num) + binary;
		}
	}
	if (minus)
	{
		binary = "-" + binary;
	}
	return binary;
}

void PrintExample() 
{
	std::cout << "radix.exe <source notation> <destination notation> <value> \n";
	std::cout << "EXAMPLE: radix.exe \"16\" \"10\" \"1F\"\n";
}
int main(int argc, char * argv[])
{
	if (argc > 4)
	{
		std::cout << "you have many arguments\n";
		PrintExample();
	}
	else if (argc < 4)
	{
		std::cout << "you have too few arguments\n";
		PrintExample();
	}
	else
	{
		std::string value = argv[1];
		int source = atoi(value.c_str());
		value = argv[2];
		int destination = atoi(value.c_str());
		value = argv[3];

		int decNumber = SourceNotationToDec(value, source);
		std::string result = DecToDestinationNotation(decNumber, destination);

		std::cout << result << "\n";
	}
	system("pause");
	return 0;
}