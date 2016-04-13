#include "stdafx.h"
#include "Calculator.h"

CCalculator::CCalculator()
{
}

bool CCalculator::CheckIdName(const std::string & identificator)
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

bool CCalculator::CheckVar(const std::string & varName) const
{
	auto it = m_vars.find(varName);
	if (it != m_vars.end())
	{
		return true;
	}
	return false;
}

bool CCalculator::CheckFn(const std::string & varName) const 
{
	auto it = m_functions.find(varName);
	if (it != m_functions.end())
	{
		return true;
	}
	return false;
}

bool CCalculator::CheckLocalFn(const std::string & fnName) const
{
	auto it = localMapFn.find(fnName);
	if (it != localMapFn.end())
	{
		return true;
	}
	return false;
}

GetValInfo CCalculator::GetVar(const std::string & varName)	const
{
	GetValInfo info;
	if (CheckVar(varName))
	{
		info.valueInfo = FoundValueInfo::valueIsFound;
		info.value = m_vars.find(varName)->second;
	}
	else
	{
		info.valueInfo = FoundValueInfo::noValue;
	}
	return info;
}

WasError CCalculator::SetVar(const std::string & varName)
{
	WasError wasError = WasError::AllOk;
	if (!CheckIdName(varName))
	{
		wasError = WasError::idNameNotCorrect;
	}
	else if (CheckFn(varName))
	{
		wasError = WasError::FnUsesIdName;
	}
	else if (CheckVar(varName))
	{
		wasError = WasError::varUsesIdName;
	}
	else 
	{
		m_vars.emplace(varName, NAN);
	}

	return wasError;
}

bool CCalculator::SetLetDouble(const std::string & varName, const double & value)
{
	if (!CheckFn(varName))
	{
		m_vars[varName] = value;
		return true;
	}
	return false;
}

WasError CCalculator::SetLetVar(const std::string & varName, const std::string & valueStr)
{
	WasError wasError = WasError::AllOk;
	GetValInfo valueInfo = GetVar(valueStr);
	if (!CheckIdName(varName))
	{
		wasError = WasError::idNameNotCorrect;
	}
	else if (valueInfo.valueInfo == FoundValueInfo::noValue)
	{
		double value = atof(valueStr.c_str());
		GetValInfo valueInfo = GetFn(valueStr);
		if (valueInfo.valueInfo == FoundValueInfo::valueIsFound)
		{
			m_vars[varName] = valueInfo.value;
		}
		else if (valueStr != "0" && value == 0)
		{
			wasError = WasError::numberNotCorrect;
		}											
		else if (!SetLetDouble(varName, value))
		{
			wasError = WasError::FnUsesIdName;
		}
	}
	else if (CheckFn(varName))
	{
		wasError = WasError::FnUsesIdName;
	}
	else
	{
		m_vars[varName] = valueInfo.value;
	}
	return wasError;
}

double CCalculator::CalcFunctions(const double & firstValue, const OperandType & operand, const double & secondValue) const
{
	if (operand == OperandType::Add)
	{
		return (firstValue + secondValue);
	}
	else if (operand == OperandType::Sub)
	{
		return (firstValue - secondValue);
	}
	else if (operand == OperandType::Div)
	{
		return (firstValue / secondValue);
	}
	else if (operand == OperandType::Mul)
	{
		return (firstValue * secondValue);
	}
	return 0;
}

GetValInfo CCalculator::GetFnValue(const std::string & fnName)
{
	GetValInfo infoResult;
	GetFnInfo infoFn;
	if (CheckLocalFn(fnName))
	{
		infoResult.valueInfo = FoundValueInfo::valueIsFound;
		infoResult.value = localMapFn[fnName];
		return infoResult;
	}
	auto it = m_functions.find(fnName);
	if (it != m_functions.end())
	{
		infoResult.valueInfo = FoundValueInfo::valueIsFound;
		infoFn = it->second;
		if (infoFn.twoOperators) {
			auto firstVal = GetVar(infoFn.firstVal);
			auto operand = infoFn.operand;
			auto secondVal = GetVar(infoFn.secondVal);
			if (firstVal.valueInfo == FoundValueInfo::noValue)
			{
				firstVal = GetFnValue(infoFn.firstVal);
			}
			if (secondVal.valueInfo == FoundValueInfo::noValue)
			{
				secondVal = GetFnValue(infoFn.secondVal);
			}

			infoResult.value = CalcFunctions(firstVal.value, operand, secondVal.value);
		}
		else
		{
			auto mainValue = GetVar(infoFn.firstVal);
			if (mainValue.valueInfo == FoundValueInfo::noValue)
			{
				mainValue = GetFnValue(infoFn.firstVal);
			}
			infoResult.value = mainValue.value;
		}
		if (infoResult.value == infoResult.value)
		{
			localMapFn[fnName] = infoResult.value;
		}
	}
	else
	{
		infoResult.valueInfo = FoundValueInfo::noValue;
	}
	return infoResult;
}

GetValInfo CCalculator::GetFn(const std::string & fnName)
{
	GetValInfo infoResult;
	infoResult = GetFnValue(fnName);
	localMapFn.clear();
	/*infoResult.value = round(infoResult.value * 100) / 100;
	*/
	return infoResult;
}

WasError CCalculator::SetFnValue(const std::string & fnName, const std::string & value)
{
	GetFnInfo info;
	WasError wasError = WasError::AllOk;
	if (!CheckIdName(fnName))
	{
		wasError = WasError::idNameNotCorrect;
	}
	else if (CheckVar(fnName))
	{
		wasError = WasError::varUsesIdName;
	}
	else if (CheckFn(fnName))
	{
		wasError = WasError::FnUsesIdName;
	}
	else if (!CheckFn(value) && !CheckVar(value))
	{
		wasError = WasError::valueSecondIdNotFound;
	}
	else
	{
		info.firstVal = value;
		info.twoOperators = false;
		m_functions.emplace(fnName, info);
	}
	return wasError;
}

WasError CCalculator::SetFnOperand(const std::string & fnName, const std::string & firstValue, OperandType operand, const std::string & secondValue)
{
	GetFnInfo info;
	WasError wasError = WasError::AllOk;
	if (!CheckIdName(fnName))
	{
		wasError = WasError::idNameNotCorrect;
	}
	else if (CheckVar(fnName))
	{
		wasError = WasError::varUsesIdName;
	}
	else if (CheckFn(fnName))
	{
		wasError = WasError::FnUsesIdName;
	}
	else if (!CheckFn(firstValue) && !CheckVar(firstValue))
	{
		wasError = WasError::valueSecondIdNotFound;
	}
	else if (!CheckFn(secondValue) && !CheckVar(secondValue))
	{
		wasError = WasError::valueThirdIdNotFound;
	}
	else
	{
		info.firstVal = firstValue;
		info.operand = operand;
		info.secondVal = secondValue;
		info.twoOperators = true;
		m_functions.insert(std::pair<std::string, GetFnInfo>(fnName, info));
	}
	return wasError;
}

std::map<std::string, double> CCalculator::GetMapVars() const 
{
	return m_vars;
}

std::map<std::string, GetFnInfo> CCalculator::GetMapFn() const
{
	return m_functions;
}
