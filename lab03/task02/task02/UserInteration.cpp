#include "stdafx.h"
#include "UserInteration.h"
#include "Definition.h"


void PrintAllError(const WasError & wasError) 
{
	switch (wasError)
	{
	case WasError::AllOk:
		break;
	case WasError::idNameNotCorrect:
		std::cout << "��� ���������� ������� �����������" << std::endl;
		break;
	case WasError::numberNotCorrect:
		std::cout << "����� ������� ����������� (������: 12,34; -34,4)" << std::endl;
		break;
	case WasError::FnUsesIdName:
		std::cout << "������� ������� ������������ ��� ����� ������� ��������������" << std::endl;
		break;
	case WasError::varUsesIdName:
		std::cout << "������� ���������� ������������ ��� ����� ������� ��������������" << std::endl;
		break;
	case WasError::valueSecondIdNotFound:
		std::cout << "�� ������� �������� ������� ��������������" << std::endl;
		break;
	case WasError::valueThirdIdNotFound:
		std::cout << "�� ������� �������� �������� ��������������" << std::endl;
		break;
	}
}
void CommandSetVar(CCalculator & calc, const string & mainRequest, size_t posStart)
{
	string identificator1;
	size_t posEnd = posStart + LEN_VAR_COMMAND;
	identificator1.append(mainRequest.begin() + posEnd, mainRequest.end());
	WasError wasError = calc.SetVar(identificator1);
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
	WasError wasError = calc.SetLetVar(identificator1, identificator2);
	PrintAllError(wasError);
}

void CommandSetFn(CCalculator & calc, const string & mainRequest, size_t posStart)
{
	string identificator1;
	size_t posEnd = posStart + LEN_FN_COMMAND;
	WasError wasError;
	OperandType operand;
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
	if (answer.wasError == GetError::noValue)
	{
		answer = calc.GetFn(identificator1);
		if (answer.wasError == GetError::noValue)
		{
			m_found = false;
			std::cout << "������ �������������� ���" << std::endl;
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
			std::cout << value << std::endl;
		}

	}
}

void HandlerCommands(CCalculator & calc, const string & mainRequest)
{
	string identificator1;
	GetValInfo answer;
	size_t posStart;
	size_t posEnd;
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