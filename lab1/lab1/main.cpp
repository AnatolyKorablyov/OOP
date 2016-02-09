#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sys/stat.h>

bool check_size_file(std::string nameFile)
{
	struct stat file;
	stat(nameFile.c_str(), &file);
	return (file.st_size > 0 && file.st_size < 2147483648);
}

void input_text_in_file(std::string nameFile, std::vector<std::string> &text) 
{
	std::ifstream inpFile(nameFile);
	
	if (!inpFile.is_open()) 
	{
		std::cout<< "Error open file\n";
		system("pause");
		exit(1);
	}
	else if (!check_size_file(nameFile)) 
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

void output_text_in_file(std::string nameFile, std::vector<std::string> text)
{
	std::ofstream outFile(nameFile);
	for (auto i : text) {
		outFile << i << "\n";
	}
}

void find_and_replace_string(std::vector<std::string> &lst_str, std::string replaceAblestr, std::string replaceMentstr) 
{
	std::string::size_type pos;
	for (int i = 0; i < int(lst_str.size()); i++)
	{	
		bool slice = false;
		std::string localSTR = lst_str[i];
		pos = localSTR.find(replaceAblestr);
		if (pos < localSTR.length())
		{
			lst_str[i].clear();
			slice = true;
		}
		while (pos < localSTR.length())
		{
			localSTR.replace(pos, replaceAblestr.length(), replaceMentstr);
			lst_str[i] += localSTR.substr(0, pos + replaceMentstr.length());
			localSTR.replace(0, pos + replaceMentstr.length(), "");
			pos = localSTR.find(replaceAblestr);
		}
		if (slice && localSTR.size() > 0) 
		{
			lst_str[i] += localSTR.substr(0, pos + replaceMentstr.length());
		}
	}
}

int main(int argc, char * argv[]) 
{	
	if (argc > 5) 
	{
		std::cout << "you have many arguments\n";
	}
	else if (argc < 5)
	{
		std::cout << "you have too few arguments\n";
	}
	else
	{
		std::vector<std::string> lst_strings = {};
		std::string nameInputFile = argv[1];
		std::string nameOutputFile = argv[2];
		std::string replaceableStr = argv[3];
		std::string replacementStr = argv[4];
		
		input_text_in_file(nameInputFile, lst_strings);

		if (replaceableStr.length() > 0)
		{
			find_and_replace_string(lst_strings, replaceableStr, replacementStr);
		}
		output_text_in_file(nameOutputFile, lst_strings);
	}

	system("pause");
	return 0;
}