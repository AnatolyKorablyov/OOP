#include "stdafx.h"
#include <boost/test/unit_test.hpp>
#include "..\task02\Calculator.h"
#include "..\task02\UserInteration.h"
#include "..\task02\Definition.h"

struct CalculatorFixture
{
	CCalculator calc;
};



BOOST_FIXTURE_TEST_SUITE(Calculator, CalculatorFixture)

//////////////////////////////////////////////////////////////////////////
// Var
//////////////////////////////////////////////////////////////////////////

	BOOST_AUTO_TEST_CASE(getVarFailed)
	{
		BOOST_CHECK(calc.GetVar("x").valueInfo == FoundValueInfo::noValue);
	}
	BOOST_AUTO_TEST_CASE(setUncorrectNameVarFailed)
	{
		BOOST_CHECK(calc.SetVar("1xAZ") == ReturnCode::idNameNotCorrect);
	}
	BOOST_AUTO_TEST_CASE(setCorrectNameVarComplete)
	{
		BOOST_CHECK(calc.SetVar("_AZ19az") == ReturnCode::AllOk);
	}
	BOOST_AUTO_TEST_CASE(setIncorrectNameVarComplete)
	{
		BOOST_CHECK(calc.SetVar("&hello") == ReturnCode::idNameNotCorrect);
	}
	struct SetNewVar_x : CalculatorFixture
	{
		SetNewVar_x()
		{
			calc.SetVar("x");
		}
	};

	BOOST_FIXTURE_TEST_SUITE(set_new_var_x, SetNewVar_x)
		BOOST_AUTO_TEST_CASE(SetVarComplete)
		{
			BOOST_CHECK(calc.GetVar("x").value != calc.GetVar("x").value);
		}
		BOOST_AUTO_TEST_CASE(SetVarFailed)
		{
			BOOST_CHECK(calc.SetVar("x") == ReturnCode::varUsesIdName);
		}
	BOOST_AUTO_TEST_SUITE_END()

//////////////////////////////////////////////////////////////////////////
// let
//////////////////////////////////////////////////////////////////////////

	BOOST_AUTO_TEST_CASE(SetLetVarFailed_var_not_found)
	{
		BOOST_CHECK(calc.SetLetVar("x", "y") == ReturnCode::numberNotCorrect);
	}
	BOOST_AUTO_TEST_CASE(SetVar_MinusDouble)
	{
		calc.SetLetVar("x", "-34.5");
		BOOST_CHECK(calc.GetVar("x").value == -34.5);
	}

	struct SetNewVar_x_13 : CalculatorFixture
	{
		SetNewVar_x_13()
		{
			calc.SetLetVar("x", "34");
		}
	};

	BOOST_FIXTURE_TEST_SUITE(set_new_var_x_13, SetNewVar_x_13)
		BOOST_AUTO_TEST_CASE(SetLetDoubleComplete)
		{
			calc.SetLetVar("x", "57");
			BOOST_CHECK(calc.GetVar("x").value == 57);
		}
		BOOST_AUTO_TEST_CASE(SetLetVarComplete)
		{
			calc.SetLetVar("y", "x");
			BOOST_CHECK(calc.GetVar("x").value == 34.0);
		}
		BOOST_AUTO_TEST_CASE(SetLetVarFailed_identificator2_NOT_Found)
		{
			BOOST_CHECK(calc.SetLetVar("x", "notVar") == ReturnCode::numberNotCorrect);
		}

