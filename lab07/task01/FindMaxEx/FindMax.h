#pragma once
#include "stdafx.h"

template<typename T, typename Less>
bool FindMax(std::vector<T>const & arr, T & maxValue, Less const & less)
{
	if (arr.empty())
	{
		return false;
	}
	T localMaxNumber = arr.front();
	for (auto i: arr)
	{
		if (less(localMaxNumber, i))
		{
			localMaxNumber = i;
		}
	}
	maxValue = localMaxNumber;
	return true;
}