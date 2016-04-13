#pragma once
#include "stdafx.h"
#include "Definition.h"

class CVariables
{
public:
	
	bool CheckVar(const std::string & varName) const;
	bool CheckFn(const std::string & fnName) const;
	bool CheckIdName(const std::string & identificator) const;
	bool CheckLocalFn(const std::string & fnName) const;

	double getVarValue(const std::string & varName) const;
	GetFnInfo getFnValue(const std::string & fnName) const;
	double getlocalFnValue(const std::string & fnName) const;
	void ClearLocalFn();
	std::map<std::string, double> GetMapVars() const;
	std::map<std::string, GetFnInfo> GetMapFn() const;
	
	void SetVarValue(const std::string & varName, const double & number);
	void SetFnValue(const std::string & fnName, const GetFnInfo & value);
	void SetlocalFnValue(const std::string & fnName, const double & value);

private:
	std::map<std::string, double> m_vars;
	std::map<std::string, GetFnInfo> m_functions;
	mutable std::map<std::string, double> localMapFn;
};

