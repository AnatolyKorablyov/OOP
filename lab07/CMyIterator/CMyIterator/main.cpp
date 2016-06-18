// CMyIterator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CMyArray.h"
#include <iostream>

int main()
{
	
	CMyArray<int> arr({ 1, 2, 3, 4 });
	std::cout << arr.begin() << std::cout;
    return 0;
}

