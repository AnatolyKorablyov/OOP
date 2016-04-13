#include "stdafx.h"
#include "Calculator.h"


GetValInfo CCalculator::GetVar(const std::string & varName)	const
{
	GetValInfo info;
	if (m_repository.CheckVar(varName))
	{
		info.valueInfo = FoundValueInfo::valueIsFound;
		info.value = m_repository.m_vars.find(varName)->second;
	}
	else
	{
		info.valueInfo = FoundValueInfo::noValue;
	}
	return info;
}

ReturnCode CCalculator::SetVar(const std::string & varName)
{
	ReturnCode wasError = ReturnCode::AllOk;
	if (!m_repository.CheckIdName(varName))
	{
		wasError = ReturnCode::idNameNotCorrect;
	}
	else if (m_repository.CheckFn(varName))
	{
		wasError = ReturnCode::FnUsesIdName;
	}
	else if (m_repository.CheckVar(varName))
	{
		wasError = ReturnCode::varUsesIdName;
	}
	else 
	{
		m_repository.m_vars.emplace(varName, NAN);
	}

	return wasError;
}

bool CCalculator::SetLetDouble(const std::string & varName, const double & value)
{
	if (!m_repository.CheckFn(varName))
	{
		m_repository.m_vars[varName] = value;
		return true;
	}
	return false;
}

ReturnCode CCalculator::SetLetVar(const std::string & varName, const std::string & valueStr)
{
	ReturnCode wasError = ReturnCode::AllOk;
	GetValInfo valueInfo = GetVar(valueStr);
	if (!m_repository.CheckIdName(varName))
	{
		wasError = ReturnCode::idNameNotCorrect;
	}
	else if (valueInfo.valueInfo == FoundValueInfo::noValue)
	{
		double value = atof(valueStr.c_str());
		valueInfo = GetFn(valueStr);
		if (valueInfo.valueInfo == FoundValueInfo::valueIsFound)
		{
			m_repository.m_vars[varName] = valueInfo.value;
		}
		else if (valueStr != "0" && value == 0)
		{
			wasError = ReturnCode::numberNotCorrect;
		}											
		else if (!SetLetDouble(varName, value))
		{
			wasError = ReturnCode::FnUsesIdName;
		}
	}
	else if (m_repository.CheckFn(varName))
	{
		wasError = ReturnCode::FnUsesIdName;
	}
	else
	{
		m_repository.m_vars[varName] = valueInfo.value;
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

GetValInfo CCalculator::GetFnValue(const std::string & fnName) const
{
	GetValInfo infoResult;
	GetFnInfo infoFn;
	if (m_repository.CheckLocalFn(fnName))
	{
		infoResult.valueInfo = FoundValueInfo::valueIsFound;
		infoResult.value = m_repository.localMapFn[fnName];
		return infoResult;
	}
	auto it = m_repository.m_functions.find(fnName);
	if (it != m_repository.m_functions.end())
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
			m_repository.localMapFn[fnName] = infoResult.value;
		}
	}
	else
	{
		infoResult.valueInfo = FoundValueInfo::noValue;
	}
	return infoResult;
}

GetValInfo CCalculator::GetFn(const std::string & fnName) const
{
	GetValInfo infoResult;
	infoResult = GetFnValue(fnName);
	m_repository.localMapFn.clear();
	/*infoResult.value = round(infoResult.value * 100) / 100;
	*/
	return infoResult;
}

ReturnCode CCalculator::SetFnValue(const std::string & fnName, const std::string & value)
{
	GetFnInfo info;
	ReturnCode wasError = ReturnCode::AllOk;
	if (!m_repository.CheckIdName(fnName))
	{
		wasError = ReturnCode::idNameNotCorrect;
	}
	else if (m_repository.CheckVar(fnName))
	{
		wasError = ReturnCode::varUsesIdName;
	}
	else if (m_repository.CheckFn(fnName))
	{
		wasError = ReturnCode::FnUsesIdName;
	}
	else if (!m_repository.CheckFn(value) && !m_repository.CheckVar(value))
	{
		wasError = ReturnCode::valueSecondIdNotFound;
	}
	else
	{
		info.firstVal = value;
		info.twoOperators = false;
		m_repository.m_functions.emplace(fnName, info);
	}
	return wasError;
}

ReturnCode CCalculator::SetFnOperand(const std::string & fnName, const std::string & firstValue, OperandType operand, const std::string & secondValue)
{
	ReturnCode wasError = ReturnCode::AllOk;
	if (!m_repository.CheckIdName(fnName))
	{
		wasError = ReturnCode::idNameNotCorrect;
	}
	else if (m_repository.CheckVar(fnName))
	{
		wasError = ReturnCode::varUsesIdName;
	}
	else if (m_repository.CheckFn(fnName))
	{
		wasError = ReturnCode::FnUsesIdName;
	}
	else if (!m_repository.CheckFn(firstValue) && !m_repository.CheckVar(firstValue))
	{
		wasError = ReturnCode::valueSecondIdNotFound;
	}
	else if (!m_repository.CheckFn(secondValue) && !m_repository.CheckVar(secondValue))
	{
		wasError = ReturnCode::valueThirdIdNotFound;
	}
	else
	{
		GetFnInfo info;
		info.firstVal = firstValue;
		info.operand = operand;
		info.secondVal = secondValue;
		info.twoOperators = true;
		m_repository.m_functions.insert(std::pair<std::string, GetFnInfo>(fnName, info));
	}
	return wasError;
}

std::map<std::string, double> CCalculator::GetMapVars() const 
{
	return m_repository.m_vars;
}

std::map<std::string, GetFnInfo> CCalculator::GetMapFn() const
{
	return m_repository.m_functions;
}
