#include "stdafx.h"
#include "../FindMaxEx/FindMax.h"

struct NumbersStructure
{
	std::vector<int> numbers;
	int maxNumber = 0;
};

BOOST_FIXTURE_TEST_SUITE(Find_max_in_numbers, NumbersStructure)

	BOOST_AUTO_TEST_CASE(can_not_find_with_empty_vector_of_numbers)
	{
		BOOST_CHECK(!FindMax(numbers, maxNumber, [](int left, int right)
		{
			return left < right;
		}));
	}
	BOOST_AUTO_TEST_CASE(find_max_element_in_one_element_vector_number)
	{
		numbers.push_back(3);
		BOOST_CHECK(FindMax(numbers, maxNumber, [](int left, int right)
		{
			return left < right;
		}));
		BOOST_CHECK_EQUAL(maxNumber, 3);
	}
	BOOST_AUTO_TEST_CASE(find_max_in_negative_element_number)
	{
		numbers.push_back(-3);
		numbers.push_back(-8);
		BOOST_CHECK(FindMax(numbers, maxNumber, [](int left, int right)
		{
			return left < right;
		}));
		BOOST_CHECK_EQUAL(maxNumber, -3);
	}
	BOOST_AUTO_TEST_CASE(find_max_in_negative_and_zero_vector_number)
	{
		numbers.push_back(-3);
		numbers.push_back(0);
		BOOST_CHECK(FindMax(numbers, maxNumber, [](int left, int right)
		{
			return left < right;
		}));
		BOOST_CHECK_EQUAL(maxNumber, 0);
	}
BOOST_AUTO_TEST_SUITE_END()


struct StringStructure
{
	std::vector<std::string> strings;
	std::string maxString = "";
};

BOOST_FIXTURE_TEST_SUITE(Find_max_in_string, StringStructure)

BOOST_AUTO_TEST_CASE(can_not_find_max_with_empty_vector_string)
{
	BOOST_CHECK(!FindMax(strings, maxString, [](std::string left, std::string right)
	{
		if (strcmp(left.c_str(), right.c_str()) < 0)
		{
			return true;
		}
		return false;
	}));
}
BOOST_AUTO_TEST_CASE(_with_one_element)
{
	strings.push_back("Vasya");
	BOOST_CHECK(FindMax(strings, maxString, [](std::string left, std::string right)
	{
		if (strcmp(left.c_str(), right.c_str()) < 0)
		{
			return true;
		}
		return false;
	}));
	BOOST_CHECK_EQUAL(maxString, "Vasya");
}
BOOST_AUTO_TEST_CASE(throw_with_negative_element)
{
	strings.push_back("Sasha");
	strings.push_back("Masha");
	strings.push_back("Vasya");
	BOOST_CHECK(FindMax(strings, maxString, [](std::string left, std::string right)
	{
		if (strcmp(left.c_str(), right.c_str()) < 0)
		{
			return true;
		}
		return false;
	})); 
	BOOST_CHECK_EQUAL(maxString, "Vasya");
}
BOOST_AUTO_TEST_SUITE_END()
