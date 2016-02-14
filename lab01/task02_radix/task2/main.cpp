#include <iostream>
#include <string>
#include <cmath>

void CheckNumToSourceNotation(int num, int notation, bool & wasError) 
{
	if (num > notation - 1)
	{
		wasError = true;
	}
}

int SourceNotationToDec(std::string byte, const int & sourceNotation, bool & wasError) 
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
			CheckNumToSourceNotation((int)byte[0] - 55, sourceNotation, wasError);
			result += ((int)byte[0] - 55) * pow(sourceNotation, count);
		}
		else if ((int)byte[0] > 47 && (int)byte[0] < 58)
		{
			CheckNumToSourceNotation((int)byte[0] - 48, sourceNotation, wasError);
			result += ((int)byte[0] - 48) * pow(sourceNotation, count);
		}
		else
		{
			if ((int)byte[0] > 96 && (int)byte[0] < 123)
			{
				CheckNumToSourceNotation((int)byte[0] - 87, sourceNotation, wasError);
				result += ((int)byte[0] - 87) * pow(sourceNotation, count);
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
		byte = byte.substr(1);
		count --;
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
	std::string binary = "";
	if (decNumber < 0)
	{
		minus = true;
		decNumber *= -1;
	}
	else if (decNumber == 0)
	{
		binary = "0";
	}

	while (decNumber > 0)
	{
		int num = 0;
		num = decNumber - destinationNot * (decNumber / destinationNot);
		decNumber = decNumber / destinationNot;
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
	if (minus && binary != "0")
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
		bool wasError = false;
		int decNumber = SourceNotationToDec(value, source, wasError);

		if ((source >= 2 && source <= 36) && (destination >= 2 && destination <= 36))
		{
			if (!wasError)
			{
				std::string result = DecToDestinationNotation(decNumber, destination);
				std::cout << result << "\n";
			}
			else
			{
				std::cout << "incorrect value. value = 0-9 and A-Z and should be in the source notation\n";
				std::cout<<"Example: task2.exe \"36\" \"10\" \"27WZ\"\n";
			}
		}
		else
		{
			std::cout << "incorrect input bit. Bit should be from 2 to 36 \n";
		}
	}
	system("pause");
	return 0;
}