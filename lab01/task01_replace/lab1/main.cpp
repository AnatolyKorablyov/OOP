#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
#include <sys/stat.h>

using namespace std;

bool CheckSizeFile(const string & nameFile)
{
	struct stat file;
	stat(nameFile.c_str(), &file);
	return (file.st_size > 0 && file.st_size < 2147483648);
}


void ReplacingString(string & mainStr, const string & needleStr, const string & hayStr)
{
	string::size_type posStart;
	string::size_type posEnd;

	string localStr = "";
	posEnd = mainStr.find(needleStr);

	int lenNeedle = needleStr.length();
	int lenHay = hayStr.length();

	while (posEnd < mainStr.length())
	{
		localStr += mainStr.substr(0, posEnd) + hayStr;
		posStart = posEnd + lenNeedle;
		mainStr = mainStr.substr(posStart);
		posEnd = mainStr.find(lenHay);
	}
	mainStr = localStr + mainStr;
}


int ReplacingStringsInFile(char * argv[])
{
	string inputFileName = argv[1];
	string outputFileName = argv[2];
	string needleStr = argv[3];
	string hayStr = argv[4];

	ifstream inpFile(inputFileName);
	if (!inpFile.is_open()) 
	{
		cout<< "Error open file" << endl;
		return 1;
	}
	else if (!CheckSizeFile(inputFileName))
	{
		cout << "Error! File very big size or 0" << endl;
		return 1;
	}

	ofstream outFile(outputFileName);

	while (!inpFile.eof())
	{	
		string string;
		getline(inpFile, string);
		if (needleStr.length() > 0)
		{
			ReplacingString(string, needleStr, hayStr);
		}
		outFile << string << endl;
	}
	return 0;
}

void PrintHelp()
{
	cout << "EXAMPLE: lab1.exe \"input.txt\" \"output.txt\" \"replaceable word\" \"replacement word\"" << endl;
}

int main(int argc, char * argv[]) 
{	
	if (argc > 5)
	{
		cout << "you have many arguments" << endl;
		PrintHelp();
	}
	else if (argc < 5)
	{
		cout << "you have too few arguments" << endl;
		PrintHelp();
	}
	else
	{	
		return ReplacingStringsInFile(argv);
	}
	return 1;
}