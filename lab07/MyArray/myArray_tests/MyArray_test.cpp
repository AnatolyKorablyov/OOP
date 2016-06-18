#include "stdafx.h"
#include "../MyArray/MyArray.h"
#include <stdexcept>

struct MyStruct
{
	CMyArray<int> arr;
};

BOOST_FIXTURE_TEST_SUITE(Array_tests, MyStruct)
BOOST_AUTO_TEST_CASE(get_size_tests)
{
	BOOST_CHECK_EQUAL(arr.GetSize(), 0);
	arr.Append(0);
	BOOST_CHECK_EQUAL(arr.GetSize(), 1);
	arr.Append(0);
	BOOST_CHECK_EQUAL(arr.GetSize(), 2);
	arr.Append(0);
	BOOST_CHECK_EQUAL(arr.GetSize(), 3);
}

BOOST_AUTO_TEST_CASE(get_item_by_index)
{
	arr.Append(2);
	arr.Append(5);
	arr.Append(7);
	BOOST_CHECK_EQUAL(arr[0], 2);
	BOOST_CHECK_EQUAL(arr[1], 5);
	BOOST_CHECK_EQUAL(arr[2], 7);
	BOOST_CHECK_THROW(arr[3], std::out_of_range);
}

BOOST_AUTO_TEST_CASE(resize_array_width_start_item)
{
	arr.Resize(10, 5);
	BOOST_CHECK_EQUAL(arr.GetSize(), 10);
	BOOST_CHECK_EQUAL(arr[0], 5);
	BOOST_CHECK_EQUAL(arr[9], 5);
	arr.Resize(2, 5);
	BOOST_CHECK_EQUAL(arr.GetSize(), 2);
	BOOST_CHECK_EQUAL(arr[1], 5);
}

BOOST_AUTO_TEST_CASE(clear_array)
{
	arr.Resize(10, 1);
	arr.Clear();
	BOOST_CHECK_EQUAL(arr.GetSize(), 0);
	BOOST_CHECK_THROW(arr[0], std::out_of_range);
}

BOOST_AUTO_TEST_CASE(resize_with_one_argument_default_value)
{
	arr.Resize(10);
	BOOST_CHECK_EQUAL(arr.GetSize(), 10);
	BOOST_CHECK_EQUAL(arr[0], 0);
}

BOOST_AUTO_TEST_CASE(construct_copy_array_elements)
{
	CMyArray<int> arrays({1, 2, 3, 4, 5});
	BOOST_CHECK_EQUAL(arrays.GetSize(), 5);
	BOOST_CHECK_EQUAL(arrays[1], 2);
}

BOOST_AUTO_TEST_CASE(assigment_cmyarray)
{
	CMyArray<int> arrays({ 1, 2, 3, 4, 5 });
	arr = arrays;
	BOOST_CHECK_EQUAL(arr.GetSize(), 5);
	BOOST_CHECK_EQUAL(arr[1], 2);
}

BOOST_AUTO_TEST_CASE(assigment_array_int)
{
	arr = { 1, 2, 3, 4, 5 };
	BOOST_CHECK_EQUAL(arr.GetSize(), 5);
	BOOST_CHECK_EQUAL(arr[2], 3);
}

//BOOST_AUTO_TEST_CASE(iterator_begin)
//{
//	arr = { 1, 2, 3, 4, 5 };
//	CMyArray<int>::myIterator it(arr.begin());
//	int res = 0;
//	for (it = arr.begin(); it != arr.end(); ++it)
//	{
//		++res;
//		BOOST_CHECK_EQUAL(it.GetData(), res);
//	}
//}

BOOST_AUTO_TEST_SUITE_END()