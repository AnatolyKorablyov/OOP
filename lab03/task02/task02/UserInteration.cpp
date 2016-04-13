#include "stdafx.h"
#include "UserInteration.h"
#include "Definition.h"


void PrintAllError(const ReturnCode & wasError) 
{
	switch (wasError)
	{
	case ReturnCode::AllOk:
		break;
	case ReturnCode::idNameNotCorrect:
		std::cout << "Имя переменной введено некорректно" << std::endl;
		break;
	case ReturnCode::numberNotCorrect:
		std::cout << "Число введено некорректно (пример: 12,34; -34,4)" << std::endl;
		break;
	case ReturnCode::FnUsesIdName:
		std::cout << "Найдена функция использующая имя этого первого идентификатора" << std::endl;
		break;
	case ReturnCode::varUsesIdName:
		std::cout << "Найдена переменная использующая имя этого первого идентификатора" << std::endl;
		break;
	case ReturnCode::valueSecondIdNotFound:
		std::cout << "Не найдено значение второго идентификатора" << std::endl;
		break;
	case ReturnCode::valueThirdIdNotFound:
		std::cout << "Не найдено значение третьего идентификатора" << std::endl;
		break;
	}
}

void CommandSetVar(CCalculator & calc, const string & mainRequest, size_t posStart)
{
	string identificator1;
	size_t posEnd = posStart + LEN_VAR_COMMAND;
	identificator1.append(mainRequest.begin() + posEnd, mainRequest.end());
	ReturnCode wasError = calc.SetVar(identificator1);
	PrintAllError(wasError);
}

void CommandSetLet(CCalculator & calc, const string & mainRequest, size_t posStart)
{
	string identificator1;
	size_t posEnd = posStart + LEN_LET_COMMAND;
	posStart = mainRequest.find("=", posEnd);
	identificator1.append(mainRequest, posEnd, posStart - posEnd);

	string identificator2;

	posEnd = posStart + 1;
	identificator2.append(mainRequest.begin() + posEnd, mainRequest.end());
	ReturnCode wasError = calc.SetLetVar(identificator1, identificator2);
	PrintAllError(wasError);
}

void CommandSetFn(CCalculator & calc, const string & mainRequest, size_t posStart)
{
	string identificator1;
	size_t posEnd = posStart + LEN_FN_COMMAND;
	ReturnCode wasError;
	OperandType operand = OperandType::Add;
	string identificator2;

	posStart = mainRequest.find("=", posEnd);
	identificator1.append(mainRequest, posEnd, posStart - posEnd);
	posEnd = posStart + 1;
	bool operandNotFound = false;
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
		operandNotFound = true;
		identificator2.append(mainRequest.begin() + posEnd, mainRequest.end());
		wasError = calc.SetFnValue(identificator1, identificator2);
		PrintAllError(wasError);
	}
	if (!operandNotFound)
	{
		identificator2.append(mainRequest, posEnd, posStart - posEnd);
		string identificator3;
		posEnd = posStart + 1;
		identificator3.append(mainRequest.begin() + posEnd, mainRequest.end());
		wasError = calc.SetFnOperand(identificator1, identificator2, operand, identificator3);
		PrintAllError(wasError);
	}
}

void CommandPrint(CCalculator & calc, const string & mainRequest, size_t posStart)
{
	string identificator1;
	size_t posEnd = posStart + LEN_PRINT_COMMAND;
	identificator1.append(mainRequest.begin() + posEnd, mainRequest.end());
	GetValInfo answer = calc.GetVar(identificator1);
	bool m_found = true;
	if (answer.valueInfo == FoundValueInfo::noValue)
	{
		answer = calc.GetFn(identificator1);
		if (answer.valueInfo == FoundValueInfo::noValue)
		{
			m_found = false;
			std::cout << "такого идентификатора нет" << std::endl;
		}
	}

	if (m_found)
	{
		if (answer.value != answer.value)
		{
			std::cout << "nan" << std::endl;
		}
		else
		{
			answer.value = round(answer.value * 100) / 100;
			std::cout << answer.value << std::endl;
		}
	}
}

void CommandPrintvars(CCalculator & calc)
{
	std::map<std::string, double> mapVars;
	mapVars = calc.GetMapVars();
	for (auto i : mapVars)
	{
		std::cout << i.first << ":";
		if (i.second != i.second)
		{
			std::cout << "nan" << std::endl;
		}
		else
		{
			i.second = round(i.second * 100) / 100;
			std::cout << i.second << std::endl;
		}
	}
}

void CommandPrintfns(CCalculator & calc)
{
	double value;
	std::map<std::string, GetFnInfo> mapFn;
	mapFn = calc.GetMapFn();
	for (auto i : mapFn)
	{
		value = calc.GetFn(i.first).value;
		std::cout << i.first << ":";
		if (value != value)
		{
			std::cout << "nan" << std::endl;
		}																						
		else
		{
			value = round(value * 100) / 100;
			std::cout << value << std::endl;
		}

	}
}

void PrintHelp()
{
	std::cout << "var <id> : Вводит переменную id с значением nan (Exampe: var x)" << std::endl;
	std::cout << "let <id1>=<id2> или let <id1>=<num> : Вводит переменную id1 с значением id2 (Exampe: let x=12,9)" << std::endl;
	std::cout << "fn <id1>=<id2><operand><id3> или fn <id1>=<id2> : Вводит функцию id1 с значением id2 (Exampe: fn f0=x+y)" << std::endl;
	std::cout << "print <id> : Выводит значение id (Example: print x)" << std::endl;
	std::cout << "printvars : Выводит все имеющиеся переменные на экран" << std::endl;
	std::cout << "printfns : Выводит все имеющиеся функции на экран" << std::endl;
}

void HandlerCommands(CCalculator & calc, const string & mainRequest)
{
	string identificator1;
	size_t posStart;
	if ((posStart = mainRequest.find("var ")) < mainRequest.length())
	{
		CommandSetVar(calc, mainRequest, posStart);
	}
	else if ((posStart = mainRequest.find("let ")) < mainRequest.length())
	{
		CommandSetLet(calc, mainRequest, posStart);
	}
	else if ((posStart = mainRequest.find("fn ")) < mainRequest.length())
	{
		CommandSetFn(calc, mainRequest, posStart);
	}
	else if ((posStart = mainRequest.find("print ")) < mainRequest.length())
	{
		CommandPrint(calc, mainRequest, posStart);
	}
	else if (mainRequest == "printvars")
	{
		CommandPrintvars(calc);
	}
	else if (mainRequest == "printfns")
	{
		CommandPrintfns(calc);
	}
	else
	{
		PrintHelp();
	}
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
