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
BOOST_AUTO_TEST_CASE(create_stlString)
{
	CMyString myString("hello world!");
	BOOST_CHECK_EQUAL(myString.GetLength(), 12);
	BOOST_CHECK_EQUAL(myString.GetStringData(), '\0');
}
BOOST_AUTO_TEST_SUITE_END()