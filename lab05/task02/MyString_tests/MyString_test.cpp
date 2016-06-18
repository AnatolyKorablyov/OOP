#include "stdafx.h"
#include "../MyString/MyString.h"


//////////////////////////////////////////////////////////////////////////
// Initialization
//////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(string_initialization)
BOOST_AUTO_TEST_CASE(empty_string)
{
	CMyString myString;
	BOOST_CHECK_EQUAL(myString.GetLength(), 0);
	BOOST_CHECK_EQUAL(myString.GetStringData()[0], '\0');
}
BOOST_AUTO_TEST_CASE(create_char_string)
{
	CMyString myString("hello world!");
	BOOST_CHECK_EQUAL(myString.GetLength(), 12);
	BOOST_CHECK_EQUAL(myString.GetStringData(), "hello world!");
}
BOOST_AUTO_TEST_CASE(create_limit_string)
{
	CMyString myString("hello world!", 6);
	BOOST_CHECK_EQUAL(myString.GetLength(), 6);
	BOOST_CHECK_EQUAL(myString.GetStringData(), "hello ");
}
BOOST_AUTO_TEST_CASE(create_myString_with_myString)
{
	CMyString myStringBegin("hello world!");
	CMyString myString(myStringBegin);
	BOOST_CHECK_EQUAL(myString.GetLength(), 12);
	BOOST_CHECK_EQUAL(myString.GetStringData(), "hello world!");
}
BOOST_AUTO_TEST_CASE(create_stlString)
{
	std::string stlString = "Hello i'm stl string";
	CMyString myString(stlString);
	BOOST_CHECK_EQUAL(myString.GetLength(), 20);
	BOOST_CHECK_EQUAL(myString.GetStringData(), "Hello i'm stl string");
}
BOOST_AUTO_TEST_CASE(create_myString_with_link_to_myString)
{
	CMyString myStringBegin("hello world!");
	CMyString *myString(&myStringBegin);
	BOOST_CHECK_EQUAL(myString->GetLength(), 12);
	BOOST_CHECK_EQUAL(myString->GetStringData(), "hello world!");
	BOOST_CHECK_EQUAL(myStringBegin.GetLength(), 12);
	BOOST_CHECK_EQUAL(myStringBegin.GetStringData(), "hello world!");
}
BOOST_AUTO_TEST_CASE(clear_myString)
{
	CMyString myString("Test string");
	BOOST_CHECK_EQUAL(myString.GetLength(), 11);
	BOOST_CHECK_EQUAL(myString.GetStringData(), "Test string");
	myString.Clear();
	BOOST_CHECK_EQUAL(myString.GetLength(), 0);
	BOOST_CHECK_EQUAL(myString.GetStringData()[0], '\0');
}
BOOST_AUTO_TEST_SUITE_END()


//////////////////////////////////////////////////////////////////////////
// Operators
//////////////////////////////////////////////////////////////////////////

struct hello_world_string
{
	CMyString myString;
	hello_world_string()
		: myString("Hello world")
	{}
};
BOOST_FIXTURE_TEST_SUITE(init_add_operators, hello_world_string)
// +=
BOOST_AUTO_TEST_CASE(unary_add_empty_string)
{
	myString += "";
	BOOST_CHECK_EQUAL(myString.GetLength(), 11);
	BOOST_CHECK_EQUAL(myString.GetStringData(), "Hello world");
}
BOOST_AUTO_TEST_CASE(unary_add_char_string)
{
	myString += " privet medved";
	BOOST_CHECK_EQUAL(myString.GetLength(), 25);
	BOOST_CHECK_EQUAL(myString.GetStringData(), "Hello world privet medved");
}
BOOST_AUTO_TEST_CASE(unary_add_stl_string)
{
	std::string stlString = " i'm stl string";
	myString += stlString;
	BOOST_CHECK_EQUAL(myString.GetLength(), 26);
	BOOST_CHECK_EQUAL(myString.GetStringData(), "Hello world i'm stl string");
}
// +
BOOST_AUTO_TEST_CASE(binary_add_empty_string)
{
	CMyString result = "" + myString;
	BOOST_CHECK_EQUAL(result.GetLength(), 11);
	BOOST_CHECK_EQUAL(result.GetStringData(), "Hello world");
}
BOOST_AUTO_TEST_CASE(binary_add_char_string)
{
	CMyString result =  "privet medved " + myString;
	BOOST_CHECK_EQUAL(result.GetLength(), 25);
	BOOST_CHECK_EQUAL(result.GetStringData(), "privet medved Hello world");
}
BOOST_AUTO_TEST_CASE(binary_stl_string)
{
	std::string stlString = " i'm stl string";
	CMyString result = myString + stlString;
	BOOST_CHECK_EQUAL(result.GetLength(), 26);
	BOOST_CHECK_EQUAL(result.GetStringData(), "Hello world i'm stl string");
}
BOOST_AUTO_TEST_SUITE_END()

//////////////////////////////////////////////////////////////////////////
// Compare
//////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(Compare_operators)
// ==, !=
BOOST_AUTO_TEST_CASE(hello_world_string_and_empty_string)
{
	BOOST_CHECK(!(CMyString("hello world") == CMyString("")));
	BOOST_CHECK(CMyString("hello world") != CMyString(""));
}
BOOST_AUTO_TEST_CASE(hello_world_string_and_hello_world_string)
{
	BOOST_CHECK((CMyString("hello world") == CMyString("hello world")));
	BOOST_CHECK(!(CMyString("hello world") != CMyString("hello world")));
}

// <
BOOST_AUTO_TEST_CASE(can_find_out_which_of_rows_preceded_by_another_in_alphabetical_order)
{
	BOOST_CHECK((CMyString("ab") < CMyString("abc", 3)));
}

BOOST_AUTO_TEST_CASE(left_str_is_not_less_by_right_str)
{
	BOOST_CHECK(!(CMyString("abz") < CMyString("abcd", 3)));
}

BOOST_AUTO_TEST_CASE(if_strings_is_equal_operator_less_return_false)
{
	BOOST_CHECK(!(CMyString("Test", 4u) < CMyString("Test")));
}
BOOST_AUTO_TEST_SUITE_END()


//////////////////////////////////////////////////////////////////////////
// stream
//////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(stream_operators)
BOOST_AUTO_TEST_CASE(istream_operator)
{
	std::ostringstream strm;
	strm << CMyString("hello");
	BOOST_CHECK(strm.str() == "hello");
}
BOOST_AUTO_TEST_CASE(ostream_operator)
{
	CMyString myString;
	std::istringstream strm("medved");
	strm >> myString;
	BOOST_CHECK_EQUAL(myString.GetLength(), 6);
	BOOST_CHECK_EQUAL(myString.GetStringData(), "medved");
}
BOOST_AUTO_TEST_SUITE_END()