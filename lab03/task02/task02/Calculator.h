#pragma once
#include "stdafx.h"
#include "Definition.h"
#include "Variables.h"

class CCalculator
{
public:
	GetValInfo GetVar(const std::string & varName) const;
	GetValInfo GetFn(const std::string & fnName) const;
	ReturnCode SetVar(const std::string & varName);
	ReturnCode SetLetVar(const std::string & varName, const std::string & valueStr);
	ReturnCode SetFnValue(const std::string & fnName, const std::string & value);
	ReturnCode SetFnOperand(const std::string & fnName, const std::string & firstValue, OperandType operand, const std::string & secondValue);
	std::map<std::string, double> GetMapVars() const;
	std::map<std::string, GetFnInfo> GetMapFn() const;
private:
	mutable CVariables m_repository;
	bool SetLetDouble(const std::string & varName, const double & value);
	double CalcFunctions(const double & firstValue, const OperandType & operand, const double & secondValue) const;
	GetValInfo GetFnValue(const std::string & fnName) const;
};

