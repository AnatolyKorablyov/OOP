#pragma once
#include "stdafx.h"
#include "Definition.h"

class CCalculator
{
public:
	CCalculator();

	GetValInfo GetVar(const std::string & varName) const;
	GetValInfo GetFn(const std::string & fnName) const;
	WasError SetVar(const std::string & varName);
	WasError SetLetVar(const std::string & varName, const std::string & valueStr);
	WasError SetFnValue(const std::string & fnName, const std::string & value);
	WasError SetFnOperand(const std::string & fnName, const std::string & firstValue, OperandType operand, const std::string & secondValue);
	std::map<std::string, double> GetMapVars();
	std::map<std::string, GetFnInfo> GetMapFn();
private:
	bool SetLetDouble(const std::string & varName, const double & value);
	double CalcFunctions(const double & firstValue, const OperandType & operand, const double & secondValue) const;
	bool CheckVar(const std::string & varName) const;
	bool CheckFn(const std::string & fnName) const;
	bool CheckIdName(const std::string & identificator);
	std::map<std::string, double> m_vars;
	std::map<std::string, GetFnInfo> m_functions;
};

