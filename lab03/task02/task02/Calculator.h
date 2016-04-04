#pragma once
#include "stdafx.h"
#include "Definition.h"

class CCalculator
{
public:
	CCalculator();

	GetValInfo GetVar(const std::string & varName) const;
	GetValInfo GetFn(const std::string & fnName) const;
	bool SetVar(const std::string & varName);
	bool SetLetDouble(const std::string & varName, const double & value);
	bool SetLetVar(const std::string & varName, const std::string & valueStr);
	bool SetFnValue(const std::string & fnName, const std::string & value);
	bool SetFnOperand(const std::string & fnName, const std::string & firstValue, OperandType operand, const std::string & secondValue);
private:
	double CalcFunctions(const double & firstValue, const OperandType & operand, const double & secondValue) const;
	bool CheckVar(const std::string & varName) const;
	bool CheckFn(const std::string & fnName) const;
	bool CheckVarName(const std::string & identificator);
	std::map<std::string, double> m_vars;
	std::map<std::string, GetFnInfo> m_functions;
};

