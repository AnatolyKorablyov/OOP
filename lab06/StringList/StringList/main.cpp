// StringList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "StringList.h"

int main()
{
	CStringList lst;
	lst.Append("Hi");
	std::cout << lst;
    return 0;
}

