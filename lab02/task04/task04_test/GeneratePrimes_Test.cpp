#include "stdafx.h"
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
#include "GeneratePrimes.h"


BOOST_AUTO_TEST_SUITE(AddNewWordInDictionary_function)
BOOST_AUTO_TEST_CASE(very_many)
{																					
	set<int> numbers = GeneratePrimes(100'000'000);
	BOOST_CHECK_EQUAL(GeneratePrimes(100'000'000).size(), 5'761'455);
}

BOOST_AUTO_TEST_CASE(check_zero)
{
	set<int> numbers = GeneratePrimes(0);
	set<int> standart = set<int>();
	BOOST_CHECK_EQUAL_COLLECTIONS(numbers.begin(), numbers.end(), standart.begin(), standart.end());
}

BOOST_AUTO_TEST_CASE(check_5)
{
	set<int> numbers = GeneratePrimes(5);
	set<int> standart = set<int>({2, 3, 5});
	BOOST_CHECK_EQUAL_COLLECTIONS(numbers.begin(), numbers.end(), standart.begin(), standart.end());
}
BOOST_AUTO_TEST_SUITE_END()