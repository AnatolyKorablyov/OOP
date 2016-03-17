// Lab2Task2Var3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;


int main(int argc, char** argv)
{
	if (argc != 3)
	{
		cout << "Example: lab.exe \"search word\" \"replace word\"";
		return 1;
	}
	string search = argv[1];
	string replace = argv[2];

	subject = (FindAndReplace(subject, search, replace));
	return 0;
}