//////////////////////////////////////////////////////////////////////////
// Fn
//////////////////////////////////////////////////////////////////////////

		BOOST_AUTO_TEST_CASE(SetFunctionValueComplete)
		{
			calc.SetFnValue("function", "x");
			BOOST_CHECK(calc.GetFn("function").value == 34.0);
		}
		
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_CASE(SetFunctionValueFailed_no_var)
	{
		BOOST_CHECK(calc.SetFnValue("function", "noVar") == ReturnCode::valueSecondIdNotFound);
	}

	BOOST_AUTO_TEST_CASE(SetFunction_no_Function)
	{
		BOOST_CHECK(calc.GetFn("function").valueInfo == FoundValueInfo::noValue);
	}

	struct SetNewVar_for_function : CalculatorFixture
	{
		SetNewVar_for_function()
		{
			calc.SetLetVar("x", "47");
			calc.SetLetVar("y", "3");
			calc.SetFnValue("f0", "x");
		}
	};

	BOOST_FIXTURE_TEST_SUITE(check_Fn, SetNewVar_for_function)

		BOOST_AUTO_TEST_CASE(SetFunctionComplete_x_changed)
		{
			calc.SetFnValue("f0", "x");
			calc.SetLetVar("x", "23");
			BOOST_CHECK_EQUAL(calc.GetFn("f0").value, 23);
		}
		BOOST_AUTO_TEST_CASE(SetFunctionComplete_Add)
		{
			calc.SetFnOperand("function", "x", OperandType::Add, "y");
			BOOST_CHECK_EQUAL(calc.GetFn("function").value, 50);
		}
		BOOST_AUTO_TEST_CASE(SetFunctionComplete_Sub)
		{
			calc.SetFnOperand("function", "x", OperandType::Sub, "y");
			BOOST_CHECK_EQUAL(calc.GetFn("function").value, 44);
		}
		BOOST_AUTO_TEST_CASE(SetFunctionComplete_Div)
		{
			calc.SetFnOperand("function", "x", OperandType::Div, "y");
			double value = round(calc.GetFn("function").value * 100) / 100;
			BOOST_CHECK_EQUAL(value, 15.67);
		}
		BOOST_AUTO_TEST_CASE(SetFunctionComplete_Mul)
		{
			calc.SetFnOperand("function", "x", OperandType::Mul, "y");
			BOOST_CHECK_EQUAL(calc.GetFn("function").value, 141);
		}
		BOOST_AUTO_TEST_CASE(SetFunctionComplete_Div_Zero)
		{
			calc.SetLetVar("zero", "0");
			calc.SetFnOperand("function", "x", OperandType::Div, "zero");
			BOOST_CHECK(calc.GetFn("function").value == INFINITY);
		}
		BOOST_AUTO_TEST_CASE(SetFunctionFailed_varFound)
		{
			BOOST_CHECK(calc.SetFnValue("y", "x") == ReturnCode::varUsesIdName);
		}
		BOOST_AUTO_TEST_CASE(SetFunctionFailed_fnFound)
		{
			BOOST_CHECK(calc.SetFnValue("f0", "x") == ReturnCode::FnUsesIdName);
		}
	BOOST_AUTO_TEST_SUITE_END()

	struct Set_for_Fibonacci : CalculatorFixture
	{
		Set_for_Fibonacci()
		{
			calc.SetLetVar("x", "0");
			calc.SetLetVar("y", "1");
			calc.SetFnValue("f0", "x");
			calc.SetFnValue("f1", "y");
		}
	};
	BOOST_FIXTURE_TEST_SUITE(Fibonacci, Set_for_Fibonacci)
		BOOST_AUTO_TEST_CASE(SetFunctionComplete_Recursion)
		{
			for (unsigned i = 2; i < 7; ++i)
			{
				calc.SetFnOperand("f" + std::to_string(i), "f" + std::to_string(i - 1), OperandType::Add, "f" + std::to_string(i - 2));
			}
			BOOST_CHECK(calc.GetFn("f6").value == 8);
		}
		BOOST_AUTO_TEST_CASE(SetFunctionComplete_changed_var)
		{
			for (unsigned i = 2; i < 7; ++i)
			{
				calc.SetFnOperand("f" + std::to_string(i), "f" + std::to_string(i - 1), OperandType::Add, "f" + std::to_string(i - 2));
			}
			calc.SetLetVar("x", "1");
			BOOST_CHECK(calc.GetFn("f6").value == 13);
		}
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()