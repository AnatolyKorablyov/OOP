#include "stdafx.h"
#include <boost/test/unit_test.hpp>
#include "..\task02\Calculator.h"

BOOST_AUTO_TEST_SUITE(Go_var)
BOOST_AUTO_TEST_CASE(SetVarComplete)
{
	CCalculator calc;
	calc.SetVar("x");
	BOOST_CHECK(calc.GetVar("x").value != calc.GetVar("x").value);
}
BOOST_AUTO_TEST_CASE(SetVarFailed)
{
	CCalculator calc;
	calc.SetVar("x");
	BOOST_CHECK(!calc.SetVar("x"));
}
BOOST_AUTO_TEST_CASE(getVarFailed)
{
	CCalculator calc;
	BOOST_CHECK(calc.GetVar("x").wasError == GetError::noValue);
}
BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(Go_let)
BOOST_AUTO_TEST_CASE(SetLetDoubleComplete)
{
	CCalculator calc;
	calc.SetLetVar("x", "13");
	BOOST_CHECK(calc.GetVar("x").value == 13);
}
BOOST_AUTO_TEST_CASE(SetLetVarComplete)
{
	CCalculator calc;
	calc.SetLetVar("y", "34");
	calc.SetLetVar("x", "y");
	BOOST_CHECK(calc.GetVar("x").value == 34.0);
}
BOOST_AUTO_TEST_CASE(SetLetVarFailed)
{
	CCalculator calc;
	BOOST_CHECK(!calc.SetLetVar("x", "y"));
}
BOOST_AUTO_TEST_SUITE_END()