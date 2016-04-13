#pragma once
#include "stdafx.h"
#include "Definition.h"

class CVariables
{
public:
	bool CheckVar(const std::string & varName) const;
	bool CheckFn(const std::string & fnName) const;
	bool CheckIdName(const std::string & identificator);
	bool CheckLocalFn(const std::string & fnName) const;

	std::map<std::string, double> m_vars;
	std::map<std::string, GetFnInfo> m_functions;
	mutable std::map<std::string, double> localMapFn;
};

