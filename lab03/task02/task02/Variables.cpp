#include "stdafx.h"
#include "Variables.h"


bool CVariables::CheckIdName(const std::string & identificator)
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
