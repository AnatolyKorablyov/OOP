// task02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cassert>
#include "Calculator.h"
#include <iostream>

int main()
{
	CCalculator calc;
	calc.SetLetVar("x", "13");
	calc.SetLetVar("y", "23");
	calc.SetFnOperand("function", "x", OperandType::Mul, "y");
	std::cout << calc.GetFn("function").value << std::endl;
    return 0;
}

