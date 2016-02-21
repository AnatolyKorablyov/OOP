#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
#include <sys/stat.h>

bool CheckSizeFile(std::string nameFile)
{
	struct stat file;
	stat(nameFile.c_str(), &file);
	return (file.st_size > 0 && file.st_size < 2147483648);
}


void FindAndReplaceString(std::string & string, const std::string & searchStr, const std::string & replacementStr)
{
	std::string::size_type posStart;
	std::string::size_type posEnd;

	std::string localSTR = "";
	posEnd = string.find(searchStr);

	int lenSearchStr = searchStr.length();
	int lenReplaceStr = replacementStr.length();

	while (posEnd < string.length())
	{
		localSTR += string.substr(0, posEnd) + replacementStr;
		posStart = posEnd + lenSearchStr;
		string = string.substr(posStart);
		posEnd = string.find(searchStr);
	}
	string = localSTR + string;
}


void Application(char * argv[])
{
	std::string inputFileName = argv[1];
	std::string outputFileName = argv[2];
	std::string replaceableStr = argv[3];
	std::string replacementStr = argv[4];

	std::ifstream inpFile(inputFileName);
	if (!inpFile.is_open()) 
	{
		std::cout<< "Error open file\n";
		exit(1);
	}
	else if (!CheckSizeFile(inputFileName))
	{
		std::cout << "Error! File very big size or 0";
		exit(1);
	}

	std::ofstream outFile(outputFileName);

	while (!inpFile.eof())
	{	
		std::string string;
		std::getline(inpFile, string);
		if (replaceableStr.length() > 0)
		{
			FindAndReplaceString(string, replaceableStr, replacementStr);
		}
		outFile << string << "\n";
	}
}

void PrintHelp()
{
	std::cout << "EXAMPLE: lab1.exe \"input.txt\" \"output.txt\" \"replaceable word\" \"replacement word\" \n";
}


int main(int argc, char * argv[]) 
{	
	if (argc > 5)
	{
		std::cout << "you have many arguments\n";
		PrintHelp();
	}
	else if (argc < 5)
	{
		std::cout << "you have too few arguments\n";
		PrintHelp();
	}
	else
	{	
		Application(argv);
		return 0;
	}
	return 1;
}