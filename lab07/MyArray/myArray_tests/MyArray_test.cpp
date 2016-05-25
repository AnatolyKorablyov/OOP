#include "stdafx.h"
#include "../MyArray/MyArray.h"
#include <stdexcept>

struct MyStruct
{
	CMyArray<int> arr;
};

BOOST_FIXTURE_TEST_SUITE(Array_tests, MyStruct)

BOOST_AUTO_TEST_CASE(push_item_widthout_exception)
{
	BOOST_CHECK_NO_THROW(arr.PushBack(0));
}

BOOST_AUTO_TEST_CASE(get_size_tests)
{
	BOOST_CHECK_EQUAL(arr.GetSize(), 0);
	arr.PushBack(0);
	BOOST_CHECK_EQUAL(arr.GetSize(), 1);
	arr.PushBack(0);
	BOOST_CHECK_EQUAL(arr.GetSize(), 2);
	arr.PushBack(0);
	BOOST_CHECK_EQUAL(arr.GetSize(), 3);
}

BOOST_AUTO_TEST_CASE(get_item_by_index)
{
	arr.PushBack(213);
	arr.PushBack(312);
	arr.PushBack(123);
	BOOST_CHECK_EQUAL(arr[0], 213);
	BOOST_CHECK_EQUAL(arr[1], 312);
	BOOST_CHECK_EQUAL(arr[2], 123);
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
	arr.Resize(10, 0);
	arr.Clear();
	BOOST_CHECK_EQUAL(arr.GetSize(), 0);
	BOOST_CHECK_THROW(arr[0], std::out_of_range);
}

BOOST_AUTO_TEST_CASE(assignment_array)
{
	CMyArray<int> arrValue;
	arrValue.PushBack(3);
	arrValue.PushBack(7);
	arrValue.PushBack(9);
	BOOST_CHECK_EQUAL(arr.GetSize(), 0);
	BOOST_CHECK_THROW(arr[0], std::out_of_range);
	arr = arrValue;
	BOOST_CHECK_EQUAL(arr.GetSize(), 3);
	BOOST_CHECK_EQUAL(arr[0], 3);
	BOOST_CHECK_EQUAL(arr[1], 7);
	BOOST_CHECK_EQUAL(arr[2], 9);
}
BOOST_AUTO_TEST_SUITE_END()