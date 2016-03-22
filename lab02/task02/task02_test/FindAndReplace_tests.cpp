#include "stdafx.h"
#include <boost/test/unit_test.hpp>
#include "FindAndReplace.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(Replace_function)

BOOST_AUTO_TEST_CASE(replace_ma_to_mama)
{
	string subject = "mama mula ramu ma";
	string search = "ma";
	string replace = "mama";
	BOOST_CHECK_EQUAL(FindAndReplace(subject, search, replace), "mamamama mula ramu mama");
}
BOOST_AUTO_TEST_CASE(replace_numbers)
{
	string subject = "12312312345";
	string search = "1231234";
	string replace = "TABULATION";
	BOOST_CHECK_EQUAL(FindAndReplace(subject, search, replace), "123TABULATION5");
}
BOOST_AUTO_TEST_CASE(replace_empty_search)
{
	string subject = "Empty";
	string search = "";
	string replace = "123";
	BOOST_CHECK_EQUAL(FindAndReplace(subject, search, replace), "Empty");
}

BOOST_AUTO_TEST_CASE(replace_empty_replace)
{
	string subject = "Empty";
	string search = "123";
	string replace = "";
	FindAndReplace(subject, search, replace);
	BOOST_CHECK_EQUAL(FindAndReplace(subject, search, replace), "Empty");
}

BOOST_AUTO_TEST_CASE(replace_empty_subject)
{
	string subject = "";
	string search = "123";
	string replace = "321";
	BOOST_CHECK_EQUAL(FindAndReplace(subject, search, replace), "");
}
BOOST_AUTO_TEST_SUITE_END()


