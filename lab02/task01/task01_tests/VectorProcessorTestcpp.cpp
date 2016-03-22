#include "stdafx.h"
#include "..\task1\VectorProcessor.h"
#include <boost/test/unit_test.hpp>

using namespace std;

// Функция ProcessVector
BOOST_AUTO_TEST_SUITE(ProcessVector_function)

// Создает пустой вектор из пустого вектора
BOOST_AUTO_TEST_CASE(makes_empty_vector_from_empty_vector)
{
	vector<double> emptyVector;
	ProcessVector(emptyVector);
	BOOST_CHECK(emptyVector.empty());
}

BOOST_AUTO_TEST_CASE(makes_do_not_change_vector_from_zero_vector)
{
	vector<double> numbers = { 0, 0, 0 };
	ProcessVector(numbers);
	BOOST_CHECK(numbers == vector<double>({ 0, 0, 0 }));
}

BOOST_AUTO_TEST_CASE(then_zero_min_number_in_vector)
{
	vector<double> numbers = { 0, 3.5 };
	ProcessVector(numbers);
	BOOST_CHECK(numbers == vector<double>({ 0, 0 }));
}

BOOST_AUTO_TEST_SUITE_END()


