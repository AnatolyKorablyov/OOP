#include "stdafx.h"
#include <boost/test/unit_test.hpp>
#include "..\task03\Mini_Dictionary.h"

BOOST_AUTO_TEST_SUITE(AddNewWordInDictionary_function)
BOOST_AUTO_TEST_CASE(ask_user)
{
	map<string, string> dict;
	dict.insert(pair<string, string>("cat", "кошка"));
	string key = "cat";
	BOOST_CHECK_EQUAL(FindWord(dict, key), "кошка");
}

BOOST_AUTO_TEST_CASE(add_word_to_dict)
{
	map<string, string> dict;
	string key = "cat";
	string value = "котэ";
	BOOST_CHECK(SaveWordInDict(dict, key, value));
}

BOOST_AUTO_TEST_CASE(find_value_on_key)
{
	map<string, string> dict = { { "cat", "кот" },{ "dog", "пес" }};
	BOOST_CHECK_EQUAL(FindWord(dict, "dog"), "пес");
}

BOOST_AUTO_TEST_CASE(find_value_in_empty_dictionary)
{
	map<string, string> dict;
	BOOST_CHECK_EQUAL(FindWord(dict, "dog"), "");
}

BOOST_AUTO_TEST_CASE(write_dictionary_in_file)
{
	map<string, string> dict; dict = { { "cat", "кот" },{ "dog", "собака" }};
	SaveDictToFile(dict, "output.txt");
	BOOST_CHECK(CheckEmptyFile("output.txt"));
}

BOOST_AUTO_TEST_SUITE_END()