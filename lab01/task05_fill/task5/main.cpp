#include <iostream>
#include <string>
#include <fstream>
#include <vector>


void CorrectionFile(std::string(&stringLst)[100], int count)
{
	for (count; count < 100; count++)
	{
		for (int i = 0; i < 100; i++)
		{
			stringLst[count] += " ";
		}
		stringLst[count] += "\n";
	}
}

bool ReadFile(std::string inputFileName, std::string (&massString)[100], std::vector<std::pair<int, int>> & posStart)
{
	std::ifstream inputFile(inputFileName);
	if (!inputFile.is_open())
	{
		std::cout << "File not found!";
		exit(1);
	}

	bool foundPosition = false;
	int count = 0;
	while (!inputFile.eof())
	{
		std::string string;
		std::getline(inputFile, string);
		if (string.find("0") < 100)
		{
			posStart.push_back(std::make_pair(string.find("0"), count));
			foundPosition = true;
		}
		if (string[string.length() - 1] == '\n')
		{
			string[string.length() - 1] = (char)(32);
		}

		if (string.length() < 100)
		{
			for (int i = string.length(); i < 100; i++)
			{
				string += " ";
			}
		}
		massString[count] = string.substr(0, 100) + "\n";
		count++;
	}
	CorrectionFile(massString, count);
	return foundPosition;
}

void FillArea(std::string(&stringLst)[100], std::vector<std::pair<int, int>> coordinateLst)
{
	while (coordinateLst.size() > 0)
	{
		int x = coordinateLst[0].first;
		int y = coordinateLst[0].second;
		if (stringLst[y][x] != '.' && stringLst[y][x] != '#')
		{
			stringLst[y][x] = '.';
			if (x > 0)
			{
				coordinateLst.push_back(std::make_pair(x - 1, y));
			}
			if (x < 99)
			{
				coordinateLst.push_back(std::make_pair(x + 1, y));
			}
			if (y > 0)
			{
				coordinateLst.push_back(std::make_pair(x, y - 1));
			}
			if (y < 99)
			{
				coordinateLst.push_back(std::make_pair(x, y + 1));
			}
		}
		coordinateLst.erase(coordinateLst.begin());
	}
}

void Application(std::string inputFileName, std::string outputFileName)
{
	std::string massString[100];
	std::vector<std::pair<int, int>> posStart;
	if (ReadFile(inputFileName, massString, posStart))
	{
		FillArea(massString, posStart);
		for (auto i : posStart)
		{
			massString[i.second][i.first] = '0';
		}
	}

	std::ofstream outFile(outputFileName);

	for (int i = 0; i < 100; i++)
	{
		outFile << massString[i];
	}
}

void PrintExample() 
{
	std::cout << "fill.exe <input file> <output file> <value> \n";
	std::cout << "EXAMPLE: fill.exe \"test.txt\" \"out.txt\" \n";
}

int main(int argc, char * argv[])
{
	if (argc > 3)
	{
		std::cout << "you have many arguments\n";
		PrintExample();
	}
	else if (argc < 3)
	{
		std::cout << "you have too few arguments\n";
		PrintExample();
	}
	else
	{
		std::string inputFileName = argv[1];
		std::string outputFileName = argv[2];
		Application(inputFileName, outputFileName);
	}
	return 0;
}