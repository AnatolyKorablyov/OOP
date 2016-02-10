#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sys/stat.h>

bool CheckSizeFile(std::string nameFile)
{
	struct stat file;
	stat(nameFile.c_str(), &file);
	return (file.st_size > 0 && file.st_size < 2147483648);
}

void InputTextInFile(std::string nameFile, std::vector<std::string> &text) 
{
	std::ifstream inpFile(nameFile);
	
	if (!inpFile.is_open()) 
	{
		std::cout<< "Error open file\n";
		system("pause");
		exit(1);
	}
	else if (!CheckSizeFile(nameFile))
	{
		std::cout << "Error! File very big size or 0";
		system("pause");
		exit(1);
	}
	while (!inpFile.eof())
	{	
		std::string string;
		std::getline(inpFile, string);
		text.push_back(string);
	}
}

void OutputTextInFile(std::string nameFile, std::vector<std::string> text)
{
	std::ofstream outFile(nameFile);
	for (auto i : text) {
		outFile << i << "\n";
	}
}

void FindAndReplaceString(std::vector<std::string> &lst_str, std::string replaceableStr, std::string replacementStr) 
{
	std::string::size_type pos;
	for (int i = 0; i < int(lst_str.size()); i++)
	{	
		bool slice = false;
		std::string localSTR = lst_str[i];
		pos = localSTR.find(replaceableStr);
		if (pos < localSTR.length())
		{
			lst_str[i].clear();
			slice = true;
		}
		while (pos < localSTR.length())
		{
			localSTR.replace(pos, replaceableStr.length(), replacementStr);
			lst_str[i] += localSTR.substr(0, pos + replacementStr.length());
			localSTR.replace(0, pos + replacementStr.length(), "");
			pos = localSTR.find(replacementStr);
		}
		if (slice && localSTR.size() > 0) 
		{
			lst_str[i] += localSTR.substr(0, pos + replacementStr.length());
		}
	}
}

void PrintExample()
{
	std::cout << "EXAMPLE: lab1.exe \"input.txt\" \"output.txt\" \"replaceable word\" \"replacement word\" \n";
}


int main(int argc, char * argv[]) 
{	
	if (argc > 5)
	{
		std::cout << "you have many arguments\n";
		PrintExample();
	}
	else if (argc < 5)
	{
		std::cout << "you have too few arguments\n";
		PrintExample();
	}
	else
	{
		std::vector<std::string> lst_strings = {};
		std::string nameInputFile = argv[1];
		std::string nameOutputFile = argv[2];
		std::string replaceableStr = argv[3];
		std::string replacementStr = argv[4];
		
		InputTextInFile(nameInputFile, lst_strings);

		if (replaceableStr.length() > 0)
		{
			FindAndReplaceString(lst_strings, replaceableStr, replacementStr);
		}
		OutputTextInFile(nameOutputFile, lst_strings);
	}

	system("pause");
	return 0;
}