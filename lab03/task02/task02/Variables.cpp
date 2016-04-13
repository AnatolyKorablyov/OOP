#include "stdafx.h"
#include "Variables.h"


bool CVariables::CheckIdName(const std::string & identificator) const
{
	if (identificator.length() > 0)
	{
		size_t it = 0;
		if ((identificator[it] >= '0' && identificator[it] <= '9'))
		{
			return false;
		}
		while (it < identificator.length())
		{
			if (!((identificator[it] >= 'a' && identificator[it] <= 'z') ||
				(identificator[it] >= 'A' && identificator[it] <= 'Z') ||
				(identificator[it] >= '0' && identificator[it] <= '9') ||
				(identificator[it] >= '_')))
			{
				return false;
			}
			++it;
		}
		return true;
	}
	return false;
}

bool CVariables::CheckVar(const std::string & varName) const
{
	auto it = m_vars.find(varName);

	return (it != m_vars.end());
}

bool CVariables::CheckFn(const std::string & varName) const
{
	auto it = m_functions.find(varName);

	return (it != m_functions.end());
}

bool CVariables::CheckLocalFn(const std::string & fnName) const
{
	auto it = localMapFn.find(fnName);

	return (it != localMapFn.end());
}

void CVariables::SetVarValue(const std::string & varName, const double & number)
{
	m_vars[varName] = number;
}

void CVariables::SetFnValue(const std::string & fnName, const GetFnInfo & value)
{
	m_functions[fnName] = value;
}

void CVariables::SetlocalFnValue(const std::string & fnName, const double & value)
{
	localMapFn[fnName] = value;
}

double CVariables::getVarValue(const std::string & varName)	const
{
	return m_vars.find(varName)->second;
}

GetFnInfo CVariables::getFnValue(const std::string & fnName) const
{
	return m_functions.find(fnName)->second;
}

double CVariables::getlocalFnValue(const std::string & fnName) const
{
	return localMapFn.find(fnName)->second;
}
void CVariables::ClearLocalFn()
{
	localMapFn.clear();
}

std::map<std::string, double> CVariables::GetMapVars() const
{
	return m_vars;
}

std::map<std::string, GetFnInfo> CVariables::GetMapFn() const
{
	return m_functions;
}
