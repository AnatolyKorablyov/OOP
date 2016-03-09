#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void AddLines(string(&stringLst)[100], int count)
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

void CorectionLine(string & mainStr)
{
	if (mainStr[mainStr.length() - 1] == '\n')
	{
		mainStr[mainStr.length() - 1] = ' ';
	}

	if (mainStr.length() < 100)
	{
		for (int i = mainStr.length(); i < 100; i++)
		{
			mainStr += " ";
		}
	}
}

bool FindStart(const string & mainStr, vector<pair<int, int>> & posStart, int y)
{
	string localStr = mainStr;
	int border = 100;
	int x = localStr.find("0");
	bool found = false;
	while (x < border && x < localStr.size())
	{
		found = true;
		posStart.push_back(make_pair(x, y));
		border -= x;
		localStr = localStr.substr(x); 
		int x = localStr.find("0");
	}
	return found;
}

bool ReadFile(string inputFileName, string (&massString)[100], vector<pair<int, int>> & posStart)
{
	ifstream inputFile(inputFileName);
	if (!inputFile.is_open())
	{
		cout << "File not found!" << endl;
		return false;
	}

	bool foundPosition = false;
	int count = 0;
	while (!inputFile.eof())
	{
		bool found = false;
		string mainStr;
		getline(inputFile, mainStr);
		found = FindStart(mainStr, posStart, count);
		CorectionLine(mainStr);
		massString[count] = mainStr.substr(0, 100) + "\n";
		count++;
		if (found)
		{
			foundPosition = true;
		}
	}
	AddLines(massString, count);
	return foundPosition;
}

void FillContour(string(&stringLst)[100], const vector<pair<int, int>> & posStart)
{
	vector<pair<int, int>> coordinateLst = posStart;
	while (coordinateLst.size() > 0)
	{
		int x = coordinateLst[0].first;
		int y = coordinateLst[0].second;
		if (stringLst[y][x] != '.' && stringLst[y][x] != '#')
		{
			stringLst[y][x] = '.';
			if (x > 0)
			{
				coordinateLst.push_back(make_pair(x - 1, y));
			}
			if (x < 99)
			{
				coordinateLst.push_back(make_pair(x + 1, y));
			}
			if (y > 0)
			{
				coordinateLst.push_back(make_pair(x, y - 1));
			}
			if (y < 99)
			{
				coordinateLst.push_back(make_pair(x, y + 1));
			}
		}
		coordinateLst.erase(coordinateLst.begin());
	}
}

void FilingArea(const string & inputFileName, const string & outputFileName)
{
	string stringsArray[100];
	vector<pair<int, int>> posStart;
	if (ReadFile(inputFileName, stringsArray, posStart))
	{
		FillContour(stringsArray, posStart);
		for (auto i : posStart)
		{
			stringsArray[i.second][i.first] = '0';
		}
	}

	ofstream outFile(outputFileName);

	for (int i = 0; i < 100; i++)
	{
		outFile << stringsArray[i];
	}
}

void PrintExample() 
{
	cout << "fill.exe <input file> <output file> <value>" << endl;
	cout << "EXAMPLE: fill.exe \"test.txt\" \"out.txt\"" << endl;
}

int main(int argc, char * argv[])
{
	cout << "hi" << endl;
	if (argc != 3)
	{
		PrintExample();
	}
	else
	{
		FilingArea(argv[1], argv[2]);
		return 0;
	}
	return 1;
}