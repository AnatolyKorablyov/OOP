// task02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "UserInteration.h"

bool FileMathematician(const std::string & inputFileName)
{
	std::ifstream inpFile(inputFileName);
	CCalculator calc;
	if (!inpFile.is_open())
	{
		std::cout << "Error open file\n";
		return false;
	}
	std::string string;
	while (!inpFile.eof())
	{
		std::getline(inpFile, string);
		HandlerCommands(calc, string);
	}
	return true;
}

int main(int argc, char * argv[])
{
	setlocale(LC_ALL, "RUS");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	if (argc == 2)
	{
		return !FileMathematician(argv[1]);
	}
	else
	{
		Mathematician();
	}
	return 0;
}

