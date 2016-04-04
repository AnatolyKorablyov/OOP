#include "stdafx.h"
#include "UserInteration.h"
#include "Definition.h"



bool HandlerCommands(CCalculator & calc, const string & mainRequest)
{
	std::cout << mainRequest << std::endl;
	string identificator1;

	GetValInfo answer;
	size_t posStart = mainRequest.find("var ");
	size_t posEnd = posStart + 4;
	if (posStart < mainRequest.length())
	{
		identificator1.append(mainRequest.begin() + posEnd, mainRequest.end());
		std::cout << "|" << identificator1 << "|" << std::endl;
		calc.SetVar(identificator1);
		return true;
	}
	else if ((posStart = mainRequest.find("let ")) < mainRequest.length())
	{
		posEnd = posStart + 4;
		posStart = mainRequest.find("=", posEnd);
		identificator1.append(mainRequest, posEnd, posStart - posEnd);

		string identificator2;

		posEnd = posStart + 1;
		identificator2.append(mainRequest.begin() + posEnd, mainRequest.end());
		calc.SetLetVar(identificator1, identificator2);
		std::cout << "|" << identificator1 << "|" << std::endl;
		std::cout << "|" << identificator2 << "|" << std::endl;
		return true;
	}
	else if ((posStart = mainRequest.find("fn ")) < mainRequest.length())
	{
		posEnd = posStart + 3;
		posStart = mainRequest.find("=", posEnd);
		identificator1.append(mainRequest, posEnd, posStart - posEnd);
		posEnd = posStart + 1;

		OperandType operand;
		string identificator2;
		if ((posStart = mainRequest.find("+", posEnd)) < mainRequest.length())
		{
			operand = OperandType::Add;
		}
		else if ((posStart = mainRequest.find("-", posEnd)) < mainRequest.length())
		{
			operand = OperandType::Sub;
		}
		else if ((posStart = mainRequest.find("/", posEnd)) < mainRequest.length())
		{
			operand = OperandType::Div;
		}
		else if ((posStart = mainRequest.find("*", posEnd)) < mainRequest.length())
		{
			operand = OperandType::Mul;
		}
		else
		{
			identificator2.append(mainRequest.begin() + posEnd, mainRequest.end());
			calc.SetFnValue(identificator1, identificator2);
			std::cout << "|" << identificator1 << "|" << std::endl;
			std::cout << "|" << identificator2 << "|" << std::endl;
			return true;
		}
		identificator2.append(mainRequest, posEnd, posStart - posEnd);
		string identificator3;
		posEnd = posStart + 1;
		identificator3.append(mainRequest.begin() + posEnd, mainRequest.end());
		calc.SetFnOperand(identificator1, identificator2, operand, identificator3);

		std::cout << "|" << identificator1 << "|" << std::endl;
		std::cout << "|" << identificator2 << "|" << std::endl;
		std::cout << "|" << identificator3 << "|" << std::endl;
		return true;
	}
	else if ((posStart = mainRequest.find("print ")) < mainRequest.length())
	{
		posEnd = posStart + 6;
		identificator1.append(mainRequest.begin() + posEnd, mainRequest.end());
		std::cout << "|" << identificator1 << "|" << std::endl;
		answer = calc.GetVar(identificator1);
		if (answer.wasError == GetError::noValue)
		{
			answer = calc.GetFn(identificator1);
		}
		std::cout << answer.value << std::endl;
		return true;
	}
	else if (mainRequest == "printvars")
	{
		
	}
	else if (mainRequest == "printfns")
	{

	}
	return false;
}

void Mathematician()
{
	CCalculator calc;
	std::string userCommand;
	std::getline(std::cin, userCommand);
	while (userCommand != "...")
	{
		if (userCommand.length() > 0)
		{
			HandlerCommands(calc, userCommand);
		}
		std::getline(std::cin, userCommand);
	}
}