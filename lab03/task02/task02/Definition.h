#pragma once

enum class GetError
{
	noValue,
	valueIsFound
};

enum class OperandType
{
	Add,	// сложение
	Sub,	// вычитание
	Div,	// деление
	Mul		// умножение
};

struct GetValInfo
{
	GetError wasError;
	double value;
};
 
struct GetFnInfo
{
	GetError wasError;
	std::string firstVal;
	OperandType operand;
	std::string secondVal;
};


static const std::map<std::string, OperandType> OPERAND_MAP
{
	{ "+", OperandType::Add },
	{ "-", OperandType::Sub },
	{ "/", OperandType::Div },
	{ "*", OperandType::Mul }
};